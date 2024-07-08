/**
 * @file FIFO.h
 * @brief Defines the FIFO (First-In, First-Out) ready queue class.
 * @author Shawn Maybush
 * @date 06-28-2024
 */

#ifndef FIFO_H
#define FIFO_H

#include "ReadyQueue.h"
#include <queue>

/**
 * @brief FIFO (First-In, First-Out) ready queue class.
 *
 * This class implements the FIFO CPU scheduling algorithm. Processes are
 * scheduled for execution in the order they arrive in the system.
 */
class FIFO : public ReadyQueue
{
public:
    /**
     * @brief Adds a process to the ready queue.
     * @param p The process to add.
     */
    void addProcess(const Process &p) override;

    /**
     * @brief Retrieves the next process to execute from the ready queue.
     * @return The next process to execute.
     * @throws std::runtime_error if the queue is empty.
     */
    Process getNextProcess() override;

    /**
     * @brief Checks if the FIFO ready queue is empty.
     *
     * This function checks whether there are any processes waiting in the ready queue
     * of the FIFO scheduler.
     *
     * @return True if the ready queue is empty, false otherwise.
     */
    bool isEmpty() const override;

private:
    /**
     * @brief The queue used to store processes in FIFO order.
     */
    std::queue<Process> readyQueue;
};

#endif // FIFO_H
