#pragma once
#include<iostream>
template<class T>
class Stack
{
private:
	int maxsize;
	T* data;
	int top;
public:
	Stack(int maxsize = 30)
	{
		this->maxsize = maxsize;
		data = new T[maxsize];
		top = -1;
	}
	void push(T element)
	{
		if (this->isFull())
			exit(1);
		top++;
		data[top] = element;
	}
	T pop()
	{
		if (this->isEmpty())
			exit(1);
		T t = this->data[top];
		top--;
		this->data[top]=NULL;
		return t;
	}
	bool isFull()
	{
		if (top == maxsize - 1)
		{
			return true;
		}
		else
			return false;
	}
	bool isEmpty()
	{
		if (top !=-1)
			return false;
		else
			return true;
	}
	void reveseOutput()
	{
		int n;
		std::cout << "please input the number of the string" << std::endl;
		std::cin >> n;
		for (int i = 0;i < n;i++)
		{
			T c;
			std::cout << "please input" << std::endl;
			std::cin >> c;
			this->push(c);
		}
		std::cout << "reversed String:" << std::endl;
		while (top>=0)
		{
			T t = this->pop();
			std::cout << t << std::endl;
		}
	}
	void isMatching(std::string a)
	{
		int l = a.length();
		for (int i = 0;i < l;i++)
		{
			if (a[i] == '{')
				this->push(a[i]);
			if (a[i] == '}')
				this->pop();
			if (top < 0) break;
		}
		if (this->isEmpty())
		{
			std::cout << "{} is matching" << std::endl;
		}
		else
		{
			std::cout << "{} is not matching" << std::endl;
		}
	}
};

