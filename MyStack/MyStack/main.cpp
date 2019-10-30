#include<iostream>
#include"Stack.h"
int main()
{
	Stack<char> stack;
	std::string a;
	std::cin >> a;
	stack.isMatching(a);
}