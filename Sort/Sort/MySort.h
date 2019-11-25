#pragma once
#include<deque>
#include<iostream>
using namespace std;
class MySort
{
public:
template<class T>
void static insertSort(deque<T> &vi)
{
	for (int i = 1; i < vi.size(); i++)
	{
		T temp = vi[i];
		int j;
		for (j = i - 1; j >= 0 && temp < vi[j]; j--)
		{
			vi[j + 1] = vi[j];
		}
		vi[j + 1] = temp;
	}
}
template<class T>
void static selectSort(deque<T>& d)
{
	for (int i = 0; i < d.size(); i++)
	{
		for(int j=i;j<d.size();j++)
			if (d[i] > d[j])
			{
				swap(d[i], d[j]);
			}
	}
}
template<class T>
void static swapSort(deque<T>& d) {
	for (int i = 0; i < d.size(); i++)
	{
		int min = i;
		for (int j = i; j < d.size(); j++)
		{
			if (d[min] > d[j])
				min = j;
		}
		swap(d[min], d[i]);
	}
}
template<class T>
void static merge(deque<T>& nums, int l1, int r1, int l2, int r2) {
	int i = l1;                                              
	int j = l2;                                             
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                   
	deque<T> temp(n);                                     
	int k = 0;	                                          
	while (i <= r1 && j <= r2) {                                
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}
}
template<class T>
void static MergeSort(deque<T>& nums, int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;				
		MergeSort(nums, start, mid);				
		MergeSort(nums, mid + 1, end);				
		merge(nums, start, mid, mid + 1, end);                 
	}
}
template<class T>
void static MergeSort1(deque<T>& nums, int start, int end)
{
	int n = nums.size();
	if (start < end) {
		for (int step = 2; step / 2 < n; step *= 2) {
			for (int i = 0; i < n; i += step) {
				int mid = i + step / 2 - 1;
				if (mid + 1 < n)

					merge(nums, i, mid, mid + 1, mid(i + step - 1, n - 1));
			}
		}
	}
}
template<class T>
void static MergeSort(deque<T>& nums)
{
	int r = nums.size();
	MergeSort(nums, 0, r-1);
}
template<class T>
void static QuickSort(deque<T>& arr,int left,int right) {	
	if (left >= right)
		return;
	int i, j;T  base, temp;
	i = left, j = right;
	base = arr[left]; 
	while (i < j)
		{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[left] = arr[i];
	arr[i] = base;
	QuickSort(arr,left, i - 1) ;
	QuickSort(arr,i + 1, right);
}
};

