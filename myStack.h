// myStack.h

#ifndef MYSTACK_H
#define MYSTACK_H

#include "Employee.h"
#include <vector>

class myStack {
protected:
    std::vector<Employee> elts;

public:
    // Returns the elts vector
    std::vector<Employee>& getElts();

    // Pushes the given Employee object onto the top of the stack
    void Push(Employee emp);

    // Removes top element from the stack AND returns it
    Employee Pop();

    // Returns true if stack is empty or false if not empty
    bool isempty();

    // Prints out the stack starting at the top
    void printStack();

    // Overload the + operator to concatenate two stacks
    myStack operator+(const myStack& other);
};

#endif
