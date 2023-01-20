#include "Queue.h"
#include <exception>
using namespace std;

long Queue::Peek()
{
	if (IsEmpty())
		throw exception("Queue is empty!");

	return data[0];
}

void Queue::Enqueue(long element)
{
	if (IsFull())
		throw exception("Queue is full!");

	data[++top] = element;	// increment the top element index
							// and set the top element value
}

long Queue::Dequeue()
{
	if (IsEmpty())
		throw exception("Queue is empty!");

	long first = data[0];

	for (size_t i = 0; i < top; i++)
	{
		data[i] = data[i + 1];
	}
	--top;

	return first;
}