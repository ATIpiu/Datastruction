#include<iostream>
#include"MyHeap.h"
#include<stdlib.h>
#include <time.h>
using namespace std;
int  main()
{
	MyHeap a;
	HeapNode t;
	int A[100], i, j;                       //整型数组和变量声明
	srand((unsigned)time(NULL));           //设置系统时间为随机种子
	for (i = 0; i < 100; i++)                    //产生10个随机数
	{
		A[i] = 1 + rand() % 100;                //得到随机数(范围在1-10之间)
		for (j = 0; j < i; j++)                 //判断和前面的数是否重复
			if (A[i] == A[j]) { i--; break; }  //如果重复,重新产生随机数
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