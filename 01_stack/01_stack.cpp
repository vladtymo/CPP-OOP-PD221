#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack stack(10);

	while (!stack.IsFull())
	{
		stack.Push(rand() % 100);
	}

	cout << "Top element: " << stack.Peek() << endl;

	while (!stack.IsEmpty())
	{
		cout << "Next element: " << stack.Pop() << endl;
	}

	try
	{
		stack.Clear();
		stack.Pop();
	}
	catch (const std::exception& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
}