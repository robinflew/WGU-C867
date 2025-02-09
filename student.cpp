#include "student.h"
#include <iostream>

// Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
                int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

// Destructor
Student::~Student() {
    // No dynamic memory to release
}

// Getters (accessors)
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

// Setters (mutators)
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print function - now using accessors
void Student::print() {
    cout << getStudentID() << "\t";
    cout << "First Name: " << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "daysInCourse: {" << getDaysInCourse()[0] << ", "
         << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} ";
    cout << "Degree Program: ";
    switch (getDegreeProgram()) {
        case SECURITY: cout << "SECURITY"; break;
        case NETWORK: cout << "NETWORK"; break;
        case SOFTWARE: cout << "SOFTWARE"; break;
    }
    cout << endl;
}
