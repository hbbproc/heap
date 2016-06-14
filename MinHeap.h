#pragma once
#include<vector>


template<class T>
class MinHeap
{
public:
	MinHeap()
	{}

	MinHeap(int* arr, int len)
	{
		int i = 0;
		//������push��������
		for (i = 0; i < len; ++i)
		{
			MinHeapArr.push_back(arr[i]);
		}
		//����
		//�����һ��Ҷ�ӽ��ĸ��׿�ʼ�Ѷѵ�����С��
		for (i = len - 1; i >= 0; --i)
		{
			int root = (i - 1) / 2;
			_AdjustDown(root);
		}
	}

	//����һ����С�������һ�����ݽ�����ɾ�����һ�����ݣ�Ȼ�󽫶����µ���
	void Pop()
	{
		swap(MinHeapArr[0], MinHeapArr[MinHeapArr.size() - 1]);
		MinHeapArr.pop_back();
		int root = (MinHeapArr.size() - 2) / 2;
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
		MinHeapArr.push_back(x);
		int root = (MinHeapArr.size() - 2) / 2;
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
		while (child > (int)MinHeapArr.size())
		{
			if (child + 1 < (int)MinHeapArr.size() && MinHeapArr[child] >  MinHeapArr[child + 1])
			{
				++child;
			}

			if (MinHeapArr[child] < MinHeapArr[root])
			{
				swap(MinHeapArr[child], MinHeapArr[root]);
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
		while (child < (int)MinHeapArr.size())
		{
			if (child + 1 < (int)MinHeapArr.size() && MinHeapArr[child] > MinHeapArr[child + 1])
			{
				++child;
			}

			if (MinHeapArr[child] < MinHeapArr[root])
			{
				swap(MinHeapArr[child], MinHeapArr[root]);
			}
			else
			{
				break;
			}
		}
	}

private:
	vector<T> MinHeapArr;
};

void TestMinHeap()
{
	int arr[10] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MinHeap<int> hp(arr, len);
	hp.Push(21);
	hp.Pop();
}
