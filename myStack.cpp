// myStack.cpp

#include "myStack.h"
#include <iostream>
#include "Employee.h"
using namespace std;

// Returns the elts vector
vector<Employee>& myStack::getElts() {
    return elts;
}

// Pushes the given Employee object onto the top of the stack
void myStack::Push(Employee emp) {
    elts.push_back(emp);
}

// Removes top element from the stack AND returns it
Employee myStack::Pop() {
    if (!isempty()) {
        Employee top = elts.back();
        elts.pop_back();
        return top;
    } else {
        // Handle underflow case
        std::cerr << "Error: Stack is empty." << std::endl;
        exit(1);
    }
}

// Returns true if stack is empty or false if not empty
bool myStack::isempty() {
    return elts.empty();
}

// Prints out the stack starting at the top
void myStack::printStack() {
//    if (!isempty()) {
//        for (int i = elts.size() - 1; i >= 0; --i) {
//            cout << elts[i] << std::endl;
//        }
//    } else {
//        cout << "Stack is empty." << std::endl;
//    }
    if (isempty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    for (int i = elts.size() - 1; i >= 0; --i) {
        cout << elts[i] << endl;
    }
}

//// Overload the + operator to concatenate two stacks
//myStack myStack::operator+(const myStack& other) {
//    myStack temp = *this; // Create a copy of current stack
//
//    // Copy elements from 'other' stack to 'temp' stack
//    for (const auto& emp : other.elts) {
//        temp.Push(emp);
//    }
//
//    return temp;
//}

// Overload the + operator to concatenate two stacks
myStack myStack::operator+(const myStack& other) {
    myStack temp = *this; // Create a copy of the current stack

    // Iterate through the 'other' stack and push its elements onto the 'temp' stack
    // This will preserve the order of elements
    for (int i = other.elts.size() - 1; i >= 0; --i) {
        temp.Push(other.elts[i]);
    }

    return temp; // Return the concatenated stack
}
