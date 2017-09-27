//File: UnsortedList.h
//Author: Jared Adams

#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

template<class ItemType>
class UnsortedList
{
public:
	UnsortedList();
	UnsortedList(int size);
 	bool isEmpty() const;
 	bool isFull() const;
 	int getLength() const;
 	void putItem(ItemType newItem);
 	void deleteItem(ItemType item);
 	ItemType get(int index);
 	void makeEmpty();
 	void printList(ofstream& out);
 	~UnsortedList();
	
private:
	int MAX_ITEMS, length;
	ItemType * info;
	int findIndex(ItemType item);
};


#endif /* UNSORTEDLIST_H */