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
	//int A[1000], i, j;                       //��������ͱ�������
	//srand((unsigned)time(NULL));           //����ϵͳʱ��Ϊ�������
	//for (i = 0; i < 1000; i++)                    //����10�������
	//{
	//	A[i] = 1 + rand() % 1000;                //�õ������(��Χ��1-10֮��)
	//	for (j = 0; j < i; j++)              //�жϺ�ǰ������Ƿ��ظ�
	//		if (A[i] == A[j]) 
	//		{
	//			i--; break; 
	//		}  //����ظ�,���²��������
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
