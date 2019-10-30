#pragma once
#include"TreeNode.h"
#include<deque>
template<class T>
class MyTree
{
private:
	TreeNode<T> *root;
public:
	MyTree(TreeNode<T> *Root=NULL)
	{
		this->root=Root;
	}
	void insert(TreeNode<T> *t,TreeNode<T> *Node);
	TreeNode<T> *getRoot();
	void preOrder(TreeNode<T>* temp = root);
	void inOrder(TreeNode<T>* temp = root);
	void levelOrde(TreeNode<T>* temp = root);
	void postOrder(TreeNode<T>* temp = root);
	TreeNode<T>* getBrother(TreeNode<T>* temp);
	TreeNode<T>* getFather(TreeNode<T>* temp, TreeNode<T>* Root);
};
template<class T>
inline void MyTree<T>::insert(TreeNode<T>* t, TreeNode<T>* Node)
{
	if (root == NULL)
	{
		root = Node;
		return;
	}
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
inline TreeNode<T>* MyTree<T>::getRoot()
{
	return this->root;
}

template<class T>
inline void MyTree<T>::preOrder(TreeNode<T>* temp)
{
	if (temp != nullptr) {		
		preOrder(temp->lefcChild);
		std::cout << temp->data << " ";
		preOrder(temp->rightChild);
	}
}

template<class T>
inline void MyTree<T>::inOrder(TreeNode<T>* temp)
{
	if (temp != nullptr) {
		std::cout << temp->data << " ";
		preOrder(temp->lefcChild);
		preOrder(temp->rightChild);
	}
}

template<class T>
inline void MyTree<T>::levelOrde(TreeNode<T>* temp)	
{
	std::deque<TreeNode<T>*> deq;
	if (temp != nullptr)
	{
		deq.push_back(temp);
	}
	while (deq.empty() != true)
	{
		TreeNode<T>* t;
		t = deq.front();
		deq.pop_front();
		std::cout << t->data << " ";
		if (t->lefcChild != nullptr) deq.push_back(t->lefcChild);
		if (t->rightChild != nullptr) deq.push_back(t->rightChild);
	}
}

template<class T>
inline void MyTree<T>::postOrder(TreeNode<T>* temp)
{
	if (temp != nullptr) {
		preOrder(temp->lefcChild);		
		preOrder(temp->rightChild);
		std::cout << temp->data << " ";
	}
}

template<class T>
inline TreeNode<T>* MyTree<T>::getBrother(TreeNode<T>* temp)
{
	TreeNode<T>* father;
	if (temp == root)
	{
		std::cout << "this node is RootNode" << std::endl;
		return nullptr;
	}
	if (temp != nullptr)
	{
		father = this->getFather(temp, root);
		if (father->lefcChild == temp)
		{
			if (father->rightChild != nullptr)
				return father->rightChild;
			else
			{
				std::cout << "the Node has no Brother" << std::endl;
				return NULL;
			}
		}
		if (father->rightChild = temp)
		{
			if (father->lefcChild != nullptr)
				return father->lefcChild;
			else
			{
				std::cout << "the Node has no Brother" << std::endl;
					return NULL;
			}
		}
	}
	return NULL;
}

template<class T>
inline TreeNode<T>* MyTree<T>::getFather(TreeNode<T>* temp, TreeNode<T>*Root)
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

