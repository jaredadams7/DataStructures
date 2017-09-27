// Test driver
#include <iostream>
#include <fstream>
#include <string>

#include "QueType.cpp"

using namespace std;

int main()
{

	ofstream outFile;
     ifstream  inFile;
	string command;
	outFile.open("output.txt");
     inFile.open("QueType.in");
	if(!outFile)
	{
		std::cout << "error openning output file" << endl;
		return 1;
	}
  int item;
  QueType<int> queue(5);
  int numCommands=0;
  std::cout << "number of items in the queue is: " << queue.Length() << endl;
 
  while (true)
  {
	  inFile >> command;

    try 
   {
		if (command == "Enqueue")
		{
			inFile >> item;
			queue.Enqueue(item);
			outFile << item << " is enqueued." << endl;
		}
		else if (command == "Dequeue")
		{
			queue.Dequeue(item);
			outFile << item << " is dequeued. " << endl;
		}
		else if (command == "IsEmpty")
			if (queue.IsEmpty())
				outFile << "Queue is empty." << endl;
			else
				outFile << "Queue is not empty." << endl;

		else if (command == "IsFull")
			if (queue.IsFull())
				outFile << "Queue is full." << endl;
			else outFile << "Queue is not full." << endl;
		else if (command == "Length")
			outFile << "Number of items in the Queue is: " << queue.Length() << endl;
		else
			if (command == "Quit")
				break;
		else outFile << command << " not found" << endl;
    }//try
  catch (FullQueue)
   {
    outFile << "FullQueue exception thrown." << endl;
   }
    
    catch (EmptyQueue)
   {
     outFile << "EmtpyQueue exception thrown." << endl;
    } 
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
  }//while
 
  cout << "Testing completed."  << endl;
  outFile.close();
  return 0;
}


