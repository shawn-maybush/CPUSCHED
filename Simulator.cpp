#include "FIFO.h"
#include "SJF.h"
#include "Priority.h"
#include <fstream>
#include <iostream> 

int main() {
    // ...
    std::ifstream inputFile("process_data.txt");
    std::string algorithmChoice;
    std::cout << "Enter scheduling algorithm (FIFO, SJF, Priority): ";
    std::cin >> algorithmChoice;

    Scheduler* scheduler;
    if (algorithmChoice == "FIFO") {
        scheduler = new FIFO();
    }
    // similar for SJF and Priority

    Process p;
    while (inputFile >> p.process_id >> p.arrival_ts >> p.priority >> p.burst_time) {
        scheduler->addProcess(p);
    }

    // ...
}
