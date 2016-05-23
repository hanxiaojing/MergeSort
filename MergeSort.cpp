#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
USING NAMESPACE STD;

#include<assert.h>

void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}


void Merge(int* a, int* tmp,int left,int mid, int right)
{
	int i = 0;
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	//注意区间是：[left,mid]  [mid+1,right]  区间不可以是：[left,mid-1] [mid,right]
	//两个区间合并成一个区间
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
	{
		tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//处理合并时可能出现的这种情况：一个区间还未走完，而另一个区间已走完
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
		
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];		
	}
	
	//将合并好的有序区间拷贝回a中，注意：tmp每次是从0开始的，将数组tmp从前至后拷回给数组a是从left开始的
	for (int j = 0; j < i; j++)
	{
	a[left+j] = tmp[j];
	}
｝


void MergeSort(int* a,int* tmp, int left, int right)
{
	assert(a);
	//将序列的整个区间每次递归压栈划分成两半，直至区间划分成只有一个元素为止。
	if (left < right)
	{
		int mid = left - (left - right) / 2;
		if (left <= mid)
		{
		MergeSort(a, tmp, left, mid);
		}

		if (mid+1 <= right)
		{
			MergeSort(a, tmp, mid+1, right);
		}
		//此时，序列已划分为只有一个元素，将每两个区间合并成为一个有序区间，出栈返回上一层，继续
		Merge(a, tmp, left, mid, right);
	}
}


void TestMergeSort()
{
	int a[] = { 12,34,12222,4568, 26, 1, 16, 10, 2, 4, 4, 93, 7, 5, 2, 4 };
	int size = sizeof(a) / sizeof(a[0]);
	int* tmp = new int[size];
	MergeSort(a, tmp, 0, size - 1);
	Print(a, size);
	delete[] tmp;
}


int main()
{
	TestMergeSort();
	system("pause");
	return 0;
}
