//B.Create a C++ project in your integrated development environment(IDE) with the following files :
//•  degree.h
//•  student.hand student.cpp
//•  roster.hand roster.cpp
//•  main.cpp

#pragma once
#include <string>

//C.  Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

static const std::string degreeProgramStrings[] = { "SECURITY","NETWORK","SOFTWARE" };
