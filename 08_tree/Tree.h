#pragma once
#include <iostream>
using std::cout;

template <typename T>
class Tree
{
private:
	struct Node
	{
		/*Node* parent;*/
		T data;
		Node* left;
		Node* right;

		Node(T data, Node* l = nullptr, Node* r = nullptr) : data(data), left(l), right(r) { }
	};

	Node* root;

	void Add(const T& value, Node*& root)
	{
		if (root == nullptr)
			root = new Node(value);
		else if (value > root->data)
			Add(value, root->right);
		else if (value < root->data)
			Add(value, root->left);
	}
	void ShowLKP(Node* root) const
	{
		if (root == nullptr) return;
		
		//cout << " ( ";
		ShowLKP(root->left);
		cout << root->data << " ";
		ShowLKP(root->right);
		//cout << " ) ";
	}
	void ShowPKL(Node* root) const
	{
		if (root == nullptr) return;

		//cout << " ( ";
		ShowPKL(root->right);
		cout << root->data << " ";
		ShowPKL(root->left);
		//cout << " ) ";
	}
public:
	Tree() : root(nullptr) { }
	~Tree()
	{
		// 
	}

	bool IsEmpty() const { return root == nullptr; }

	void Add(const T& value)
	{
		this->Add(value, this->root);
	}

	void ShowFromLeft() const
	{
		// [L]eft[K]oren[R]ight
		ShowLKP(this->root);
	}
	void ShowFromRight() const
	{
		// [R]ight[K]oren[L]eft
		ShowPKL(this->root);
	}
};