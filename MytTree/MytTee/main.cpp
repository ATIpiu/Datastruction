#include<iostream>
#include"MyTree.h"
using namespace std;
int main()
{
	MyTree<int> tree;
	TreeNode<int> *a,*b,*c,*d;
	a = new TreeNode<int>();
	tree.insert(tree.getRoot(),a);
	b = new TreeNode<int>(2);
	tree.insert(tree.getRoot(), b);
	c = new TreeNode<int>(1);
	tree.insert(tree.getRoot(),c);
	d = new TreeNode<int>(3);
	tree.insert(tree.getRoot(), d);
	if (tree.getBrother(a) != nullptr)
	cout << tree.getBrother(b)->data << endl;
}