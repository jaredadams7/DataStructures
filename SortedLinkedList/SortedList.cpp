//File: SortedList.cpp
//Author: Jared Adams

#include <stdexcept>
#include <cstdlib>

#include "SortedList.h"

using namespace std;

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType>* next;
};

template<class ItemType>
SortedList<ItemType>::SortedList()
{
	length = 0;
	listData = NULL;
}

template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
	return (length == 0);
}

template<class ItemType>
int SortedList<ItemType>::getLength() const
{
	return length;
}

template<class ItemType>
void SortedList<ItemType>::makeEmpty()
// Post: List is empty; all items have been deallocated.
{
	NodeType<ItemType>* tempPtr;

	while (listData != NULL)
	{
	tempPtr = listData;
	listData = listData->next;
	delete tempPtr;
	}

  	length = 0;
}

template<class ItemType>
ItemType SortedList<ItemType>::get(int index)
{
	if(index < 1 || index > length)
	{
		throw("out of range exception");
	}
	else
	{
		NodeType<ItemType> * location;
		location = listData;
		int position = 1;

		while(position < index)
		{
			location = location->next;
			position++;
		}

		return location->info;
	}
}

template<class ItemType>
ItemType SortedList<ItemType>::getNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
  ItemType item;
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
  return item;
}

template<class ItemType>
void SortedList<ItemType>::insertItem(ItemType newItem)
{
	NodeType<ItemType>* newNode;  // pointer to node being inserted
	NodeType<ItemType>* predLoc;  // trailing pointer
	NodeType<ItemType>* location; // traveling pointer
	location = listData;
	predLoc= NULL;

	// Find insertion point.
	while (location != NULL)  
	{
		if(newItem > location->info)      // operator > and < must me overloaded for any ItemTypeobject
		{           
			predLoc= location;
			location = location->next;
		}
		else if( newItem < location->info)
			break;
	}

	// Prepare node for insertion
	newNode= new NodeType<ItemType>;
	newNode->info = newItem;

	// Insert node into list.
	if(predLoc== NULL)  // Insert as first
	{      
		newNode->next = listData;
		listData= newNode;
	}
	else 
	{
		newNode->next = location;
		predLoc->next = newNode;
	}

	length++;

}

template<class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item)
{
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* predLoc= NULL;
	NodeType<ItemType>* predecessor;

	// Locate node to be deleted.
	// check if item exists in the first node
	if(findItem(item))
	{
		if(item == listData->info) 
		{
			listData = listData->next; // Delete first node.
		}
		else
		{
			while(item != (location->info))
			{ 
				predLoc = location;
				location = location->next;
			}

			// Delete node at location->next
			predLoc->next = location->next;
		}

		length--;
	}

	delete location; // deallocate the node
	
}

template<class ItemType>
void SortedList<ItemType>::printList(ofstream& out)
{
	NodeType<ItemType>* location;
	location = listData;

	for (int i = 0; i < length; ++i)
	{
		out << location->info << " ";
		location = location->next;
	}

	out << "\n";

	delete location;
}

template<class ItemType>
bool SortedList<ItemType>::findItem (ItemType item)
{
	NodeType<ItemType> * location = listData;

	for (int i = 0; i < length; ++i)
	{
		if(location->info == item)
		{
			return true;
		}
		else if(location->info != item && i == length-1)
		{
			throw "item is not in the list";
			return false;
		}
		else
		{
			location = location->next;
		}
	}

	delete location;
	return false;
}

template<class ItemType>
SortedList<ItemType>::~SortedList()
// Post: List is empty; all items have been deallocated.
{
	NodeType<ItemType>* tempPtr;

	while (listData != NULL)
	{
	tempPtr = listData;
	listData = listData->next;
	delete tempPtr;
	}
}