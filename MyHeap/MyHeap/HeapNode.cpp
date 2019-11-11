#include "HeapNode.h"

template<class T>
inline HeapNode<T>::HeapNode(T temp, int p)
{
	this->data = temp;
	this->priority = p;
}

template<class T>
HeapNode<T>::HeapNode()
{
	this->data = nullptr;
	this->priority = -1;
}
template<class T>
void HeapNode<T>::setData(T temp)
{
	this->data = temp;
}

template<class T>
void HeapNode<T>::setPriority(int p)
{
	this->priority = p;
}

