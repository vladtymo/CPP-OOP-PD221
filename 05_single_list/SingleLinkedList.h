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
	// tail of the list
	Node* tail;
	// size of the list
	int size;

public:
	List() : head(nullptr), tail(nullptr), size(0) { }
	~List()
	{
		Clear();
	}
	
	bool IsEmpty() const { return size == 0; }

	void AddHead(long data)
	{
		// create new item
		Node* item = new Node;
		item->data = data;	// set data
		item->next = head;	// link with next item

		// set tail if the list is empty
		if (IsEmpty()) tail = item;

		// set new item as a head
		head = item;

		// increase size
		++size;
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

		// decrease size
		--size;

		// clear tail the list is empty
		if (IsEmpty()) tail = nullptr;
	}

	void AddTail(long data)
	{
		// create new item
		Node* item = new Node;
		item->data = data;
		item->next = nullptr;

		if (IsEmpty()) 
			head = item; // set head if the list is empty
		else
			tail->next = item; // link new item with the previous

		// set new item as a tail
		tail = item;

		// increase size
		++size;
	}

	long GetFirst() const
	{
		if (IsEmpty()) throw exception("List is empty.");

		return head->data;
	}
	long GetLast() const
	{
		if (IsEmpty()) throw exception("List is empty.");

		return tail->data;
	}
	int GetCount() const
	{
		return size;
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
		head = tail = nullptr;
		size = 0;
	}
};