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
		//将数据push到数组中
		for (i = 0; i < len; ++i)
		{
			MinHeapArr.push_back(arr[i]);
		}
		//建堆
		//从最后一个叶子结点的父亲开始把堆调整成小堆
		for (i = len - 1; i >= 0; --i)
		{
			int root = (i - 1) / 2;
			_AdjustDown(root);
		}
	}

	//将第一个最小数与最后一个数据交换，删除最后一个数据，然后将堆向下调整
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

	//push一个数据，然后将堆向上调整
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
	//下调，要调整每一棵子树，子子树；
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

	//上调，只调整每一棵子树就可以了，因为子子树本来就是一个堆
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
