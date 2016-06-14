#pragma once

#include<vector>

template<class T>
class MaxHeap
{
public:
	MaxHeap()
	{}

	MaxHeap(int* arr, int len)
	{
		int i = 0;
		//������push��������
		for (i = 0; i < len; ++i)
		{
			MaxHeapArr.push_back(arr[i]);
		}
		//����
		//�����һ��Ҷ�ӽ��ĸ��׿�ʼ�Ѷѵ����ɴ��
		for (i = len - 1; i >= 0; --i)
		{
			int root = (i - 1) / 2;
			_AdjustDown(root);
		}
	}

	//����һ������������һ�����ݽ�����ɾ�����һ�����ݣ�Ȼ�󽫶����µ���
	void Pop()
	{
		swap(MaxHeapArr[0], MaxHeapArr[MaxHeapArr.size() - 1]);
		MaxHeapArr.pop_back();
		int root = (MaxHeapArr.size() - 2) / 2;
		for (int i = root; i >= 0; i = (i - 1) / 2)
		{
			_AdjustDown(i);
			if (i == 0)
				break;
		}
	}

	//pushһ�����ݣ�Ȼ�󽫶����ϵ���
	void Push(const T& x)
	{
		MaxHeapArr.push_back(x);
		int root = (MaxHeapArr.size() - 2) / 2;
		for (int i = root; i >= 0; i = (i - 1) / 2)
		{
			_AdjustUp(i);
			if (i == 0)
				break;
		}
	}

protected:
	//�µ���Ҫ����ÿһ����������������
	void _AdjustDown(int root)
	{
		int child = root * 2 + 1;
		while (child < (int)MaxHeapArr.size())
		{
			if (child + 1 < (int)MaxHeapArr.size() && MaxHeapArr[child] < MaxHeapArr[child + 1])
			{
				++child;
			}

			if (MaxHeapArr[child] > MaxHeapArr[root])
			{
				swap(MaxHeapArr[child], MaxHeapArr[root]);
				root = child;
				child = root * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	//�ϵ���ֻ����ÿһ�������Ϳ����ˣ���Ϊ��������������һ����
	void _AdjustUp(int root)
	{
		int child = root * 2 + 1;
		while (child < (int)MaxHeapArr.size())
		{
			if (child + 1 < (int)MaxHeapArr.size() && MaxHeapArr[child] < MaxHeapArr[child + 1])
			{
				++child;
			}

			if (MaxHeapArr[child] > MaxHeapArr[root])
			{
				swap(MaxHeapArr[child], MaxHeapArr[root]);
			}
			else
			{
				break;
			}
		}
	}

private:
	vector<T> MaxHeapArr;
};

void TestMaxHeap()
{
	int arr[10] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MaxHeap<int> hp(arr, len);
	hp.Push(21);
	hp.Pop();
}
