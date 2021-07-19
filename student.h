//B.Create a C++ project in your integrated development environment(IDE) with the following files :
//•  degree.h
//•  student.hand student.cpp
//•  roster.hand roster.cpp
//•  main.cpp

#pragma once
#include <string>
#include "degree.h"
using std::string;

//D.For the Student class, do the following :
//1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables :
//•  student ID
//•  first name
//•   last name
//•  email address
//•  age
//•  array of number of days to complete each course
//•  degree program

class Student
{
public:
	static const int daysArraySize = 3;

	//D.For the Student class, do the following :
	/*2.  Create each of the following functions in the Student class :
		a.an accessor(i.e., getter) for each instance variable from part D1
		b.a mutator(i.e., setter) for each instance variable from part D1
		c.All external accessand changes to any instance variables of the Student class must be done using accessorand mutator functions.
		d.constructor using all of the input parameters provided in the table
		e.print() to print specific student data*/


	//empty constuctor
	Student();

	//full constructor
	Student(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		double daysToComplete[],
		DegreeProgram degreeProgram);

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	double* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//setters (needs to be different parameter names)
	void setStudentID(string setterStudentID);
	void setFirstName(string setterFirstName);
	void setLastName(string setterLastName);
	void setEmail(string setterEmail);
	void setAge(int setterAge);
	void setDaysToComplete(double setterDaysToComplete[]);
	void setDegreeProgram(DegreeProgram setterDegreeProgram);

	//print() to print specific student data
	void print();

	//destructor
	~Student();

protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	double daysToComplete[daysArraySize];
	DegreeProgram degreeProgram;
};