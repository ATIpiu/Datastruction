#include<iostream>
template<class T>
class MyTree;
template<class T>
class TreeNode {
public:
	T data;
	TreeNode<T>* lefcChild, * rightChild;
	TreeNode(T x=0, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL)
	{
		this->data = x; 
		this->lefcChild = l;
		this->rightChild = r;
	}
};
