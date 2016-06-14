#pragma once
#include<iostream>
using namespace std;
#include<vector>
//仿函数（函数对象）
template<class T>
struct GreaterCompare
{
	bool operator()(const T& leftChild, const T& rightChild)
	{
		return leftChild > rightChild;
	}
};

template<class T>
struct LessCompare
{
	bool operator()(const T& leftChild, const T& rightChild)
	{
		return leftChild < rightChild;
	}
};

//模板类型的模板形参
template<class T,template<class> class Compare = GreaterCompare> //缺省参数

//template<class T,class Compare<T> = GreaterCompare>
class Heap
{
public:
	Heap()
	{}

	Heap(const T* arr,int len)
	{
		if (arr == NULL || len <= 0)
			return;

		for (int i = 0; i < len; ++i)
		{
			_heapArr.push_back(arr[i]);
		}

		//建堆：找第一个非叶子结点的父亲，然后向下调整
		for (int i = len - 1; i >= 0; --i)
		{
			int root = (i - 1) / 2;
			_AdjustDown(root);
		}
	}

	//末尾增加一个结点后，向上调整
	void Push(const T& x)
	{
		_heapArr.push_back(x);
		_AdjustUp(_heapArr.size() - 1);
	}

	//删除一个结点时，先将堆顶数据与末尾数据交换，然后删除末尾数据，最后向下调整
	void Pop()
	{
		swap(_heapArr[0], _heapArr[_heapArr.size() - 1]);
		_heapArr.pop_back();
		_AdjustDown(0);
	}

	T& Size()
	{
		return _heapArr.size();
	}

	bool Empty()
	{
		return _heapArr.empty();
	}

	T& Top()
	{
		return _heapArr[0];
	}

	void Print()
	{
		for (int i = 0; i < (int)_heapArr.size(); ++i)
		{
			cout << _heapArr[i] << " ";
		}
		cout << endl;
	}

	~Heap()
	{}

protected:
	//向下调整
	void _AdjustDown(int root)
	{
		Compare<T> com;
		int child = root * 2 + 1;
		while (child < (int)_heapArr.size())
		{
			if (child + 1 < (int)_heapArr.size() && com(_heapArr[child + 1], _heapArr[child]))
			{
				++child;
			}

			if (com(_heapArr[child], _heapArr[root]))
			{
				swap(_heapArr[child], _heapArr[root]);
				root = child;
				child = root * 2 + 1;
			}
			else
			{
				break;
			}
		}	
	}

	//向上调整
	void _AdjustUp(int child)
	{
		Compare<T> com;
		int root = (child - 1) / 2;
		while (child > 0)
		{
			if (com(_heapArr[child], _heapArr[root]))
			{
				swap(_heapArr[child], _heapArr[root]);
				child = root;
				root = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

private:
	vector<T> _heapArr;
};

//测试用例
void TestHeap()
{
	int arr[10] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//大堆
	Heap<int> hp1(arr, len);
	hp1.Print();
	//小堆
	Heap<int,LessCompare> hp(arr, len);
	hp.Print();

	hp.Push(21);
	hp.Print();

	hp.Pop();
	hp.Print();
}

//将堆封装成优先级队列
template <class T>
class PriorityQueue
{
public:
	PriorityQueue(Heap<T>& heap)
		:_heap(heap)
	{}

	~PriorityQueue()
	{}

	void QueuePush(const T& x)
	{
		_heap.Push();
	}

	void QueuePop()
	{
		_heap.Pop();
	}

	bool QueueEmpty()
	{
		return _heap.Empty();
	}

	int QueueSize
	{
		return _heap.Size();
	}

	T& QueueFront()
	{
		return _heap.Top();
	}

private:
	Heap<T> _heap;
};


