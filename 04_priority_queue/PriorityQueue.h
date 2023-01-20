#pragma once

// Priority queue is an abstract data-type similar to a regular queue or stack data structure.

class PriorityQueue
{
private:
	enum { Empty = -1 };
	struct Node
	{
		long value;
		int priority;
	};

	Node* data;
	const int size;
	int top;

public:
	PriorityQueue(int size) : size(size)
	{
		data = new Node[size];
		top = Empty; // no elements
	}
	~PriorityQueue()
	{
		delete[] data;
	}

	void Enqueue(long element, int priority); // add new item to the top
	long Dequeue();				// remove the item with the highest priority value
	long Peek();				// get the item with the highest priority value

	void Clear() { top = Empty; }

	bool IsEmpty() const { return top == Empty; }
	bool IsFull() const { return top == size - 1; }
	void Show() const;
};
