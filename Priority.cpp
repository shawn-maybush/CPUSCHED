#include "Priority.h"
#include <stdexcept>

void Priority::addProcess(const Process &p)
{
    readyQueue.push(p); // Simply add the process to the queue
}

Process Priority::getNextProcess()
{
    if (readyQueue.empty())
    {
        throw std::runtime_error("Error: Attempting to get a process from an empty Priority queue");
    }

    Process nextProcess = readyQueue.top();
    readyQueue.pop(); // Remove the process from the front of the queue
    return nextProcess;
}

bool Priority::isEmpty() const
{
    return readyQueue.empty();
}