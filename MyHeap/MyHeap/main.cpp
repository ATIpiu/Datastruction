#include<iostream>
#include"MyHeap.h"
#include<stdlib.h>
#include <time.h>
using namespace std;
int  main()
{
	MyHeap a;
	HeapNode t;
	int A[100], i, j;                       //��������ͱ�������
	srand((unsigned)time(NULL));           //����ϵͳʱ��Ϊ�������
	for (i = 0; i < 100; i++)                    //����10�������
	{
		A[i] = 1 + rand() % 100;                //�õ������(��Χ��1-10֮��)
		for (j = 0; j < i; j++)                 //�жϺ�ǰ������Ƿ��ظ�
			if (A[i] == A[j]) { i--; break; }  //����ظ�,���²��������
	}
	for (i = 0; i < 100; i++)
	{
		t.data = i; t.priority = A[i];
		a.insert(t);
	}
	for (i = 0; i < 100; i++)
	{
		HeapNode t = a.Pop();
		cout << t.data << " Priority:" << t.priority << endl;
	}
}