#ifndef READYQUEUE_H
#define READYQUEUE_H
#include "Process.h"
#include "Event.h"

class ReadyQueue {
public:
    virtual void addProcess(const Process& p) = 0;
    virtual Process getNextProcess() = 0;
    virtual bool isEmpty() const = 0;
};
#endif 
