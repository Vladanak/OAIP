#pragma once
struct AAA
{
	int x;			//приоритет
	void Print();
	void Print2();
	int GetPriority() const;
};
namespace heap
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Heap
	{
		int Size;  int MaxSize;
		void** Storage;
		CMP(*Compare)(void*, void*);
		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			Size = 0;    Storage = new void *[MaxSize = maxsize]; Compare = f;
		};
		Heap(int maxsize, CMP(*f)(void*, void*), void* x[])
		{
			Size = 0;   Storage = x;	MaxSize = maxsize;   Compare = f;
		};
		int Leftt(int ix);  int Rightt(int ix);
		int Parent(int ix);
		bool isFull() const { return (Size >= MaxSize); };
		bool isEmpty() const { return (Size <= 0); };
		bool isLess(void* x1, void * x2) const
		{
			return Compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2) const
		{
			return Compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2) const
		{
			return Compare(x1, x2) == EQUAL;
		};
		void Swap(int i, int j);
		void Heapify(int ix);
		void Insertt(void* x);
		void* ExtractMax();
		void* ExtractMin();
		void* ExtractIT();

		void DeleteHeap();
		void Scan(int i) const;
		void Scan2(int i) const;
	};
	Heap Createc(int maxsize, CMP(*f)(void*, void*));
};