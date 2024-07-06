/**
 * @file SJF.h
 * @brief Defines the SJF (Shortest Job First) readyqueue class.
 * @author Shawn Maybush
 * @date 06-28-2024
 */

#ifndef SJF_H
#define SJF_H

#include "ReadyQueue.h"
#include <queue>
#include <functional>

/**
 * @brief SJF (Shortest Job First - Non-Preemptive) readyqueue class.
 *
 * This class implements the SJF CPU scheduling algorithm. Processes are
 * scheduled for execution based on the shortest burst time, with the process
 * having the shortest burst time being executed first. This implementation is
 * non-preemptive, meaning that once a process starts executing, it will run to
 * completion without interruption.
 */
class SJF : public ReadyQueue
{
public:
    /**
     * @brief Adds a process to the SJF priority queue.
     * @param p The process to add.
     */
    void addProcess(const Process &p) override;

    /**
     * @brief Retrieves the next process to execute from the SJF priority queue.
     * @return The process with the shortest burst time.
     * @throws std::runtime_error if the queue is empty.
     */
    Process getNextProcess() override;

private:
    /**
     * @brief Priority queue that stores processes based on their burst time.
     *        The process with the shortest burst time is at the top of the queue.
     */
    std::priority_queue<Process, std::vector<Process>, std::function<bool(const Process &, const Process &)>> readyQueue{
        /**
         * @brief Custom comparator lambda function for the priority queue.
         *
         * This lambda compares two Process objects based on their burst time. If the burst times
         * are equal, it further compares their arrival times. It returns true if the first
         * process (p1) has a shorter burst time or an earlier arrival time (in case of a tie)
         * than the second process (p2), thus ensuring that the process with the shortest
         * burst time or earliest arrival time is given higher priority in the queue.
         */
        [](const Process &p1, const Process &p2)
        {
            if (p1.burst_time == p2.burst_time)
            {
                return p1.arrival_time < p2.arrival_time; // Tiebreaker: Earlier arrival time
            }
            return p1.burst_time < p2.burst_time;
        }};
};
#endif // SJF_H
