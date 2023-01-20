#pragma once

// A Circular Queue is a special version of queue
// where the last element of the queue is connected 
// to the first element of the queue forming a circle.
// The operations are performed based on FIFO(First In First Out) principle.
// It is also called 'Ring Buffer'.

class CircularQueue
{
private:
	enum { Empty = -1 };

	long* data;
	const int size;
	int top;

public:
	CircularQueue(int size) : size(size)
	{
		data = new long[size] {};
		top = Empty; // no elements
	}
	~CircularQueue()
	{
		delete[] data;
	}

	void Enqueue(long element); // add new item to the top
	long Dequeue();				// remove the top item and move it to the end
	long Peek();				// get the top item

	void Clear() { top = Empty; }

	bool IsEmpty() const { return top == Empty; }
	bool IsFull() const { return top == size - 1; }
	void Show() const;
};
