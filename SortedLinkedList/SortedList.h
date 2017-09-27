//File: SortedList.h
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
struct NodeType;

template<class ItemType>
class SortedList
{
public:
	SortedList();
	SortedList(int size);
	bool isEmpty() const;
	int getLength() const;
	void makeEmpty();
	ItemType get(int index);
	ItemType getNextItem();
	void insertItem(ItemType newItem);
	void deleteItem(ItemType item);
	void printList(ofstream& out);
	~SortedList();

private:
	NodeType<ItemType>* listData, currentPos;
	int length;
	bool findItem (ItemType item);
	
};

#endif /* UNSORTEDLIST_H */