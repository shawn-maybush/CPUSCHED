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
     * @brief Calculates and writes process scheduling statistics to an output file.
     *
     * This method calculates and outputs various statistics related to the completed processes and CPU utilization:
     *   - Number of processes completed
     *   - Total elapsed time (in CPU time units)
     *   - Throughput (processes completed per CPU time unit)
     *   - CPU utilization (%)
     *   - Average waiting time (in CPU time units)
     *   - Average turnaround time (in CPU time units)
     *   - Average response time (in CPU time units)
     *
     * The statistics are written to a text file with the same name as the input file, 
     * but with "-output.txt" appended to the filename.
     *
     * @param input_filename The name of the input file used for the simulation.
     * @throws std::runtime_error if the output file cannot be opened.
     */
    void printStatistics(const std::string& input_filename) const;
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
