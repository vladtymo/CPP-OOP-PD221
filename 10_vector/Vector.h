#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:
	T* collection;
	int size;		// count of initialized elements

	const int growthKoef;
	int capacity;	// count of all allocated elements

	void IncreaseCapacity()
	{
		if (capacity == 0)
			capacity = 1;
		else
			capacity *= growthKoef;
	}

public:
	Vector() : collection(nullptr), size(0), growthKoef(2), capacity(0) { }
	~Vector()
	{
		delete[] collection;
	}

	int GetCapacity() const { return capacity; }
	int GetSize() const { return size; }
	bool IsFullCapacity() const
	{
		return size == capacity;
	}

	void ShrinkToFit()
	{
		if (IsFullCapacity()) return;

		T* newArr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = collection[i];
		}
		delete[] collection;
		collection = newArr;

		capacity = size;
	}

	void Clear()
	{
		if (collection != nullptr)
		{
			delete[] collection;
			collection = nullptr;
		}
		size = capacity = 0;
	}
	void Push(const T& value)
	{
		this->Insert(value, size);
	}
	void Unshift(const T& value)
	{
		this->Insert(value, 0);
	}

	// [4, 6, 2, 7, 2, 6]
	// insert value: 8 at pos: 3
	// [4, 6, 2, [8], 7, 2, 6]
	void Insert(const T& value, int position = 0)
	{
		if (IsFullCapacity())
		{
			IncreaseCapacity();
			T* newArr = new T[capacity];

			for (size_t i = 0; i < position; i++)
			{
				newArr[i] = collection[i];
			}

			newArr[position] = value;

			for (size_t i = position; i < size; i++)
			{
				newArr[i + 1] = collection[i];
			}

			delete[] collection;
			collection = newArr;
		}
		else
		{
			// without [new] and [delete] operations
			for (size_t i = size; i > position; i--)
			{
				collection[i] = collection[i - 1];
			}
			collection[position] = value;
		}

		++size;
	}

	void Show(string title = "") const
	{
		if (!title.empty())
			cout << title << ": ";

		for (size_t i = 0; i < size; i++)
			cout << collection[i] << " ";

		cout << endl;
	}
};
