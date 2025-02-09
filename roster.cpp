#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>

Roster::Roster() {
    lastIndex = -1;
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

void Roster::parseAndAdd(string studentData) {
    stringstream ss(studentData);
    string items[9];
    string token;
    int i = 0;
    
    while (getline(ss, token, ',')) {
        items[i] = token;
        i++;
    }

    DegreeProgram degreeProgram;
    if (items[8] == "SECURITY") degreeProgram = SECURITY;
    else if (items[8] == "NETWORK") degreeProgram = NETWORK;
    else if (items[8] == "SOFTWARE") degreeProgram = SOFTWARE;

    add(items[0], items[1], items[2], items[3],
        stoi(items[4]), stoi(items[5]), stoi(items[6]), stoi(items[7]),
        degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName,
                                              emailAddress, age, daysArray, degreeProgram);
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            // Shift remaining elements
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Error: Student with ID " << studentID << " not found." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            cout << "Student ID: " << studentID << ", average days in course is: "
                 << average << endl;
            return;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos ||
            email.find('.') == string::npos ||
            email.find(' ') != string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
