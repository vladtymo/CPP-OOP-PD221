#pragma once
#include <initializer_list>
using namespace std;

template <typename T>
class Graph
{
private:
	struct Node
	{
		T data;
		Node** relations;
		int relationsSize;

		Node(T data, Node** relations = nullptr, int size = 0)
			: data(data), relations(relations), relationsSize(size) { }

		void AddRelation(Node* node)
		{
			Node** newArr = new Node * [relationsSize + 1];
			for (size_t i = 0; i < relationsSize; i++)
			{
				newArr[i] = relations[i];
			}
			newArr[relationsSize] = node;
			delete[] relations;
			this->relations = newArr;

			++relationsSize;
		}
	};

	Node* root;
	Node** nodes;
	int size;

	void AddNodePointer(Node* node)
	{
		Node** newArr = new Node*[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = nodes[i];
		}
		newArr[size] = node;
		delete[] nodes;
		this->nodes = newArr;

		++size;
	}
	
	Node* FindNode(const T& value) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (nodes[i]->data == value)
				return nodes[i];
		}

		return nullptr;
	}

public:
	Graph() : root(nullptr), nodes(nullptr), size(0) { }
	// TODO: destructor, copy constructor

	void Add(const T& data, const initializer_list<T> relations)
	{
		Node* item = new Node(data);

		if (root == nullptr) root = item;
		
		for (const T& value : relations)
		{
			Node* relation = FindNode(value);
			if (relation == nullptr) continue;

			item->AddRelation(relation);
			relation->AddRelation(item);
		}
		
		AddNodePointer(item);
	}

	void Show() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << "Node: " << nodes[i]->data << " - ";

			for (size_t k = 0; k < nodes[i]->relationsSize; k++)
			{
				cout << nodes[i]->relations[k]->data << ", ";
			}
			cout << endl;
		}
	}
};
