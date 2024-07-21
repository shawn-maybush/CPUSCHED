# CPU Scheduler Simulator

A C++ simulation of various CPU scheduling algorithms (FIFO, SJF, Priority) for educational purposes. This project aims to demonstrate the behavior and performance characteristics of different scheduling approaches in managing a workload of processes.

## Installation

You can install and build the CPU Scheduler Simulator in two ways:

#### From Archive (e.g., ZIP):
1. Extract the downloaded archive.
2. Open a terminal or command prompt and change to the extracted directory.


#### From Source Code (using Git):
1. Clone the Repository:
   ```
   git clone https://github.com/shawn-maybush/CPUSCHED.git
   ```
2. Navigate to the Project Directory:
   ```
   cd CPUSCHED
   ```

#### Build
```
make
```

## Usage

Run the simulator using the following command:
```Bash
./scheduler_simulator <data_file> <algorithm>
```
- `<data_file>`: Path to the input text file containing process data.
- `<algorithm>`: The scheduling algorithm to use (FIFO, SJF, or Priority).

## Input Data Format

The input data file should be a text file with the following format:

```
Arrival time	CPU Burst length	Priority
0 5 2
2 3 1
4 6 3
... (more processes)
```
- Each subsequent line represents a process, with space-separated values for:
    - Arrival Time (integer)
    - CPU Burst length (integer)
    - Priority (integer, lower is higher priority)

## Output

The simulator will print the following statistics to the console:

- Number of processes
- Total elapsed time (in CPU time units)
- Throughput (processes per time unit)
- CPU utilization (%)
- Average waiting time (in CPU time units)
- Average turnaround time (in CPU time units)
- Average response time (in CPU time units)

## Algorithms

The following scheduling algorithms are implemented:

- **FIFO (First-In-First-Out):** Processes are scheduled in the order they arrive.
- **SJF (Shortest Job First):** Processes with the shortest burst time are prioritized.
- **Priority Scheduling:** Processes with higher priorities are prioritized.

## Dependencies

- C++11 or later
- A standard C++ library implementation
- Make (for building the project)


