/**
 * @file EventQueue.h
 * @brief Defines the EventQueue class for managing events in a CPU scheduling simulation.
 * @author Shawn Maybush
 * @date 06-29-2024
 */

#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <map>      
#include <iostream>
#include "Event.h"

/**
 * @brief Class for managing events in a CPU scheduling simulation.
 *
 * This class provides a priority queue-like interface for scheduling and processing
 * events in a CPU scheduling simulation. It uses a `std::multimap` to store events
 * in sorted order by their timestamp (and process ID as a tiebreaker).
 */
class EventQueue {
public:
    /**
     * @brief Type alias for the event key, a pair of (timestamp, process_id).
     */
    using EventKey = std::pair<int, int>;

    /**
     * @brief Adds an event to the queue.
     *
     * @param event The event to add. The event's timestamp is used as the key in the multimap.
     */
    void push(const Event& event);

    /**
     * @brief Returns a const reference to the earliest (top) event in the queue.
     *
     * The earliest event is the one with the lowest timestamp (or lowest process ID in case of a tie).
     *
     * @return The earliest event.
     * @throws std::out_of_range if the queue is empty.
     */
    const Event& top() const;

    /**
     * @brief Removes the earliest (top) event from the queue.
     *
     * @throws std::out_of_range if the queue is empty.
     */
    void pop();

    /**
     * @brief Checks if the queue is empty.
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Removes a specific event from the queue based on its key.
     *
     * @param key The EventKey representing the (timestamp, process_id) of the event to remove.
     */
    void remove(const EventKey& key);

    /**
     * @brief Prints the contents of the event queue to the console for debugging purposes.
     */
    void printQueue();

private:
    /**
     * @brief The underlying multimap used to store events.
     *
     * Events are stored in sorted order by their timestamp. If two events have the same timestamp,
     * they are ordered by their process ID.
     */
    std::multimap<EventKey, Event> events; 
};

#endif // EVENTQUEUE_H
