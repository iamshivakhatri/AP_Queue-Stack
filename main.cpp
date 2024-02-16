#include <iostream>
#include <fstream>
#include <algorithm>
#include "myStack.h"
#include "myQueue.h"

using namespace std;

int main() {
    // Create myStack object S1 and myQueue object Q1
    myStack S1;
    myQueue Q1;

    // Prompt user for the first input file path
    string filePath1;
    cout << "Please enter the path for file #1: ";
    cin >> filePath1;

    // Open the first input file
    ifstream file1(filePath1);
    if (!file1.is_open()) {
        cerr << "Error: Unable to open file " << filePath1 << endl;
        return 1;
    }

    // Read the first input file and populate S1 and Q1
    string lastName, firstName, socsecnum, deptNum;
    double wage;
    while (file1 >> lastName >> firstName >> socsecnum >> deptNum >> wage) {
        Employee emp(firstName, lastName, socsecnum, deptNum, wage);
        S1.Push(emp);
        Q1.Enqueue(emp);
    }
    file1.close();

    // Create myStack object S2 and myQueue object Q2
    myStack S2;
    myQueue Q2;

    // Prompt user for the second input file path
    string filePath2;
    cout << "Please enter the path for file #2: ";
    cin >> filePath2;

    // Open the second input file
    ifstream file2(filePath2);
    if (!file2.is_open()) {
        cerr << "Error: Unable to open file " << filePath2 << endl;
        return 1;
    }

    // Read the second input file and populate S2 and Q2
    while (file2 >> lastName >> firstName >> socsecnum >> deptNum >> wage) {
        Employee emp(firstName, lastName, socsecnum, deptNum, wage);
        S2.Push(emp);
        Q2.Enqueue(emp);
    }
    file2.close();

    // Print stack #1
    cout << "STACK #1" << endl;
    cout << "_______" << endl;
    S1.printStack();

    // Print queue #1
    cout << "QUEUE #1" << endl;
    cout << "_______" << endl;
    Q1.printQueue();

    // Print stack #2
    cout << "STACK #2" << endl;
    cout << "_______" << endl;
    S2.printStack();

    // Print queue #2
    cout << "QUEUE #2" << endl;
    cout << "_______" << endl;
    Q2.printQueue();

    // Sort the vectors using std::sort
    sort(S1.getElts().begin(), S1.getElts().end(), less<Employee>());
    sort(Q1.getElts().begin(), Q1.getElts().end(), less<Employee>());
    sort(S2.getElts().begin(), S2.getElts().end(), less<Employee>());
    sort(Q2.getElts().begin(), Q2.getElts().end(), less<Employee>());

    // Print the sorted lists
    cout << "AFTER SORTING" << endl;
    cout << "STACK #1" << endl;
    cout << "_______" << endl;
    S1.printStack();
    cout << "QUEUE #1" << endl;
    cout << "_______" << endl;
    Q1.printQueue();
    cout << "STACK #2" << endl;
    cout << "_______" << endl;
    S2.printStack();
    cout << "QUEUE #2" << endl;
    cout << "_______" << endl;
    Q2.printQueue();

    // Create myStack object S3 and myQueue object Q3 by adding S1 and S2, Q1 and Q2 respectively
    myStack S3 = S1 + S2;
    myQueue Q3 = Q1 + Q2;

    // Print myStack S3 followed by myQueue Q3
    cout << "STACK #3 (after adding S1 and S2)" << endl;
    cout << "_______" << endl;
    S3.printStack();
    cout << "QUEUE #3 (after adding Q1 and Q2)" << endl;
    cout << "_______" << endl;
    Q3.printQueue();

    // Sort myStack S3 and myQueue Q3
    sort(S3.getElts().begin(), S3.getElts().end(), less<Employee>());
    sort(Q3.getElts().begin(), Q3.getElts().end(), less<Employee>());

    // Print sorted myStack S3 and myQueue Q3
    cout << "AFTER SORTING S3" << endl;
    cout << "STACK #3" << endl;
    cout << "_______" << endl;
    S3.printStack();
    cout << "AFTER SORTING Q3" << endl;
    cout << "QUEUE #3" << endl;
    cout << "_______" << endl;
    Q3.printQueue();

    // Pop all items from myStack S2
    cout << "REMOVING ALL ITEMS FROM S2" << endl;
    while (!S2.isempty()) {
        Employee emp = S2.Pop();
        cout << "POPPING " << emp << endl;
    }
    // Try to print the now empty stack
    cout << "Attempting to print the now empty stack S2: " << endl;
    S2.printStack();

    // Dequeue all elements from myQueue Q2
    cout << "DEQUEUING ALL ITEMS FROM Q2" << endl;
    while (!Q2.isempty()) {
        Employee emp = Q2.Dequeue();
        cout << "DEQUEUEING " << emp << endl;
    }
    // Try to print the now empty queue
    cout << "Attempting to print the now empty queue Q2: " << endl;
    Q2.printQueue();

    // Exit message
    cout << "Program execution is complete." << endl;

    return 0;
}
