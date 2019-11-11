#pragma once
#include<iostream>
struct HeapNode
{
	int data;
	int priority;
};
class MyHeap{
private:
	HeapNode* elements;//������
	int maxsize;//�������
	int lenth;//����
protected:
	void insert_(int i);
	void pop(int i);
public:
	MyHeap(int size=100);
	void insert(HeapNode t);
	void Print();
	HeapNode Pop();


};



