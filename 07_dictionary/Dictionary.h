#pragma once
#include <iostream>
using namespace std;

// Associative Containers - contain elements without any specific order

template <typename TKey, typename TValue>
class Dictionary
{
	struct Node
	{
		TValue value;
		TKey key;

		Node() { }
		Node(TKey key, TValue value) : key(key), value(value) { }
	};

	Node* data;
	int size;

public:
	Dictionary() : size(0), data(nullptr) { }
	~Dictionary()
	{
		delete[] data;
	}

	TValue& Get(const TKey& key) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i].key == key) 
				return data[i].value;
		}
		throw exception("Key does not exist!");
	}
	TValue& operator[](const TKey& key) const
	{
		return this->Get(key);
	}

	bool IsEmpty() const { return size == 0; }
	void Add(const TKey& key, const TValue& value)
	{
		Node* newArr = new Node[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = data[i];
		}
		newArr[size] = Node(key, value);
		delete[] data;
		data = newArr;

		++size;
	}

	bool ContainsKey(const TKey& key) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i].key == key) return true;
		}
		return false;
	}
	bool ContainsValue(const TValue& value) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i].value == value) return true;
		}
		return false;
	}

	void Show() const
	{
		if (IsEmpty()) cout << "Collection is empty!";
		else
		{
			for (size_t i = 0; i < size; i++)
			{
				cout << data[i].key << ": " << data[i].value << endl;
			}
		}
	}
};