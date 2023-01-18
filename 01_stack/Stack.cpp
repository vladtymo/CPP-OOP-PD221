#include "Stack.h"
#include <exception>
using namespace std;

long Stack::Peek()
{
	if (IsEmpty()) 
		throw exception("Stack is empty!");

	return data[top];
}

void Stack::Push(long element)
{
	if (IsFull())
		throw exception("Stack is full!");

	data[++top] = element;	// increment the top element index
							// and set the top element value
}

long Stack::Pop()
{
	if (IsEmpty())
		throw exception("Stack is empty!");

	return data[top--];
}