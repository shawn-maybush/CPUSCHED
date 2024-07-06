/**
 * @file CPU.h
 * @brief Defines the CPU class for representing a CPU in a process scheduling simulation.
 * @author Shawn Maybush
 * @date 07-05-2024
 */

#ifndef CPU_H
#define CPU_H

#include "Process.h"

/**
 * @brief Represents a CPU in a process scheduling simulation.
 *
 * The CPU class models a single central processing unit (CPU) in a simulation.
 * It can load and unload processes, update process statistics, and provides information about its current state.
 */
class CPU {
public:
    /**
     * @brief Default constructor for the CPU class.
     *
     * Initializes the CPU to an idle state with no running process.
     */
    CPU();

    /**
     * @brief Gets the currently running process on the CPU.
     *
     * @return A const pointer to the currently running Process object.
     *         Returns nullptr if the CPU is idle.
     */
    const Process* getRunningProcess() const;

    /**
     * @brief Checks if the CPU is idle (i.e., has no running process).
     *
     * @return True if the CPU is idle, false otherwise.
     */
    bool isIdle() const;

    /**
     * @brief Loads a process onto the CPU and calculates its completion time.
     *
     * Sets the process's start_time to the current time.
     *
     * @param p The Process object to load onto the CPU.
     * @param currentTime The current simulation time when the process is loaded.
     * @return The completion time of the process, taking into account any previously completed burst time.
     */
    int loadProcess(const Process& p, int currentTime);

    /**
     * @brief Unloads the currently running process from the CPU.
     * 
     * Updates the completed_burst_time and wait_time of the process.
     * 
     * @param currentTime The current simulation time when the process is unloaded.
     * @return The Process object that was just unloaded from the CPU.
     */
    Process unloadProcess(int currentTime);

private:
    /**
     * @brief Pointer to the currently running Process object.
     *        Set to nullptr if the CPU is idle.
     */
    Process* runningProcess;
};

#endif // CPU_H
