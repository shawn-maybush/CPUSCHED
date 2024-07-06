#ifndef EVENT_H
#define EVENT_H

#include "Process.h"
#include <functional>

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
     *        This is only used for ARRIVAL events.
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

    /**
     * @brief Overloads the less-than operator to compare events by timestamp.
     *
     * This is used for ordering events in a priority queue (smallest timestamp first).
     * If timestamps are equal, ARRIVAL events are prioritized over COMPLETION events,
     * and if both are the same, then arrival time is used as a tiebreaker.
     *
     * @param other The other Event object to compare to.
     * @return True if this event has a lower timestamp or an equal timestamp but higher priority
     *         (ARRIVAL before COMPLETION).
     */
    bool operator<(const Event &other) const
    {
        if (timestamp == other.timestamp)
        {
            return type == EventType::ARRIVAL;
        }
        return timestamp < other.timestamp;
    }
};

#endif // EVENT_H
