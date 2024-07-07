/**
 * @file Priority.h
 * @brief Defines the Priority ready queue class for a CPU scheduling simulation.
 * @author Shawn Maybush
 * @date 06-28-2024
 */

#ifndef PRIORITY_H
#define PRIORITY_H

#include "ReadyQueue.h"
#include <queue>
#include <functional>

/**
 * @brief Ready queue implementation for the Priority scheduling algorithm with preemption.
 *
 * This class inherits from the `ReadyQueue` interface and implements a priority-based
 * scheduling algorithm. Processes are scheduled for execution based on their priority,
 * with higher priority processes (lower numerical values) given precedence.
 *
 * The algorithm is preemptive, meaning that a running process can be interrupted
 * (preempted) if a higher-priority process arrives. In case of a tie in priorities, the
 * process with the earlier arrival time is prioritized.
 */
class Priority : public ReadyQueue
{
public:
    /**
     * @brief Adds a process to the priority queue based on its priority.
     *
     * The process is inserted into the priority queue, with higher-priority processes
     * (lower numerical values) placed at the front of the queue.
     *
     * @param p The Process object to be added to the queue.
     */
    void addProcess(const Process &p) override;

    /**
     * @brief Retrieves and removes the next process to execute from the priority queue.
     *
     * The process with the highest priority (lowest numerical value) is removed from
     * the queue and returned.
     *
     * @return The Process object with the highest priority.
     * @throws std::runtime_error if the queue is empty.
     */
    Process getNextProcess() override;

    /**
     * @brief Checks if the priority ready queue is empty.
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const override;

private:
    /**
     * @brief The priority queue used to store and prioritize processes.
     *
     * Processes are stored in the priority queue with the following criteria:
     *  - Highest priority: Lowest numerical priority value.
     *  - Tiebreaker: Earliest arrival time.
     *
     * The custom comparator lambda function ensures this ordering.
     */
    std::priority_queue<Process, std::vector<Process>, std::function<bool(const Process &, const Process &)>> readyQueue{
        /**
         * @brief Custom comparator for the priority queue.
         *
         * Compares two Process objects and returns true if the first process (`p1`) has a
         * higher priority than the second process (`p2`). Higher priority is determined by a
         * lower numerical priority value, with earlier arrival time used as a tiebreaker if
         * priority values are equal.
         *
         * @param p1 The first Process object to compare.
         * @param p2 The second Process object to compare.
         * @return True if `p1` has a higher priority than `p2`, false otherwise.
         */
        [](const Process &p1, const Process &p2)
        {
            if (p1.priority == p2.priority)
            {
                return p1.arrival_time > p2.arrival_time; // Prioritize earlier arrival if priorities are equal
            }
            return p1.priority > p2.priority; // Prioritize lower priority value
        }};
};

#endif // PRIORITY_H
