#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	PriorityQueue queue(10);

	queue.Enqueue(1, 8);
	queue.Enqueue(2, 3);
	queue.Enqueue(3, 5);
	queue.Enqueue(4, 1);
	queue.Enqueue(5, 1);
	queue.Enqueue(6, 12);
	queue.Enqueue(7, 3);
	queue.Enqueue(8, 2);

	cout << "Top element: " << queue.Peek() << endl;

	while(!queue.IsEmpty())
	{
		system("cls");
		queue.Show();
		cout << "Next element: " << queue.Dequeue() << endl;
		cin.get();
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