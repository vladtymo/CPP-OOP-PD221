#pragma once
#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T data;		// value of the item
		Node* next;	// pointer to the next item 
		Node* prev; // pointer to the previous item

		Node(T data, Node* next = nullptr, Node* prev = nullptr)
			: data(data), next(next), prev(prev) { }
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

	// List (push front item):	X<[new]>-<[1]><[2]><[3]><[4]>X
	void AddHead(T data)
	{
		// create new item
		Node* item = new Node(data, head);
		//item->data = data;	// set data
		//item->next = head;	// link with next item
		//item->prev = nullptr; // no previous item

		// set tail if the list is empty
		if (IsEmpty()) tail = item;
		else head->prev = item;

		// set new item as a head
		head = item;

		// increase size
		++size;
	}

	// List (pop front item):	X<[old]> X<[2]><[3]><[4]>X
	void DeleteHead()
	{
		if (IsEmpty()) return;

		// save current head
		Node* temp = head;

		// set new head
		head = head->next;

		// delete old head item
		delete temp;

		// decrease size
		--size;

		// clear tail the list is empty
		if (IsEmpty()) tail = nullptr;
		// remove link with the previous item
		else head->prev = nullptr;
	}

	// List (push back item):	X<[1]><[2]><[3]><[4]>-<[new]>X
	void AddTail(T data)
	{
		// create new item
		Node* item = new Node(data, nullptr, tail);
		/*item->data = data;
		item->next = nullptr;
		item->prev = tail;*/

		if (IsEmpty())
			head = item; // set head if the list is empty
		else
			tail->next = item; // link new item with the previous

		// set new item as a tail
		tail = item;

		// increase size
		++size;
	}

	// List (pop front item):	X<[1]><[2]><[3]><[4]>X <[old]>X
	void DeleteTail()
	{
		if (IsEmpty()) return;

		// save current tail
		Node* temp = tail;

		// set new head
		tail = tail->prev;

		// delete old tail item
		delete temp;

		// decrease size
		--size;

		// clear tail the list is empty
		if (IsEmpty()) head = nullptr;
		// remove link with the previous item
		else tail->next = nullptr;
	}

	// List (insert item):		X<[1]><[2]>-<[new]>-<[3]><[4]>X
	void InsertItem(T data, int index)
	{
		if (index < 0 || index > size) throw out_of_range("Index is out of the range!");
		if (index == 0) { AddHead(data); return; }
		if (index == size) { AddTail(data); return; }

		// find item by index
		Node* current = head;
		for (int i = 0; i < index; ++i)
		{
			current = current->next;
		}

		// create new item
		Node* item = new Node(data, current, current->prev);
		/*item->data = data;
		item->next = current;
		item->prev = current->prev;*/

		// link previous item with the new item
		current->prev->next = item;

		// link current item with the new item
		current->prev = item;

		// increase size
		++size;
	}

	// TODO: Reverse()
	//*TODO: DeleteItem(int index)

	T GetFirst() const
	{
		if (IsEmpty()) throw exception("List is empty.");

		return head->data;
	}
	T GetLast() const
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