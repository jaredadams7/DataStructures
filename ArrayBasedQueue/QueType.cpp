//File: OneType.cpp
//Author: Jared Adams

#include <stdexcept>
#include <cstdlib>
#include "QueType.h"

using namespace std;

int length;

template<class ItemType>
QueType<ItemType>::QueType()
{
	maxQue = 500;
	items = new ItemType[maxQue];
	length = 0;
	front = rear = maxQue - 1; //when queue is empty, front = rear
}

template<class ItemType>
QueType<ItemType>::QueType(int max)
{
	maxQue = max;
	items = new ItemType[maxQue];
	length = 0;
	front = rear = maxQue - 1; //when queue is empty, front = rear
}

template<class ItemType>
void QueType<ItemType>::MakeEmpty()
{
	items = new ItemType[maxQue];
	length = 0;
	front = rear = maxQue - 1; //when queue is empty, front = rear

}

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
	return (front == rear); //when queue is empty, front = rear
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const
{
	return (rear+1 == front); //queue is full when rear+1 = front
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
	if(IsFull())
	{
		throw FullQueue();
	}
	else
	{
		if(rear == maxQue)
		{
			rear = 0;
		}
		else
		{
			rear++;
		}

		items[rear] = newItem;
		length++;
	}
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
	// Function: Removes front item from the queue and returns it   
    //in item.
    if(IsEmpty())
    {
    	throw EmptyQueue();
    }
    else
    {
    	if(front == maxQue)
		{
			front = 0;
			item = items[front];

		}
		else
		{
			front++;
			item = items[front];
		}
  
    	length--;
    }
}

template<class ItemType>
int QueType<ItemType>::Length()
{
	return length;
}

template<class ItemType>
QueType<ItemType>::~QueType()
{
	delete [] items;
}