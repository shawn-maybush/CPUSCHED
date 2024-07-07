#include "EventQueue.h"
#include <iostream>

void EventQueue::push(const Event& event){
    EventKey eventKey(event.timestamp, event.process.process_id);
    events.insert({eventKey, event});
}

const Event& EventQueue::top() const {
    return events.begin()->second;
}

void EventQueue::pop(){
    events.erase(events.begin());
}

bool EventQueue::empty() const {
    return events.empty();
}

void EventQueue::remove(const EventKey& key) {
    int elementsRemoved = events.erase(key);
    if(elementsRemoved == 0){
        std::cout << "Event Not Found\n";
    }
}

void EventQueue::printQueue() {
    std::cout << "Event Queue:\n";
    for (const auto& [key, event] : events) { 
        std::cout << "Time: " << event.timestamp << " ";
        std::cout << "| Type: " << (event.type == Event::ARRIVAL ? "Arrival " : "Completion ");
        std::cout << "| Process ID: " << event.process.process_id << std::endl;
    }
}