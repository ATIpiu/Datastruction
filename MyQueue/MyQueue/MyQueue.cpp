#include<iostream>
#include"Queue.h"
void print()
{
	using namespace std;
	Queue<int> queue;
	int n;
	cout << "please input n" << endl;
	cin >> n;
	queue.insert(1);
	queue.insert(1);
	for (int i = 1;i < n;i++)
	{
		for (int j = 1;j <= i + 1;j++)
		{
			for (int k = 1;k <= n - 1;k++)cout << " ";
			int t = queue.pop();
			cout << t << " ";
			queue.insert(queue.getTop() + t);
		}
		cout << endl;
	}
}
void YangVi(int n)
{
	using namespace std;
	Queue<int> queue(1000);
	int i = 1, j, s = 0, k = 0, t, u;
	queue.insert(i); queue.insert(i);
	for (i = 1; i <= n; i++)
	{		
		cout << endl;
		for (int k = 1; k <= n - i; k++)cout << " ";
		queue.insert(0);
		for (j = 1; j <= i + 2; j++)
		{
			t = queue.pop();
			u = s + t; queue.insert(u);
			s = t;
			if (j!=i+2) cout << s << " ";
		}
	}
}
int main()
{
	std::cout << "please input a number" << std::endl;
	int n; std::cin >> n;
	YangVi(n);
	return 0;
}