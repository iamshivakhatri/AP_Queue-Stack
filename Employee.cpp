#include "Employee.h"

Employee::Employee() : firstName(""), lastName(""), socsecnum(""), deptNum(""), wage(0.0) {}

Employee::Employee(const string& first, const string& last, const string& socsec, const string& dept, double w)
        : firstName(first), lastName(last), socsecnum(socsec), deptNum(dept), wage(w) {}

void Employee::setFirstName(const string& first) { firstName = first; }
void Employee::setLastName(const string& last) { lastName = last; }
void Employee::setSocsecnum(const string& socsec) { socsecnum = socsec; }
void Employee::setDeptNum(const string& dept) { deptNum = dept; }
void Employee::setWage(double w) { wage = w; }

string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }
string Employee::getSocsecnum() const { return socsecnum; }
string Employee::getDeptNum() const { return deptNum; }
double Employee::getWage() const { return wage; }

ostream& operator<<(ostream& out, const Employee& E) {
    out << E.lastName <<" "<<   E.firstName <<" " <<   E.socsecnum <<" "  <<E.deptNum <<" "<<E.wage <<"\n";
    return out;
}

bool Employee::operator<(const Employee& other) const {
    if (deptNum != other.deptNum) {
        return deptNum < other.deptNum;
    } else if (lastName != other.lastName) {
        return lastName < other.lastName;
    } else {
        return firstName < other.firstName;
    }
}
