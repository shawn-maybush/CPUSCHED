#include "Priority.h"
#include <stdexcept>

void Priority::addProcess(const Process &p)
{
    readyQueue.push(p); 
}

Process Priority::getNextProcess()
{
    if (readyQueue.empty())
    {
        throw std::runtime_error("Error: Attempting to get a process from an empty Priority queue");
    }

    Process nextProcess = readyQueue.top();
    readyQueue.pop(); 
    return nextProcess;
}

bool Priority::isEmpty() const
{
    return readyQueue.empty();
}