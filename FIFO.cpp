#include "FIFO.h"
#include <stdexcept>
#include "Event.h" 

void FIFO::addProcess(const Process& p) {
    readyQueue.push(p); 
}

Process FIFO::getNextProcess() {
    if (readyQueue.empty()) {
        throw std::runtime_error("Error: Attempting to get a process from an empty FIFO queue");
    }

    Process nextProcess = readyQueue.front(); 
    readyQueue.pop(); 
    return nextProcess;
}

bool FIFO::isEmpty() const{
    return readyQueue.empty();
}
