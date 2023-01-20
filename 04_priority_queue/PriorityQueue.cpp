#include "PriorityQueue.h"
#include <exception>
#include <iostream>
using namespace std;

long PriorityQueue::Peek()
{
	if (IsEmpty())
		throw exception("Queue is empty!");

	return data[top].value;
}

void PriorityQueue::Enqueue(long element, int priority)
{
	if (IsFull())
		throw exception("Queue is full!");

	// index to insert the new item
	int index = 0;

	if (!IsEmpty())
	{
		// find position to insert the new item
		for (; index <= top; index++)
		{
			if (data[index].priority >= priority) break;
		}

		// move the existing items
		for (int i = top; i >= index; --i)
		{
			data[i + 1] = data[i];
		}
	}
	
	// insert new item to found position
	data[index] = { element, priority };

	++top;
}

long PriorityQueue::Dequeue()
{
	if (IsEmpty())
		throw exception("Queue is empty!");

	return data[top--].value;
}

void PriorityQueue::Show() const
{
	if (IsEmpty()) return;

	cout << "Queue: ";
	for (size_t i = 0; i <= top; i++)
	{
		cout << data[i].value << "/" << data[i].priority << " ";
	}
	cout << endl;
}