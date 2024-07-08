#ifndef EVENT_H
#define EVENT_H

#include "Process.h"
#include <functional>

using EventKey = std::pair<int, int>;

/**
 * @brief Represents an event in the CPU scheduling simulation.
 */
struct Event
{
    /**
     * @brief Types of events that can occur in the simulation.
     */
    enum EventType
    {
        ARRIVAL,
        COMPLETION
    }; 

    /**
     * @brief The type of the event (ARRIVAL or COMPLETION).
     */
    EventType type;

    /**
     * @brief The timestamp at which the event occurs.
     */
    int timestamp;

    /**
     * @brief The process associated with the event.
     *       
     */
    Process process;

    /**
     * @brief Constructor for creating an Event object.
     *
     * @param type The type of event (ARRIVAL or COMPLETION).
     * @param timestamp The timestamp at which the event occurs.
     * @param p The process associated with the event (optional, only for ARRIVAL events).
     */
    Event(EventType type, int timestamp, const Process &p = Process())
        : type(type), timestamp(timestamp), process(p) {}

    /**
     * @brief Default Constructor for creating an Event object.
     *
     */

    Event() : type(EventType::ARRIVAL), timestamp(0), process(Process()) {}

};

#endif // EVENT_H
