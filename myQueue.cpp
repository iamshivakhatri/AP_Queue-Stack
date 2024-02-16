// myQueue.cpp

#include "myQueue.h"
#include <iostream>

using namespace std;

// Returns the elts vector
vector<Employee>& myQueue::getElts() {
    return elts;
}

// Adds the given Employee object to the rear of the queue
void myQueue::Enqueue(Employee emp) {
    elts.push_back(emp);
}

// Removes and returns the front element from the queue
Employee myQueue::Dequeue() {
    if (!isempty()) {
        Employee front = elts.front();
        elts.erase(elts.begin());
        return front;
    } else {
        // Handle underflow case
        cerr << "Error: Queue is empty." << endl;
        exit(1);
    }
}

// Returns true if queue is empty or false if not empty
bool myQueue::isempty() {
    return elts.empty();
}

// Prints out the queue from front to rear
void myQueue::printQueue() {
    if (!isempty()) {
        for (const auto& emp : elts) {
            cout << emp << endl;
        }
    } else {
        cout << "Queue is empty." << endl;
    }
}

// Overload the + operator to concatenate two queues
myQueue myQueue::operator+(const myQueue& other) {
    myQueue temp = *this; // Create a copy of current queue

    // Copy elements from 'other' queue to 'temp' queue
    for (const auto& emp : other.elts) {
        temp.Enqueue(emp);
    }

    return temp;
}
