#pragma once
#include"TreeNode.h"
#include<deque>
template<class T>
class MyTree
{
private:
	TreeNode<T> *root;
protected:
	int getNodeNum(TreeNode<int>* temp);
	void inOrder(TreeNode<T>* temp );
	void levelOrde(TreeNode<T>* temp );
	void preOrder(TreeNode<T>* temp );
	void postOrder(TreeNode<T>* temp );
public:
	MyTree(TreeNode<T> *Root=NULL)
	{
		this->root=Root;
	}
	void insert(TreeNode<T> *t,TreeNode<T> *Node);
	void insert(TreeNode<T>* Node) { this->insert(root, Node); }
	TreeNode<T> *getRoot();
	void preOrder() { this->preOrder(root); }
	void inOrder() { this->inOrder(root); }
	void levelOrde() { this->levelOrde(root); }
	void postOrder() { this->postOrder(root); }
	TreeNode<T>* getBrother(TreeNode<T>* temp);
	TreeNode<T>* getFather(TreeNode<T>* temp, TreeNode<T>* Root);
	TreeNode<T>* getFather(TreeNode<T>* temp){		return this->getFather(temp, root);}
	TreeNode<T>* getLeftChild(TreeNode<T>* temp);
	TreeNode<T>* getRightChild(TreeNode<T>* temp);
	int getDegree(TreeNode<T>* temp);
	int getLeavesNodeNum(TreeNode<T>* temp);
	int getNodeNum() { return this->getNodeNum(root); }
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
	return NULL;
}
template<class T>
inline TreeNode<T>* MyTree<T>::getLeftChild(TreeNode<T>* temp)
{
	return temp->lefcChild;
}

template<class T>
inline TreeNode<T>* MyTree<T>::getRightChild(TreeNode<T>* temp)
{
	return temp->rightChild;
}

template<class T>
inline int MyTree<T>::getNodeNum(TreeNode<int>* temp)
{
	int t = 0;
	if (temp != nullptr) {
		t = 1 + getNodeNum(temp->lefcChild);

		t = t + getNodeNum(temp->rightChild);
	}
	return t;

}

template<class T>
inline int MyTree<T>::getDegree(TreeNode<T>* temp)
{
	if (temp == nullptr)
		return -1;
	int degree = 0;
	if (temp->lefcChild != nullptr)
		degree++;
	if (temp->rightChild != nullptr)
		degree++;
	return degree;
}
template<class T>
inline int MyTree<T>::getLeavesNodeNum(TreeNode<T>* temp)
{
	int t = 0;
	if (temp != nullptr) {
		if (getDegree(temp) == 0)
			t += 1;
		t = t + getLeavesNodeNum(temp->lefcChild);
		t = t + getLeavesNodeNum(temp->rightChild);
	}
	return t;
}