#include <iostream>
#include "roster.h"

int main() {
    // F1: Print course information
    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011525749" << endl;
    cout << "Name: Kabbo Sultan" << endl << endl;

    // Student data
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kabbo,Sultan,ksulta7@wgu.edu,24,10,30,25,SOFTWARE"
    };

    // F2: Create roster instance
    Roster classRoster;

    // F3: Add each student to classRoster
    for (int i = 0; i < 5; i++) {
        classRoster.parseAndAdd(studentData[i]);
    }

    // F4: Execute required functions
    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    // Print average days in course for each student
    cout << "Displaying average days in course:" << endl;
    for (const string& data : studentData) {
        string studentID = data.substr(0, data.find(','));
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << endl;

    cout << "Displaying by degree program: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing student A3:" << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Removing student A3 again:" << endl;
    classRoster.remove("A3");
    cout << endl;

    // Destructor is called automatically when classRoster goes out of scope

    return 0;
}
