//File: UnsortedListDr.cpp
//Author: Jared Adams

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include "SortedList.h"
#include "SortedList.cpp"
#include "Student.h"
#include "Student.cpp"

using namespace std;
void testIntegersList();
void testCharactersList();
void testStudentsList();

int main(int argc, char const *argv[])
{
	//read commands and data from input file inFile until "Quit" command is read
	//Writes output to output file outFile.txt
	int datatype;
	// Prompt user to enter type of elements 
	cout << "Enter Elements Type\n1 for integer\n2 for character\n3 for Student\n";
	cin >> datatype;
	switch (datatype)
	{ case 1: testIntegersList();
	          break;
	  case 2: testCharactersList();
	           break;
	  case 3: testStudentsList();
	          break;
	}

	return 0;
}

void testIntegersList()
{
	SortedList<int> list;
	string command;
	int number;
	ifstream inFile;
	ofstream outFile;
	inFile.open("intcommands.txt");
	outFile.open("outFile.txt");
	inFile>> command; // read commands from a text file
	while (command != "Quit")
	{ 
		if (command == "isEmpty")
        {
	    	if(list.isEmpty())
	        	outFile << "list is empty\n";
	      	else
	        	outFile << "list is not empty\n";
        }
	 	else if (command == "insertItem")
	 	{ 
        	inFile>> number;
        	try
        	{
        		list.insertItem(number);
        		outFile << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}
        }
        else if (command == "deleteItem")
        {
        	inFile >> number;
        	try
        	{
        		list.deleteItem(number);
        		outFile << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}
        }
        else if (command == "get")
        {
        	inFile >> number;
        	try
        	{
        		outFile << list.get(number) << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}

        }
        else if (command == "makeEmpty")
        {
        	list.makeEmpty();
        	outFile << "\n";
        }
        else if (command == "printList")
        {
        	list.printList(outFile);
        }
        else if (command == "getLength")
        {
        	outFile << list.getLength() << endl;
        }
        else
        {
        	outFile << "undefined command\n";
        }
		inFile>> command;
	} // while

	inFile.close();
	outFile.close();

} //testIntegersList()

void testCharactersList()
{
	SortedList<char> list;
	string command;
	char character;
	int number;
	ifstream inFile;
	ofstream outFile;
	inFile.open("chcommands.txt");
	outFile.open("outFile.txt");
	inFile>> command; // read commands from a text file
	while (command != "Quit")
	{ 
		if (command == "isEmpty")
	    	if( list.isEmpty())
	        	outFile << "list is empty\n";
	      	else
	        	outFile << "list is not empty\n";
	 	else if (command == "insertItem")
	 	{ 
        	inFile>> character;
        	try
        	{
        		list.insertItem(character);
        		outFile << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}
        }
        else if (command == "deleteItem")
        {
        	inFile >> character;
        	try
        	{
        		list.deleteItem(character);
        		outFile << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}

        }
        else if (command == "get")
        {
        	inFile >> number;
        	try
        	{
        		outFile << list.get(number) << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}

        }
        else if (command == "makeEmpty")
        {
        	list.makeEmpty();
        	outFile << "\n";
        }
        else if (command == "printList")
        {
        	list.printList(outFile);
        }
        else if (command == "getLength")
        {
        	outFile << list.getLength() << endl;
        }
        else
        {
        	outFile << "undefined command\n";
        }
		inFile>> command;
	} // while

	inFile.close();
	outFile.close();
} //testCharactersList()

void testStudentsList()
{
	SortedList<Student> list;
	ifstream inFile;
	ofstream outFile;
	string command, name;
	int ID;
	int number;

	inFile.open("studcommands.txt");
	outFile.open("outFile.txt");
	inFile>> command; // read commands from a text file
	Student StudentObj;
	while (command != "Quit")
	{ 
		if (command == "isEmpty")
		{
    	  	if(list.isEmpty())
    	  	{
	         	outFile << "list is empty\n";
    	  	}
	      	else
	      	{
	         	outFile << "list is not empty\n";
	      	}
	    }
	 	else if (command ==  "insertItem")
     	{ 
            inFile>> ID>>name;
            StudentObj.setID(ID);
            StudentObj.setName(name);
            try
        	{
        		list.insertItem(StudentObj);
        		outFile << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}
     	}
        else if (command == "deleteItem")
        {
        	int newID;
        	inFile >> newID;
        	StudentObj.setID(newID);

        	try
        	{
        		list.deleteItem(StudentObj);
        		outFile << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}

        }
        else if (command == "get")
        {
        	inFile >> number;
        	try
        	{
        		outFile << list.get(number) << "\n";
        	} catch (const char* msg) {
        		outFile << msg << endl;
        	}

        }
        else if (command == "makeEmpty")
        {
        	list.makeEmpty();
        	outFile << "\n";
        }
        else if (command == "printList")
        {
        	list.printList(outFile);
        }
        else if (command == "getLength")
        {
        	outFile << list.getLength() << endl;
        }
        else
        {
        	outFile << "undefined command\n";
        }
		inFile>> command;
	}//end while

	inFile.close();
	outFile.close();
} //testStudentsList()
