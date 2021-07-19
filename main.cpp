//B.Create a C++ project in your integrated development environment(IDE) with the following files :
//•  degree.h
//•  student.hand student.cpp
//•  roster.hand roster.cpp
//•  main.cpp

#include<iostream>
#include<iomanip>
#include "degree.h"
#include "roster.h"
#include "student.h"
using std::cout;
using std::cerr;
using namespace std;

int main()
{
    int numStudents = 5;
    //input is 5 comma delimited strings

    //A.  Modify the “studentData Table” to include your personal information as the last item.
    string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Rodney,Agosto,ragost1@wgu.edu,33,30,50,33,SOFTWARE",
    };

    //F.Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results :
    //1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 000568951" << endl;
    cout << "Student Name: Rodney Agosto\n" << endl;

    //F.Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results :
    //2.  Create an instance of the Roster class called classRoster.
    Roster* classRoster = new Roster(numStudents);

    //F.Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results :
    //3.  Add each student to classRoster.
    cout << "Parsing data and adding students:\n" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        classRoster->parseThenAdd(studentData[i]);
    }
    cout << "DONE.\n" << endl;

    //F.Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results :
    //4.  Convert the following pseudo code to complete the rest of the  main() function:
    //classRoster.printAll();
    cout << "Displaying all students:\n" << endl;
    classRoster->print_ALL();
    cout << "\n" << endl;//extra line

    //classRoster.printInvalidEmails();
    cout << "Displaying invalid emails:\n" << endl;
    classRoster->printInvalidEmails();//Spots emails that are in error and displays them
    cout << endl;//extra line

    //classRoster.printAverageDaysInCourse(/*current_object's student id*/);
    cout << "Printing average days in course for all students:\n" << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->printAverageDaysToComplete(classRoster->getStudentAt(i)->getStudentID());//Print average days of specified student
    }

    //classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;//extra line
    cout << "Printing students with Software Degree Program:\n" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << "\n" << endl;//extra line

    //classRoster.remove("A3");
    cout << "Removing student ID A3.\n" << endl;//Remove student with ID supplied
    classRoster->remove("A3");

    //classRoster.printAll();
    cout << "Displaying all students:\n" << endl;
    classRoster->print_ALL();
    cout << "\n" << endl;//extra line

    //classRoster.remove("A3");
    ////expected: the above line should print a message saying such a student with this ID was not found.
    cout << "Removing student ID A3:\n" << endl;//Remove student twice to check error condition
    classRoster->remove("A3");

    //All done
    cout << "Program completed\n" << endl;//extra line

    return 0;
}