#include "EventQueue.h"
#include <iostream>

void EventQueue::push(const Event& event){
    events.insert(event);
}

const Event& EventQueue::top() const {
    return *events.begin();
}

void EventQueue::pop(){
    events.erase(events.begin());
}

bool EventQueue::empty() const {
    return events.empty();
}

void EventQueue::remove(const Event& eventToRemove) {
    int elementsRemoved = events.erase(eventToRemove);
    if(elementsRemoved == 0){
        std::cout << "Event Not Found\n";
    }
}

void EventQueue::printQueue(){
    for (auto it = events.begin(); it != events.end(); it++){
        std::cout << "Time: " << it->timestamp << " ";
        std::cout << "| Type: " << (it->type == Event::ARRIVAL ? "Arrival " : "Completion ");
        std::cout << "| Process ID: " << it->process.process_id << std::endl;
    }
}