#include "CPU.h"
#include <stdexcept>
#include <iostream>

CPU::CPU() : runningProcess(nullptr) {}

const Process *CPU::getRunningProcess() const
{
    if (runningProcess == nullptr)
    {
        throw std::runtime_error("Error: Attempting to get a process from an empty CPU!");
    }
    return runningProcess;
}

bool CPU::isIdle() const
{
    return runningProcess == nullptr;
}

int CPU::loadProcess(const Process &p, int currentTime)
{
    runningProcess = new Process(p);
    runningProcess->start_time = currentTime;
    if (!runningProcess->hasStarted) {
        runningProcess->hasStarted = true;
        runningProcess->response_time = currentTime - runningProcess->arrival_time;
    }
    runningProcess->wait_time = currentTime - runningProcess->arrival_time - runningProcess->completed_burst_time;

    runningProcess->completion_time = currentTime + p.burst_time - p.completed_burst_time;
    lastProcessStartTime = currentTime;

    return runningProcess->completion_time;
}

Process CPU::unloadProcess(int currentTime)
{
    Process completedProcess; // Create a copy of the process to be returned
    if (runningProcess)
    {
        // Update completed_burst_time and wait_time (same as before)
        runningProcess->completed_burst_time += currentTime - runningProcess->start_time;
        

        // copy running process into completedProcess to return it
        completedProcess = *runningProcess;

        delete runningProcess;
        runningProcess = nullptr;
        totalBusyTime += currentTime - lastProcessStartTime;
    }
    else
    {
        throw std::runtime_error("Error: Attempting to unload a process from an empty CPU!");
    }
    return completedProcess;
}

int CPU::getTotalBusyTime() const
{
    return totalBusyTime;
}
