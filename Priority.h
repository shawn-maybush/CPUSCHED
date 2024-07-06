/**
 * @file Priority.h
 * @brief Defines the Priority readyqueue class.
 * @author Shawn Maybush
 * @date 06-28-2024
 */

#ifndef PRIORITY_H
#define PRIORITY_H

#include "ReadyQueue.h"
#include <queue>
#include <functional>

/**
 * @brief Priority (Preemptive) readyqueue class.
 *
 * This class implements the Priority CPU scheduling algorithm with preemption.
 * Processes are scheduled based on their priority, with higher-priority processes
 * being executed first. If a higher-priority process arrives while a lower-priority
 * process is running, the lower-priority process is preempted (interrupted) and
 * the higher-priority process takes over the CPU.
 */
class Priority : public ReadyQueue
{
public:
    /**
     * @brief Adds a process to the priority queue based on its priority.
     * @param p The process to add.
     */
    void addProcess(const Process &p) override;

    /**
     * @brief Retrieves the next process to execute from the priority queue.
     *        This is the process with the highest priority (lowest numerical value).
     * @return The highest-priority process.
     * @throws std::runtime_error if the queue is empty.
     */
    Process getNextProcess() override;

private:
    /**
     * @brief Priority queue that stores processes based on their priority.
     *        Processes with lower priority values (higher priority) are placed at the top.
     */
    std::priority_queue<Process, std::vector<Process>, std::function<bool(const Process &, const Process &)>> readyQueue{
        /**
         * @brief Custom comparator lambda function for the priority queue.
         *
         * This lambda compares two Process objects based on their priority.
         * It returns true if the first process (p1) has a lower priority value (higher priority)
         * than the second process (p2), thus ensuring that higher-priority processes are
         * placed at the top of the queue.
         */
        [](const Process &p1, const Process &p2)
        {
            if (p1.priority == p2.priority)
            {
                return p1.arrival_time < p2.arrival_time; // Prioritize earlier arrival if priorities are equal
            }
            return p1.priority < p2.priority; // Lower priority value means higher priority
        }};
};
#endif // PRIORITY_H
