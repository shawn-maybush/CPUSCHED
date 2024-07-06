#include "CPU.h"

CPU::CPU() : runningProcess(nullptr) {}

const Process* CPU::getRunningProcess() const {
    return runningProcess;
}

bool CPU::isIdle() const {
    return runningProcess == nullptr;
}

int CPU::loadProcess(const Process& p, int currentTime) {
    runningProcess = new Process(p);
    runningProcess->start_time = currentTime;

    // Calculate and return the completion time
    return currentTime + p.burst_time - p.completed_burst_time; 
}

Process CPU::unloadProcess(int currentTime) {
    Process completedProcess; // Create a copy of the process to be returned
    if (runningProcess) {
        // Update completed_burst_time and wait_time (same as before)
        runningProcess->completed_burst_time += currentTime - runningProcess->start_time;
        runningProcess->wait_time = currentTime - runningProcess->arrival_time - runningProcess->completed_burst_time; 

        // copy running process into completedProcess to return it
        completedProcess = *runningProcess;

        delete runningProcess;
        runningProcess = nullptr;
    }
    return completedProcess; 
}
