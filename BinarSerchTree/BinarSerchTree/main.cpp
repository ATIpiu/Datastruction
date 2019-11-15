#include<iostream>
#include"BInarySearchTree.h"
using namespace std;
int main()
{
	BInarySearchTree<int> bin;
	TreeNode<int>* a, * b, * c, * d, * e, * f;
	a = new TreeNode<int>(9);
	bin.insert(a);
	b = new TreeNode<int>(10);
	bin.insert(b);
	c = new TreeNode<int>(7);
	bin.insert(c); 
	d = new TreeNode<int>(36);
	bin.insert(d); 
	e= new TreeNode<int>(23);
	bin.insert(e);
	f = new TreeNode<int>(40);
	bin.insert(f);
	bin.drop(f);
	bin.inOrder();
	std::cout << bin.FindMax(a)->data << endl;
}