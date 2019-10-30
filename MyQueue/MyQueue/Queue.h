#pragma once
#include<iostream>
template<class T>
class Queue
{
private:
	int rear;//队尾指针
	int front;//队首指针
	T* data;//数据域
	int maxsiaze;
public:
	Queue(int t = 30)
	{
		this->maxsiaze = t;
		data = new T[maxsiaze];
		if (data == NULL)
		{
			std::cout << "error" << std::endl;
		}
		front = 0;
		rear = -1;
	}
	void insert(T element)
	{
		if (isFull())
		{
			std::cout << "insert error:the queue is Full" << std::endl;
			exit(1);
		}
		rear = (rear + 1) % maxsiaze;
		data[rear] = element;
	}
	T pop()
	{
		if (this->isEmpty())
		{
			std::cout << "pop error:the queue is empty" << std::endl;
			exit(1);
		}
		T temp = data[front];
		front++;
		return temp;
	}
	bool isFull()
	{
		if (rear==maxsiaze-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	T getTop()
	{
		return this->data[front];
	}
	bool isEmpty()
	{
		if (front >rear)
		{
			return true;
		}
		return false;
	}
};

