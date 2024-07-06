/**
 * @file EventQueue.h
 * @brief Defines the EventQueue class for managing events in a CPU scheduling simulation.
 * @author Shawn Maybush
 * @date 06-29-2024
 */

#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <set>
#include <iostream>
#include "Event.h"

/**
 * @brief Class for managing events in a CPU scheduling simulation.
 *
 * This class provides a priority queue-like interface for scheduling and processing
 * events in a CPU scheduling simulation. It uses a `std::multiset` to store events
 * in sorted order by their timestamp.
 */
class EventQueue
{
public:
    /**
     * @brief Adds an event to the queue.
     *
     * @param event The event to add.
     */
    void push(const Event &event);

    /**
     * @brief Returns a const reference to the earliest (top) event in the queue.
     *
     * @return The earliest event.
     */
    const Event &top() const;

    /**
     * @brief Removes the earliest (top) event from the queue.
     */
    void pop();

    /**
     * @brief Checks if the queue is empty.
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Removes a specific event from the queue.
     *
     * @param event The event to remove.
     */
    void remove(const Event &event);

    /**
     * @brief Prints the contents of the event queue to the console for debugging purposes.
     */
    void printQueue();

private:
    /**
     * @brief The underlying multiset used to store events in sorted order.
     */
    std::multiset<Event> events;
};

#endif // EVENTQUEUE_H
