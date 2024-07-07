/**
 * @file CPU.h
 * @brief Defines the `CPU` class for simulating a central processing unit in a process scheduling environment.
 * @author Shawn Maybush
 * @date 2024-07-06
 */

#ifndef CPU_H
#define CPU_H

#include "Process.h" // Include the Process class definition

/**
 * @class CPU
 * @brief Represents a single central processing unit (CPU) in a process scheduling simulation.
 *
 * The CPU class models the behavior of a CPU, allowing it to:
 * - Load and unload processes
 * - Track the currently running process
 * - Update process statistics (e.g., completion time, waiting time)
 * - Calculate and provide information about its utilization
 */
class CPU
{
public:
    /**
     * @brief Constructs a new CPU object in an idle state (no running process).
     */
    CPU();

    /**
     * @brief Returns a pointer to the currently running `Process`, or `nullptr` if the CPU is idle.
     *
     * @return A const pointer to the `Process` object running on the CPU.
     * @throws std::runtime_error if the CPU is empty.
     */
    const Process *getRunningProcess() const;

    /**
     * @brief Checks if the CPU is currently idle (i.e., has no running process).
     * @return `true` if the CPU is idle, `false` otherwise.
     */
    bool isIdle() const;

    /**
     * @brief Loads a process onto the CPU and calculates its expected completion time.
     *
     * This method sets the process's `start_time` to the current time.
     *
     * @param p The `Process` object to load onto the CPU.
     * @param currentTime The current simulation time.
     * @return The expected completion time of the process, accounting for any previously completed burst time.
     */
    int loadProcess(const Process &p, int currentTime);

    /**
     * @brief Unloads the currently running process from the CPU.
     *
     * This method updates the process's `completed_burst_time` and `wait_time` statistics.
     * If the CPU is empty, a `runtime_error` is thrown.
     *
     * @param currentTime The current simulation time.
     * @return A copy of the `Process` object that was unloaded.
     * @throws std::runtime_error if the CPU is empty.
     */
    Process unloadProcess(int currentTime);

    /**
     * @brief Retrieves the total amount of time the CPU has been busy executing processes.
     * @return The total busy time of the CPU.
     */
    int getTotalBusyTime() const;

private:
    /**
     * @brief A pointer to the currently running `Process`.
     *
     * This will be `nullptr` if the CPU is idle.
     */
    Process *runningProcess = nullptr;

    /**
     * @brief The total amount of time (in simulation units) that the CPU has been busy executing processes.
     */
    int totalBusyTime = 0;

    /**
     * @brief The simulation time when the last process was loaded onto the CPU.
     *
     * This is used to calculate the duration for which the current process has been running.
     */
    int lastProcessStartTime = 0;
};

#endif // CPU_H
