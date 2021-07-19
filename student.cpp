//B.Create a C++ project in your integrated development environment(IDE) with the following files :
//•  degree.h
//•  student.hand student.cpp
//•  roster.hand roster.cpp
//•  main.cpp

#include<iostream>
#include<iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;
using namespace std;


//empty constuctor
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = 0;
}

//full constuctor
Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	double daysToComplete[],
	DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++)	this->daysToComplete[i] = daysToComplete[i];
	this->degreeProgram = degreeProgram;
}

//getters
string Student::getStudentID()
{
	return studentID;
}
string Student::getFirstName()
{
	return firstName;
}
string Student::getLastName()
{
	return lastName;
}
string Student::getEmail()
{
	return email;
}
int Student::getAge()
{
	return age;
}
double* Student::getDaysToComplete()
{
	return daysToComplete;
}
DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}

//setters
void Student::setStudentID(string setterStudentID)
{
	this->studentID = setterStudentID;
}
void Student::setFirstName(string setterFirstName)
{
	this->firstName = setterFirstName;
}
void Student::setLastName(string setterLastName)
{
	this->lastName = setterLastName;
}
void Student::setEmail(string setterEmail)
{
	this->email = setterEmail;
}
void Student::setAge(int setterAge)
{
	this->age = setterAge;
}
void Student::setDaysToComplete(double setterDaysToComplete[])
{
	for (int i = 0; i < daysArraySize; i++)
		this->daysToComplete[i] = setterDaysToComplete[i];
}
void Student::setDegreeProgram(DegreeProgram setterDegreeProgram)
{
	this->degreeProgram = setterDegreeProgram;
}

//print method
void Student::print() {
	cout << left << setw(5) << studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(25) << email;
	cout << left << setw(5) << age;
	cout << left << setw(5) << daysToComplete[0];
	cout << left << setw(5) << daysToComplete[1];
	cout << left << setw(5) << daysToComplete[2];
	cout << left << setw(25) << degreeProgramStrings[degreeProgram];
}

Student::~Student()
{
	//empty
}