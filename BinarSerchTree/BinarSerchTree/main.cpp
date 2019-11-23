#include<iostream>
#include"BInarySearchTree.h"
#include<time.h>
using namespace std;
void biSerach(int x)
{
	int a[1000];
	for (int i = 0; i < 1000; i++)
	{
		a[i] = i;
	}
	int low = 0, high = 999;
	while (true)
	{
		if (x == a[(low + high) / 2])
		{
			cout << a[(low + high) / 2];
			break;
		}
		if (x > a[(low + high) / 2])
		{
			low = (low + high) / 2;
		}
		if (x < a[(low + high) / 2])
		{
			high = (low + high) / 2;
		}
	}
}
int main()
{
	//BInarySearchTree<int> bin;
	//int A[1000], i, j;                       //整型数组和变量声明
	//srand((unsigned)time(NULL));           //设置系统时间为随机种子
	//for (i = 0; i < 1000; i++)                    //产生10个随机数
	//{
	//	A[i] = 1 + rand() % 1000;                //得到随机数(范围在1-10之间)
	//	for (j = 0; j < i; j++)              //判断和前面的数是否重复
	//		if (A[i] == A[j]) 
	//		{
	//			i--; break; 
	//		}  //如果重复,重新产生随机数
	//}
	//for (int j = 0; j < 1000; j++)
	//{
	//	TreeNode<int> *a=new TreeNode<int>(A[j]);
	//	bin.insert(a);
	//}
	//bin.inOrder();
	//TreeNode<int>* b = bin.findElement(199,bin.getRoot());
	//cout << b->data << endl;
	biSerach(199);
}
