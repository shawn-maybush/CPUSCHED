#include "Scheduler.h"
#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <algorithm_type>" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::string algorithmType = argv[2];

    Scheduler scheduler(fileName, algorithmType);
    scheduler.runSimulation();

    return 0;
}

Scheduler::Scheduler(const std::string &fileName, const std::string &algorithmType)
{
    this->algorithmType = algorithmType;
    loadProcessesFromFile(fileName);

    if (algorithmType == "FIFO")
    {
        readyQueue = new FIFO();
    }
    else if (algorithmType == "SJF")
    {
        readyQueue = new SJF();
    }
    else if (algorithmType == "Priority")
    {
        readyQueue = new Priority();
    }
    else
    {
        throw std::runtime_error("Invalid algorithm type");
    }
}

void Scheduler::loadProcessesFromFile(const std::string &fileName)
{
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        throw std::runtime_error("Error opening file: " + fileName);
    }

    std::string headerLine;
    std::getline(inputFile, headerLine);

    int arrivalTime, burstTime, priority;

    std::string line;
    int processCount = 0;

    while (std::getline(inputFile, line) && processCount < 500)
    {
        std::istringstream iss(line);

        // Split the line by tabs and read the values
        if (!(iss >> arrivalTime >> burstTime >> priority))
        {
            throw std::runtime_error("Invalid line format in file: " + line);
        }
        Process p{arrivalTime, burstTime, priority};

        eventQueue.push(Event(Event::ARRIVAL, arrivalTime, p));

        processCount++;

    }

    inputFile.close();
}

void Scheduler::runSimulation()
{
    while (!eventQueue.empty())
    {
        // Get the next event from the queue
        Event currentEvent = eventQueue.top();
        eventQueue.pop();

        // Update the current time
        currentTime = currentEvent.timestamp;

        // Handle the event based on its type
        switch (currentEvent.type)
        {
        case Event::ARRIVAL:
            handleArrivalEvent(currentEvent, currentTime);
            break;
        case Event::COMPLETION:
            handleCompletionEvent(currentEvent, currentTime);
            break;
        }
    }
    printStatistics();
}

void Scheduler::handleArrivalEvent(const Event &arrivalEvent, const int &currentTime)
{
    if (cpu.isIdle())
    {
        int completionTime = cpu.loadProcess(arrivalEvent.process, currentTime);
        eventQueue.push(Event(Event::COMPLETION, completionTime, arrivalEvent.process));
    }
    else
    {
        if (algorithmType == "Priority" && arrivalEvent.process.priority < cpu.getRunningProcess()->priority)
        {
            // Preemption logic:
            Process preemptedProcess = cpu.unloadProcess(currentTime);
            readyQueue->addProcess(preemptedProcess);
            EventKey preemptKey(preemptedProcess.completion_time, preemptedProcess.process_id);
            eventQueue.remove(preemptKey);
            int completionTime = cpu.loadProcess(arrivalEvent.process, currentTime);
            eventQueue.push(Event(Event::COMPLETION, completionTime, arrivalEvent.process));
        }
        else
        {

            readyQueue->addProcess(arrivalEvent.process);
        }
    }
}

void Scheduler::handleCompletionEvent(const Event &completionEvent, const int &currentTime)
{

    try
    {
        if (cpu.getRunningProcess()->process_id == completionEvent.process.process_id)
        {
            completedProcesses.push_back(cpu.unloadProcess(currentTime));
            if (!readyQueue->isEmpty())
            {
                Process nextProcess = readyQueue->getNextProcess();
                int nextCompletionTime = cpu.loadProcess(nextProcess, currentTime);
                eventQueue.push(Event(Event::COMPLETION, nextCompletionTime, nextProcess));
            }
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error in handleCompletionEvent: " << e.what() << std::endl;
    }
}

void Scheduler::printStatistics() const
{
    int numProcesses = completedProcesses.size();
    int totalElapsedTime = completedProcesses.back().completion_time; // Assuming last process has the latest completion time
    double throughput = static_cast<double>(numProcesses) / totalElapsedTime;
    double cpuUtilization = (static_cast<double>(cpu.getTotalBusyTime()) / totalElapsedTime) * 100.0;

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int totalResponseTime = 0;

    for (const Process &p : completedProcesses)
    {
        totalWaitingTime += p.wait_time;
        totalTurnaroundTime += p.completion_time - p.arrival_time;
        totalResponseTime += p.response_time;
    }

    double avgWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;
    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / numProcesses;
    double avgResponseTime = static_cast<double>(totalResponseTime) / numProcesses;

    std::cout << "\n----------------- Statistics -----------------\n";
    std::cout << "Number of processes: " << numProcesses << std::endl;
    std::cout << "Total elapsed time (CPU burst times): " << totalElapsedTime << std::endl;
    std::cout << "Throughput: (Number of processes executed in one unit of CPU burst time) " << throughput << std::endl;
    std::cout << "CPU utilization: " << cpuUtilization << "%" << std::endl;
    std::cout << "Average waiting time (CPU burst times): " << avgWaitingTime << std::endl;
    std::cout << "Average turnaround time (CPU burst times): " << avgTurnaroundTime << std::endl;
    std::cout << "AAverage response time (CPU burst times): " << avgResponseTime << std::endl;
    std::cout << "---------------------------------------------\n";
}
