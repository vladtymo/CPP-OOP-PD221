#include "CircularQueue.h"
#include <exception>
#include <iostream>
using namespace std;

long CircularQueue::Peek()
{
	if (IsEmpty())
		throw exception("Queue is empty!");

	return data[0];
}

void CircularQueue::Enqueue(long element)
{
	if (IsFull())
		throw exception("Queue is full!");

	data[++top] = element;	// increment the top element index
							// and set the top element value
}

long CircularQueue::Dequeue()
{
	if (IsEmpty())
		throw exception("Queue is empty!");

	long first = data[0];

	for (size_t i = 0; i < top; i++)
	{
		data[i] = data[i + 1];
	}

	// move the first item to the end
	data[top] = first;

	return first;
}

void CircularQueue::Show() const
{
	cout << "Queue: ";
	for (size_t i = 0; i <= top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}