//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//#include<assert.h>
//
//
//void Print(int* a, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << a[i] << "  ";
//	}
//	cout << endl;
//}
//
//
//void Merge(int* a, int* tmp,int left,int mid, int right)
//{
//	int i = 0;
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid + 1;
//	int end2 = right;
//	//ע�������ǣ�[left,mid]  [mid+1,right]  ���䲻�����ǣ�[left,mid-1] [mid,right]
//	//��������ϲ���һ������
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] <= a[begin2])
//		{
//			tmp[i++] = a[begin1++];
//		}
//		else
//		{
//			tmp[i++] = a[begin2++];
//		}
//	}
//
//	//����ϲ�ʱ���ܳ��ֵ����������һ�����仹δ���꣬����һ������������
//	while (begin1 <= end1)
//	{
//		tmp[i++] = a[begin1++];
//		
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i++] = a[begin2++];		
//	}
//	
//	//���ϲ��õ��������俽����a�У�ע�⣺tmpÿ���Ǵ�0��ʼ�ģ�������tmp��ǰ���󿽻ظ�����a�Ǵ�left��ʼ��
//	for (int j = 0; j < i; j++)
//	{
//		a[left+j] = tmp[j];
//	}
//}
//
//
//void MergeSort(int* a,int* tmp, int left, int right)
//{
//	assert(a);
//	//�����е���������ÿ�εݹ�ѹջ���ֳ����룬ֱ�����仮�ֳ�ֻ��һ��Ԫ��Ϊֹ��
//	if (left < right)
//	{
//		int mid = left - (left - right) / 2;
//		if (left <= mid)
//		{
//			MergeSort(a, tmp, left, mid);
//		}
//
//		if (mid+1 <= right)
//		{
//			MergeSort(a, tmp, mid+1, right);
//		}
//		//��ʱ�������ѻ���Ϊֻ��һ��Ԫ�أ���ÿ��������ϲ���Ϊһ���������䣬��ջ������һ�㣬����
//		Merge(a, tmp, left, mid, right);
//	}
//}
//
//
//void TestMergeSort()
//{
//	int a[] = { 12,34,12222,4568, 26, 1, 16, 10, 2, 4, 4, 93, 7, 5, 2, 4 };
//	int size = sizeof(a) / sizeof(a[0]);
//	int* tmp = new int[size];
//	MergeSort(a, tmp, 0, size - 1);
//	Print(a, size);
//	delete[] tmp;
//}
//
//
//int main()
//{
//	TestMergeSort();
//	system("pause");
//	return 0;
//}