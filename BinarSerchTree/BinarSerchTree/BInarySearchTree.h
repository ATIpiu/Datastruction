#pragma once
#include<iostream>

template<class T>
class TreeNode {
public:
	T data;
	TreeNode<T>* lefcChild, * rightChild;
	TreeNode(T x = 0, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL)
	{
		this->data = x;
		this->lefcChild = l;
		this->rightChild = r;
	}
};

template<class T>
class BInarySearchTree
{
private:
	TreeNode<T>* root;
public:
	BInarySearchTree(TreeNode<T>* Root = NULL)
	{
		this->root = Root;
	}
	void inOrder() { this->inOrder(root); }
	void inOrder(TreeNode<T>* temp);
	void insert(TreeNode<T>* t, TreeNode<T>* Node);
	void insert(TreeNode<T>* Node) { this->insert(root, Node); }
	void drop(TreeNode<T>* temp);
	TreeNode<T>* getFather(TreeNode<T>* temp, TreeNode<T>* Root);
	TreeNode<T>* FindMax(TreeNode<T>* temp);
	void swap(TreeNode<T>* a, TreeNode<T>* b);
}; 

template<class T>
void BInarySearchTree<T>::inOrder(TreeNode<T>* temp)
{
	if (temp != nullptr) {
		inOrder(temp->lefcChild);
		std::cout << temp->data << " ";
		inOrder(temp->rightChild);
	}
}

template<class T>
inline void	BInarySearchTree<T>::insert(TreeNode<T>* t, TreeNode<T>* Node)
{
	if (root == NULL)
	{
		root = Node;
		return;
	}
	if (Node == nullptr)
		return;
	if (Node->data < t->data)
	{
		if (t->lefcChild == NULL)
		{
			t->lefcChild = Node;
		}
		else
		{
			insert(t->lefcChild, Node);
		}
	}
	else
	{
		if (t->rightChild == NULL)
		{
			t->rightChild = Node;
		}
		else
		{
			insert(t->rightChild, Node);
		}
	}
}

template<class T>
inline void BInarySearchTree<T>::drop(TreeNode<T>* temp)
{
	if (temp == nullptr)
	{
		return;
	}
	if (temp->lefcChild = nullptr && temp->rightChild != nullptr)
	{
		this->swap(temp, temp->rightChild);
		delete temp;
	}
	else if (temp->rightChild == nullptr && temp->lefcChild != nullptr)
	{
		TreeNode<T> *maxson = this->FindMax(temp->lefcChild);
		this->swap(temp, maxson);
		delete temp;
		this->drop(maxson);
	}
	else {
		TreeNode<T>* a = this->getFather(temp,this->root);
		if (a->lefcChild == temp)
			a->lefcChild = nullptr;
		else if (a->rightChild == temp)
			a->rightChild = nullptr;
		delete temp;
	}
}

template<class T>
inline TreeNode<T>* BInarySearchTree<T>::getFather(TreeNode<T>* temp, TreeNode<T>* Root)
{
	if (Root != nullptr)
	{
		if (temp == root)
		{
			std::cout << "this Node is RootNode" << std::endl;
			return NULL;
		}
		if (Root->lefcChild == temp || Root->rightChild == temp)
			return Root;
		this->getFather(temp, Root->lefcChild);
		this->getFather(temp, Root->rightChild);
	}
}

template<class T>
inline TreeNode<T>* BInarySearchTree<T>::FindMax(TreeNode<T>* temp)
{
	if (temp == nullptr) return nullptr;
	if (temp->rightChild != nullptr)
		return FindMax(temp->rightChild);
	if (temp->rightChild == nullptr)
		return temp;
}

template<class T>
inline void BInarySearchTree<T>::swap(TreeNode<T>* a, TreeNode<T>* b)
{
	TreeNode<T>* a_father = this->getFather(a, this->root);
	b->lefcChild = a->lefcChild;
	b->rightChild = a->rightChild;
	if (a_father->lefcChild == a)
	{
		a_father->lefcChild = b;
	}
	else if (a->rightChild == a)
	{
		a_father->rightChild == b;
	}

}
