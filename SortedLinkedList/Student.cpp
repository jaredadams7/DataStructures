//File: Student.cpp
//Author: Jared Adams

#include <cstdlib>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student() //default constructor
{
	StudentID = 0;
	name = "";
}

void Student::setID(int ID)
{
	StudentID = ID;
}

void Student::setName(string newName)
{
	name = newName;
}

int Student::getID()
{
	return StudentID;
}

string Student::getName()
{
	return name;
}

bool Student::operator== (Student stu)
{
	return(StudentID == stu.getID());
}

bool Student::operator!= (Student stu)
{
	return(StudentID != stu.getID());
}

bool Student::operator< (Student stu)
{
	return(StudentID < stu.getID());
}

bool Student::operator> (Student stu)
{
	return(StudentID > stu.getID());
}

ostream& operator<< (ostream & os, const Student & stud)
{
	os << stud.StudentID << " " << stud.name;
	return os;
}
