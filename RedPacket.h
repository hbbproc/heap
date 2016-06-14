#pragma once

//100w�������ҳ�����k����,����С��
#include<assert.h>
#include<iostream>
using namespace std;

void _AdjustDown(int* KOfArr,int k,int root)
{
	int child = root * 2 + 1;
	while (child < k - 1)
	{
		if (child + 1 < k - 1 && KOfArr[child] > KOfArr[child + 1])
		{
			++child;
		}
		if (KOfArr[child] < KOfArr[root])
		{
			swap(KOfArr[child], KOfArr[root]);
			root = child;
			child = 2 * root + 1;
		}
		else
		{
			break;
		}
	}
}

void RedPacket(int* NOfArr, int* KOfArr,int n, int k)
{
	assert(NOfArr);
	assert(KOfArr);
	assert(k < n && k>0);

	int i = 0;

	//��ǰk�����ȷ����ڴ�
	for (i = 0; i < k; ++i)
	{
		KOfArr[i] = NOfArr[i];
	}

	//����
	for (i = k - 1; i >= 0; --i)
	{
		int root = (i - 1) / 2;
		_AdjustDown(KOfArr, k, root);
	}

	//�滻һ�δ����ݣ��µ�һ�Σ���֤�Ѷ�������С

	for (i = k; i < (int)n; ++i)
	{
		if (KOfArr[0] < NOfArr[i])
		{
			KOfArr[0] = NOfArr[i];
			_AdjustDown(KOfArr, k, 0);
		}
	}
}

void Print(int* KOfArr, int k)
{
	assert(KOfArr);
	assert(k > 0);

	for (int i = 0; i < k; ++i)
	{
		cout << KOfArr[i] << " ";
	}
	cout << endl;
}


void TestRedPacket()
{
	int *NOfArr = new int[1000000];
	int KOfArr[100] = { 0 };
	int i = 0;
	for (i = 0; i < 1000000; ++i)
	{
		NOfArr[i] = i;
	}

	NOfArr[0] = 9999999;
	NOfArr[1] = 9999999;
	NOfArr[2] = 9999999;

	RedPacket(NOfArr, KOfArr, 1000000, sizeof(KOfArr) / sizeof(KOfArr[0]));
	Print(KOfArr, sizeof(KOfArr) / sizeof(KOfArr[0]));
	delete[] NOfArr;
}

//����С��

void HeapSort(int* arr,int len)
{
	assert(arr);
	assert(len > 0);

	//����
	int i = 0;
	for (i = len-1; i >= 0; --i)
	{
		int root = (i - 1) / 2;
		_AdjustDown(arr, len, root);
	}

	i = len;
	while (i > 1)
	{
		swap(arr[0], arr[i - 1]);
		//�Ƚ���Сֵ��ȥ�����µ���
		--i;
		_AdjustDown(arr,i,0);
	}
}

void TestHeapSort()
{
	int arr[10] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
}