#pragma once
#include<iostream>
struct HeapNode
{
	int data;
	int priority;
};
class MyHeap{
private:
	HeapNode* elements;//数据域
	int maxsize;//最大容量
	int lenth;//长度
protected:
	void insert_(int i);
	void pop(int i);
public:
	MyHeap(int size=100);
	void insert(HeapNode t);
	void Print();
	HeapNode Pop();


};



