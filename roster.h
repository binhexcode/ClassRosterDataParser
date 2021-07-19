//B.Create a C++ project in your integrated development environment(IDE) with the following files :
//•  degree.h
//•  student.hand student.cpp
//•  roster.hand roster.cpp
//•  main.cpp

#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"

//Roster stores students
class Roster {
private:
	//index of last book
	int privateRosterLastIndex;

	//max size of repository
	int privateRosterCapacity;

	//E.Create a Roster class (roster.cpp) by doing the following :
	//1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

	//array pointers
	Student** classRosterArray;

public:
	//empty constructor
	Roster();

	//full constructor
	Roster(int privateRosterCapacity);
	//Section E
	Student* getStudentAt(int publicRosterIndex);

	//E.Create a Roster class (roster.cpp) by doing the following :
	//	2.  Create a student object for each student in the data tableand populate classRosterArray.
	//	a.Parse each set of data identified in the “studentData Table.”
	//	b.Add each student object to classRosterArray.

	void parseThenAdd(string publicDatarow);

	//E.Create a Roster class (roster.cpp) by doing the following :
	//3.  Define the following functions :
	//	a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
	//	b.  public void remove(string studentID)  that removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.
	//	c. public void printAll() that prints a complete tab - separated list of student data in the provided format : A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.The printAll() function should loop through all the students in classRosterArrayand call the print() function for each student.
	//	d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter.
	//	e.  public void printInvalidEmails() that verifies student email addressesand displays all invalid email addresses to the user.
	//	Note : A valid email should include an at sign('@') and period('.') and should not include a space(' ').
	//	f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.

	void add(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		double daysToComplete0,
		double daysToComplete1,
		double daysToComplete2,
		DegreeProgram degreeProgram);
	void print_ALL();
	void remove(string studentID);
	void printAverageDaysToComplete(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram SOFTWARE);

	//destructor
	~Roster();
};