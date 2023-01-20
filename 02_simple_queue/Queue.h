#pragma once

// A Queue is defined as a linear data structure
// that is open at both ends and the operations 
// are performed in First In First Out (FIFO) order.

class Queue
{
private:
	enum { Empty = -1 };

	long* data;
	const int size;
	int top;

public:
	Queue(int size) : size(size)
	{
		data = new long[size] {};
		top = Empty; // no elements
	}
	~Queue()
	{
		delete[] data;
	}

	void Enqueue(long element); // add new item to the top
	long Dequeue();				// remove the top item
	long Peek();				// get the top item

	void Clear() { top = Empty; }

	bool IsEmpty() const { return top == Empty; }
	bool IsFull() const { return top == size - 1; }
};
