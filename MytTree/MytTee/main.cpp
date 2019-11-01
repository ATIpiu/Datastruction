#include<iostream>
#include"MyTree.h"
using namespace std;
int main()
{
	MyTree<int> tree;
	TreeNode<int> *a,*b,*c,*d,*e;
	a = new TreeNode<int>();
	tree.insert(a);
	b = new TreeNode<int>(2);
	tree.insert( b);
	c = new TreeNode<int>(1);
	tree.insert(c);
	d = new TreeNode<int>(3);
	tree.insert(d);
	e = new TreeNode<int>(4);
	tree.insert(e);
	/*if (tree.getBrother(a) != nullptr)
	cout << tree.getBrother(b)->data << endl;*/
	cout << tree.getLeavesNodeNum(tree.getRoot()) << endl;
	cout << tree.getHeight() << endl;
}