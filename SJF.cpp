#include "SJF.h"
#include <stdexcept>

void SJF::addProcess(const Process &p)
{
    readyQueue.push(p); // Simply add the process to the queue
}

Process SJF::getNextProcess()
{
    if (readyQueue.empty())
    {
        throw std::runtime_error("Error: Attempting to get a process from an empty SJF queue");
    }

    Process nextProcess = readyQueue.top();
    readyQueue.pop(); // Remove the process from the front of the queue
    return nextProcess;
}

bool SJF::isEmpty() const
{
    return readyQueue.empty();
}