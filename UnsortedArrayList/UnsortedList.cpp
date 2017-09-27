//File: UnsortedList.cpp
//Author: Jared Adams

#include <stdexcept>
#include <cstdlib>
#include "UnsortedList.h"

using namespace std;

template<class ItemType>
UnsortedList<ItemType>::UnsortedList()
{
	MAX_ITEMS = 50;
	info = new ItemType[MAX_ITEMS];
	length = 0;
}

template<class ItemType>
UnsortedList<ItemType>::UnsortedList(int size)
{
	MAX_ITEMS = size;
	info = new ItemType[MAX_ITEMS];
	length = 0;
}

template<class ItemType>
bool UnsortedList<ItemType>::isEmpty() const
{
	return (length == 0);
}

template<class ItemType>
bool UnsortedList<ItemType>::isFull() const
{
	return (length == MAX_ITEMS);
}

template<class ItemType>
int UnsortedList<ItemType>::getLength() const
{
	return length;
}

template<class ItemType>
void UnsortedList<ItemType>::putItem(ItemType newItem)
{
	//make sure list isn't full
	if(isFull())
	{
		throw "List is full, insertion failed";
	}
	else
	{
		//make sure item isn't already in the list
		if(findIndex(newItem) == -1)
		{
			info[length] = newItem;
  			length++;
		}
		else
		{
			throw "Item is already in the list, insertion failed";
		}

	}
	
}

template<class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType item)
{

  	if(findIndex(item) == -1)
  	{
  		//std::cerr << "item is not in the list\n";
  		throw "item is not in the list";
  	}
  	else
  	{
  		info[findIndex(item)] = info[length-1];
  		length--;
  	}
 
}

template<class ItemType>
ItemType UnsortedList<ItemType>::get(int index)
{
	if(index < 0 || index >= length)
	{
		//throw index out of bounds exception
		throw "index out of range";
	}
	else
	{
		return info[index];
	}
}

template<class ItemType>
void UnsortedList<ItemType>::makeEmpty()
{
	while(!isEmpty())
	{
		deleteItem(get(0));
	}
}

template<class ItemType>
void UnsortedList<ItemType>::printList(ofstream& out)
{
	for (int i = 0; i < length; ++i)
	{
		out << info[i] << " ";
	}

	out << "\n";
}

template<class ItemType>
UnsortedList<ItemType>::~UnsortedList()
{
	length = 0;
	delete [] info;
}

template<class ItemType>
int UnsortedList<ItemType>::findIndex(ItemType item)
{
	for (int i = 0; i < length; ++i)
	{
		//if item is in the list
		if(item == info[i])
		{
			return i;
		}
	}

	//if item is not in the list
	return -1;
}