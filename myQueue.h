// myQueue.h

#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "Employee.h"
#include <vector>

class myQueue {
protected:
    std::vector<Employee> elts;

public:
    // Returns the elts vector
    std::vector<Employee>& getElts();

    // Adds the given Employee object to the rear of the queue
    void Enqueue(Employee emp);

    // Removes and returns the front element from the queue
    Employee Dequeue();

    // Returns true if queue is empty or false if not empty
    bool isempty();

    // Prints out the queue from front to rear
    void printQueue();

    // Overload the + operator to concatenate two queues
    myQueue operator+(const myQueue& other);
};

#endif
