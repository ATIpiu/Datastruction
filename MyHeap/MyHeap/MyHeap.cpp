#include "MyHeap.h"

MyHeap::MyHeap(int size)
{
	this->maxsize = size;
	this->elements = new HeapNode[maxsize];
	this->lenth = 0;
}

void MyHeap::insert(HeapNode t)
{
	lenth++;
	elements[lenth] = t;
	this->insert_(lenth);
}

void MyHeap::Print()
{
	for (int i = 1; i <= lenth; i++)
	{
		std::cout << elements[i].data <<"  p:"<<elements[i].priority<< std::endl;
	}
}

HeapNode MyHeap::Pop()
{
	HeapNode t = elements[1];
	elements[1] = elements[lenth];
	lenth--;
	this->pop(1);
	return t;
}

void MyHeap::insert_(int i)
{
	if (i == 1)
		return;
	if (elements[i].priority > elements[i / 2].priority)
	{
		HeapNode t;
		t = elements[i];
		elements[i] = elements[i / 2];
		elements[i / 2] = t;
		this->insert_(i / 2);	
	}
	else
	{
		return;
	}

}

void MyHeap::pop(int i)
{
	int t=i;
	if (i*2<=lenth&&elements[i].priority< elements[i * 2 ].priority ){
		t = i * 2 ;
	}
	if (i * 2 + 2 <= lenth && elements[t].priority < elements[i * 2 + 1].priority) {
		t = i * 2 + 1;
	}
	if(t!=i)
	{
		HeapNode ti;
		ti = elements[i];
		elements[i] = elements[t];
		elements[t] = ti;
		this->pop(t);
	}
}
