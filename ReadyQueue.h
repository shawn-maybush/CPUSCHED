/**
 * @file ReadyQueue.h
 * @brief Defines the abstract base class `ReadyQueue` for process scheduling simulations.
 * @author Shawn Maybush
 * @date 2024-07-06 
 */

#ifndef READYQUEUE_H
#define READYQUEUE_H

#include "Process.h"
#include "Event.h"

/**
 * @class ReadyQueue
 * @brief Abstract base class for representing a ready queue in a process scheduler.
 *
 * This class provides a common interface for different types of ready queues (e.g., FIFO, SJF, Priority).
 * Specific ready queue implementations (derived classes) must implement the pure virtual functions declared here.
 */
class ReadyQueue {
public:
    /**
     * @brief  Adds a process to the ready queue.
     *
     * The specific implementation of how a process is added depends on the type of ready queue (e.g., FIFO, SJF, Priority).
     *
     * @param p The `Process` to be added to the queue.
     */
    virtual void addProcess(const Process& p) = 0; 

    /**
     * @brief Gets the next process to be scheduled from the ready queue.
     *
     * The specific implementation of how the next process is selected depends on the type of ready queue.
     *
     * @return The next `Process` to be scheduled.
     * @throws std::runtime_error if the queue is empty.
     */
    virtual Process getNextProcess() = 0;  

    /**
     * @brief Checks if the ready queue is empty.
     * @return `true` if the queue is empty, `false` otherwise.
     */
    virtual bool isEmpty() const = 0;  
};

#endif // READYQUEUE_H
