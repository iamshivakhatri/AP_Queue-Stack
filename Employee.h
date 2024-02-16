#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string firstName;
    string lastName;
    string socsecnum;
    string deptNum;
    double wage;

public:
    // Default constructor
    Employee();

    // Constructor with arguments
    Employee(const string& first, const string& last, const string& socsec, const string& dept, double w);

    // Setters
    void setFirstName(const string& first);
    void setLastName(const string& last);
    void setSocsecnum(const string& socsec);
    void setDeptNum(const string& dept);
    void setWage(double w);

    // Getters
    string getFirstName() const;
    string getLastName() const;
    string getSocsecnum() const;
    string getDeptNum() const;
    double getWage() const;

    // Overload << operator
    friend ostream& operator<<(ostream& out, const Employee& E);

    // Overload < operator
    bool operator<(const Employee& other) const;
};

#endif /* EMPLOYEE_H */
