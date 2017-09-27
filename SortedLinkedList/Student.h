//File: Student.h
//Author: Jared Adams

#ifndef STUDENT_H
#define STUDENT_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

class Student
{
public:
	Student();
	void setID(int ID);
	void setName(string newName);
	string getName();
	int getID();
	bool operator== (Student);
	bool operator!= (Student);
	bool operator< (Student);
	bool operator> (Student);
	friend ostream& operator << (ostream& os, const Student& stud);
	
private:
	int StudentID;
	string name;
};

#endif /* STUDENT_H */