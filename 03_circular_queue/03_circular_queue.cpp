#include <iostream>
#include "CircularQueue.h"
using namespace std;

int main()
{
	CircularQueue queue(10);

	int id = 1;
	while (!queue.IsFull())
	{
		queue.Enqueue(id++);
	}

	cout << "Top element: " << queue.Peek() << endl;

	for (size_t i = 0; i < 20; i++)
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