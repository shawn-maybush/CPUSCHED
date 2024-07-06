/**
 * @file Process.h
 * @brief Defines the Process structure for CPU scheduling simulation.
 * @author Shawn Maybush
 * @date 06-28-2024
 */

#ifndef PROCESS_H
#define PROCESS_H

/**
 * @brief Represents a process in the CPU scheduling simulation.
 *
 * This struct stores all the relevant information about a process, including
 * its arrival time, burst time, priority, and statistics related to its execution.
 */
struct Process {
    /**
     * @brief Unique identifier for the process.
     */
    int process_id;

    /**
     * @brief Timestamp when the process arrives in the system.
     */
    int arrival_time;

    /**
     * @brief Total time the process needs to run on the CPU.
     */
    int burst_time;

    /**
     * @brief Total CPU time the process has completed so far.
     */
    int completed_burst_time = 0; 

    /**
     * @brief Priority of the process (lower value indicates higher priority).
     */
    int priority;

    /**
     * @brief Timestamp when the process starts executing on the CPU.
     *        Initialized to -1 to indicate the process has not yet started.
     */
    int start_time = -1;

    /**
     * @brief Timestamp when the process completes its execution.
     *        Initialized to -1 to indicate the process has not yet completed.
     */
    int completion_time = -1;

    /**
     * @brief Total time the process spends waiting in the ready queue.
     */
    int wait_time = 0; 

    /**
     * @brief Time interval between the process's arrival and completion.
     */
    int turnaround_time = 0;

    /**
     * @brief Time interval between the process's arrival and the first time it gets the CPU.
     */
    int response_time = 0;

    /**
     * @brief Default constructor for the Process structure.
     * Initializes all members to default values.
     */
    Process() : process_id(0), arrival_time(0), burst_time(0), priority(0), start_time(-1), completion_time(-1), wait_time(0), turnaround_time(0), response_time(0), completed_burst_time(0) {}
    
    /**
     * @brief Copy constructor for creating a new Process object as a copy of an existing one.
     * @param other The existing Process object to copy from.
     */
    Process(const Process& other) {
        process_id = other.process_id;
        arrival_time = other.arrival_time;
        burst_time = other.burst_time;
        completed_burst_time = other.completed_burst_time;
        priority = other.priority;
        start_time = other.start_time;
        completion_time = other.completion_time;
        wait_time = other.wait_time;
        turnaround_time = other.turnaround_time;
        response_time = other.response_time;
    }
};

#endif // PROCESS_H

