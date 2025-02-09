#pragma once
#include "student.h"

class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex;  // Keeps track of the number of students in the roster

public:
    // Constructor
    Roster();
    
    // Destructor
    ~Roster();

    // Required methods
    void add(string studentID, string firstName, string lastName, string emailAddress,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
             DegreeProgram degreeProgram);
    
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Helper method to parse student data
    void parseAndAdd(string studentData);
};
