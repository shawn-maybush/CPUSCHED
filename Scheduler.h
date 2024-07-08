/**
 * @file Scheduler.h
 * @brief Defines the `Scheduler` class for simulating process scheduling algorithms.
 * @author Shawn Maybush
 * @date 2024-07-06 
 */
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

/**
 * @class Scheduler
 * @brief Simulates various process scheduling algorithms.
 *
 * This class manages the simulation of process scheduling, handling events,
 * loading processes, and calculating statistics based on the chosen algorithm.
 */
class Scheduler {
public:
    /**
     * @brief Constructs a new `Scheduler` object.
     * 
     * @param fileName The name of the input file containing process data.
     * @param algorithmType The type of scheduling algorithm to use ("FIFO", "SJF", or "Priority").
     */
    Scheduler(const std::string& fileName, const std::string& algorithmType);

    /**
     * @brief Runs the process scheduling simulation.
     *
     * This method initializes the simulation, loads processes from the input file,
     * and then processes events (arrivals and completions) until all processes are completed.
     */
    void runSimulation();

    /**
     * @brief Prints statistics about the completed processes and CPU utilization.
     *
     * This method calculates and displays various statistics, including average waiting time,
     * turnaround time, response time, throughput, and CPU utilization.
     */
    void printStatistics() const;
private:
    /**
     * @brief Loads processes from the specified file into the event queue.
     * 
     * @param fileName The name of the input file containing process data.
     */
    void loadProcessesFromFile(const std::string& fileName);

    /**
     * @brief Handles the arrival of a new process.
     * 
     * @param arrivalEvent The `Event` object representing the process arrival.
     * @param currentTime The current simulation time.
     */
    void handleArrivalEvent(const Event& arrivalEvent, const int& currentTime);

    /**
     * @brief Handles the completion of a process.
     * 
     * @param completionEvent The `Event` object representing the process completion.
     * @param currentTime The current simulation time.
     */
    void handleCompletionEvent(const Event& completionEvent, const int& currentTime);

    int currentTime = 0;              /**< @brief The current simulation time. */
    std::string algorithmType;       /**< @brief The type of scheduling algorithm used. */
    std::vector<Process> completedProcesses; /**< @brief A vector to store completed processes. */
    CPU cpu;                          /**< @brief The CPU object for the simulation. */
    ReadyQueue* readyQueue;           /**< @brief A pointer to the ready queue (algorithm-specific). */
    EventQueue eventQueue;            /**< @brief The event queue for the simulation. */
};

#endif // SCHEDULER_H
