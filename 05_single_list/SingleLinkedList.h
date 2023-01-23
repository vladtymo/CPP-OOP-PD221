#pragma once
#include <iostream>
using namespace std;

class List
{
private:
	struct Node
	{
		long data;
		Node* next;
	};

	// head of the list
	Node* head;

public:
	List() : head(nullptr) { }
	~List()
	{
		Clear();
	}
	
	bool IsEmpty() const { return head == nullptr; }

	void AddHead(long data)
	{
		// create new item
		Node* item = new Node;
		item->data = data;
		item->next = head;

		// set new item as a head
		head = item;
	}
	void DeleteHead()
	{
		if (IsEmpty()) return;

		// save current head
		Node* temp = head;

		// set new head
		head = head->next;

		// delete previous head item
		delete temp;
	}

	long GetFirst() const
	{
		if (IsEmpty()) throw exception("List is empty.");

		return head->data;
	}

	void Show() const
	{
		// using while cycle
		/*Node* item = head;
		while (item != nullptr)
		{
			cout << item->data << " ";
			item = item->next;
		}*/

		// using for
		for (Node* i = head; i != nullptr; i = i->next)
		{
			cout << i->data << " ";
		}
		cout << endl;
	}

	void Clear()
	{
		Node* item = head;
		while (item != nullptr)
		{
			Node* next = item->next;
			delete item;
			item = next;
		}
		head = nullptr;
	}
};