#include"MySort.h"
#include<time.h>
int main() {
	MySort q;
	int A[100], i, j;                       //整型数组和变量声明
	srand((unsigned)time(NULL));           //设置系统时间为随机种子
	for (i = 0; i < 100; i++)                    //产生10个随机数
	{
		A[i] = 1 + rand() % 100;                //得到随机数(范围在1-10之间)
		for (j = 0; j < i; j++)              //判断和前面的数是否重复
			if (A[i] == A[j])
			{
				i--; break;
			}  //如果重复,重新产生随机数
	}
	deque<int> a;
	for (i = 0; i < 100; i++)
	{
		a.push_back(A[i]);
	}
	MySort::QuickSort(a,0,99);
	for (i = 0; i < 100; i++)
	{
		cout << a[i] << endl;
	}
}