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

//empty constructor
Roster::Roster()
{
	this->privateRosterCapacity = 0;
	this->privateRosterLastIndex = -1;
	this->classRosterArray = nullptr;
}

//full constructor
Roster::Roster(int privateRosterCapacity) {
	this->privateRosterCapacity = privateRosterCapacity;
	this->privateRosterLastIndex = -1;
	this->classRosterArray = new Student * [privateRosterCapacity];
}

Student* Roster::getStudentAt(int publicRosterIndex)
{
	return classRosterArray[publicRosterIndex];
}

void Roster::parseThenAdd(string publicDatarow)
{
	if (privateRosterLastIndex < privateRosterCapacity) {
		privateRosterLastIndex++;

		size_t position = 0;

		//get StudentID
		int rhs = publicDatarow.find(",", position);
		string ADDstudentID = publicDatarow.substr(0, rhs);

		//get firtName
		int lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		string ADDfirstName = publicDatarow.substr(lhs, rhs - lhs);

		//get lastName
		lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		string ADDlastName = publicDatarow.substr(lhs, rhs - lhs);

		//get email
		lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		string ADDemail = publicDatarow.substr(lhs, rhs - lhs);

		//get age
		lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		int ADDage = stod(publicDatarow.substr(lhs, rhs - lhs));

		//get daysToComplete[0-4]
		lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		double ADDdaysToComplete0 = stod(publicDatarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		double ADDdaysToComplete1 = stod(publicDatarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		double ADDdaysToComplete2 = stod(publicDatarow.substr(lhs, rhs - lhs));

		//get degreeProgram
		lhs = rhs + 1;
		rhs = publicDatarow.find(",", lhs);
		string ADDdegreeProgram = publicDatarow.substr(lhs, rhs - lhs);

		DegreeProgram degreeProgram;
		if (ADDdegreeProgram == "SECURITY") degreeProgram = SECURITY;
		else if (ADDdegreeProgram == "NETWORK") degreeProgram = NETWORK;
		else if (ADDdegreeProgram == "SOFTWARE") degreeProgram = SOFTWARE;
		else
		{
			cerr << "INVALID DEGREE PROGRAM! EXITING NOW!\n";
			exit(-1);
		}

		add(
			ADDstudentID,
			ADDfirstName,
			ADDlastName,
			ADDemail,
			ADDage,
			ADDdaysToComplete0,
			ADDdaysToComplete1,
			ADDdaysToComplete2,
			degreeProgram);
	}
}

void Roster::add(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	double daysToComplete0,
	double daysToComplete1,
	double daysToComplete2,
	DegreeProgram degreeProgram)
{
	double voidRosterDaysToComplete[Student::daysArraySize];
	voidRosterDaysToComplete[0] = daysToComplete0;
	voidRosterDaysToComplete[1] = daysToComplete1;
	voidRosterDaysToComplete[2] = daysToComplete2;
	classRosterArray[privateRosterLastIndex] = new Student(
		studentID,
		firstName,
		lastName,
		email,
		age,
		voidRosterDaysToComplete,
		degreeProgram);
}

void Roster::print_ALL()
{
	for (int i = 0; i <= privateRosterLastIndex; i++) this->classRosterArray[i]->print();
}

void Roster::remove(string removeStudentID)
{
	bool found = false;
	for (int i = 0; i <= privateRosterLastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == removeStudentID)//Student found
		{
			found = true;
			//delete it
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[privateRosterLastIndex];
			privateRosterLastIndex--;
		}
	}
	if (found == false) cout << "Student with ID A3 was not found.\n" << endl;
}

void Roster::printAverageDaysToComplete(string studentID)
{
	for (int i = 0; i <= privateRosterLastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)//Student found
		{
			double* p = classRosterArray[i]->getDaysToComplete();
			cout << "Student ID " << studentID << ": " << (p[0] + p[1] + p[2]) / 3 << "\n";
		}
	}
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= privateRosterLastIndex; i++)
	{
		any = false;
		size_t position = 0;
		string rosterEmail = classRosterArray[i]->getEmail();
		if (rosterEmail.find('@', position) == string::npos)
		{
			any = true;
			cout << "Student ID " << classRosterArray[i]->getStudentID() << " (" << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ") is missing the '@' symbol: ";
			cout << rosterEmail << ".\n";
		}
		else if (rosterEmail.find('.', position) == string::npos)
		{
			any = true;
			cout << "Student ID " << classRosterArray[i]->getStudentID() << " (" << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ") is missing a period: ";
			cout << rosterEmail << "\n";
		}
		else if (rosterEmail.find(' ', position) != string::npos)
		{
			any = true;
			cout << "Student ID " << classRosterArray[i]->getStudentID() << " (" << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ") has a space in the email: ";
			cout << rosterEmail << "\n";
		}

	}
}

void Roster::printByDegreeProgram(DegreeProgram SOFTWARE)
{
	for (int i = 0; i <= privateRosterLastIndex; i++)
	{
		if (this->classRosterArray[i]->getDegreeProgram() == SOFTWARE) classRosterArray[i]->print();
	}
}

//F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
//5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster(void)//destroys all students
{
	for (int i = 0; i <= privateRosterLastIndex; i++)
	{
		delete this->classRosterArray[i];//Deletes each student
	}
	delete classRosterArray;//Deletes the dynamically allocated array of pointers to the students
}