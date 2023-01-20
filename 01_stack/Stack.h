#pragma once

// Stack is a linear data structure that follows the LIFO (Last-In-First-Out) principle.

class Stack
{
private:
	enum { Empty = -1 };

	long* data;
	const int size;
	int top;

public:
	Stack(int size) : size(size)
	{
		data = new long[size] {};
		top = Empty; // no elements
	}
	~Stack()
	{
		delete[] data;
	}

	void Push(long element); // add new item to the top
	long Pop();				 // remove the top item
	long Peek();			 // get the top item
	
	void Clear() { top = Empty; }

	bool IsEmpty() const { return top == Empty; }
	bool IsFull() const { return top == size - 1; }
};
