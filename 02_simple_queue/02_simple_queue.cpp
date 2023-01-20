#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue queue(10);

	int id = 1000;
	while (!queue.IsFull())
	{
		queue.Enqueue(id++);
	}

	cout << "Top element: " << queue.Peek() << endl;

	while (!queue.IsEmpty())
	{
		cout << "Next element: " << queue.Dequeue() << endl;
	}

	try
	{
		queue.Clear();
		queue.Dequeue();
	}
	catch (const std::exception& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
}
