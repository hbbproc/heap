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
		//将数据push到数组中
		for (i = 0; i < len; ++i)
		{
			MaxHeapArr.push_back(arr[i]);
		}
		//建堆
		//从最后一个叶子结点的父亲开始把堆调整成大堆
		for (i = len - 1; i >= 0; --i)
		{
			int root = (i - 1) / 2;
			_AdjustDown(root);
		}
	}

	//将第一个最大数与最后一个数据交换，删除最后一个数据，然后将堆向下调整
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

	//push一个数据，然后将堆向上调整
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
	//下调，要调整每一棵子树，子子树；
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

	//上调，只调整每一棵子树就可以了，因为子子树本来就是一个堆
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
