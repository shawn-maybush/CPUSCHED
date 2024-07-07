#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "ReadyQueue.h"
#include "FIFO.h"
#include "SJF.h"
#include "Priority.h"
#include "CPU.h"
#include "EventQueue.h"
#include "Event.h"
#include "Process.h"
#include <vector>
#include <string> 

class Scheduler {
public:
    // Constructor now takes a file name and scheduling algorithm type
    Scheduler(const std::string& fileName, const std::string& algorithmType);

    void runSimulation();

private:
    void loadProcessesFromFile(const std::string& fileName);
    void handleArrivalEvent(const Event& arrivalEvent, const int& currentTime);
    void handleCompletionEvent(const Event& completionEvent, const int& currentTime);
    void printStatistics() const;
    int currentTime;
    std::string algorithmType;
    std::vector<Process> completedProcesses; 
    CPU cpu;
    ReadyQueue* readyQueue;
    EventQueue eventQueue;
};

#endif // SCHEDULER_H
