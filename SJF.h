/**
 * @file SJF.h
 * @brief Defines the SJF (Shortest Job First) ready queue class for a CPU scheduling simulation.
 * @author Shawn Maybush
 * @date 06-28-2024
 */

#ifndef SJF_H
#define SJF_H

#include "ReadyQueue.h"
#include <queue>
#include <functional>

/**
 * @brief Ready queue implementation for the Shortest Job First (SJF) scheduling algorithm.
 *
 * This class inherits from the `ReadyQueue` interface and implements the SJF algorithm.
 * SJF is a non-preemptive scheduling algorithm where processes are scheduled for execution
 * based on the shortest burst time. The process with the shortest burst time is executed first.
 * In case of a tie in burst times, the process with the earlier arrival time is prioritized.
 */
class SJF : public ReadyQueue
{
public:
    /**
     * @brief Adds a process to the SJF ready queue.
     *
     * The process is inserted into the priority queue based on its burst time,
     * with shorter burst times having higher priority.
     *
     * @param p The Process object to be added to the queue.
     */
    void addProcess(const Process &p) override;

    /**
     * @brief Retrieves and removes the next process to execute from the SJF ready queue.
     *
     * The process with the shortest burst time (or earliest arrival time in case of a tie)
     * is removed from the queue and returned.
     *
     * @return The Process object with the shortest burst time/earliest arrival time.
     * @throws std::runtime_error if the queue is empty.
     */
    Process getNextProcess() override;

    /**
     * @brief Checks if the SJF ready queue is empty.
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const override;

private:
    /**
     * @brief The priority queue used to store and prioritize processes.
     *
     * Processes are stored in the priority queue with the following criteria:
     *  - Highest priority: Shortest burst time.
     *  - Tiebreaker: Earliest arrival time.
     *
     * The custom comparator lambda function ensures this ordering.
     */
    std::priority_queue<Process, std::vector<Process>, std::function<bool(const Process &, const Process &)>> readyQueue{
        /**
         * @brief Custom comparator for the priority queue.
         *
         * Compares two Process objects and returns true if the first process (`p1`) has a
         * higher priority than the second process (`p2`).  The higher priority is determined
         * by shorter burst time, with earlier arrival time used as a tiebreaker if burst times
         * are equal.
         *
         * @param p1 The first Process object to compare.
         * @param p2 The second Process object to compare.
         * @return True if `p1` has a higher priority than `p2`, false otherwise.
         */
        [](const Process &p1, const Process &p2)
        {
            if (p1.burst_time == p2.burst_time)
            {
                return p1.arrival_time > p2.arrival_time; // Prioritize earlier arrival if burst times are equal
            }
            return p1.burst_time > p2.burst_time; // Prioritize shorter burst time
        }};
};

#endif // SJF_H
