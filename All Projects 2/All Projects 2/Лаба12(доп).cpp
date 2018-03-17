#include "Header.h"
#include "К12лабе.h"
using namespace std;
int k = 999, kk = 0, l = 0;
void AAA::Print()
{
	std::cout << x;
}
void AAA::Print2()
{

	if (x < k)
	{
		k = x;
		l = kk;
	}kk++;
}
int AAA::GetPriority() const { return x; }
namespace heap
{
	Heap Createc(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::Leftt(int ix)
	{
		return (2 * ix + 1 >= Size) ? -1 : (2 * ix + 1);
	}
	int Heap::Rightt(int ix)
	{
		return (2 * ix + 2 >= Size) ? -1 : (2 * ix + 2);
	}
	int Heap::Parent(int ix) { return (ix + 1) / 2 - 1; }
	void Heap::Swap(int i, int j)
	{
		void* buf = Storage[i];   Storage[i] = Storage[j];    Storage[j] = buf;
	}
	void Heap::Heapify(int ix)
	{
		int l = Leftt(ix), r = Rightt(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(Storage[l], Storage[ix]))     irl = l;
			if (r > 0 && isGreat(Storage[r], Storage[irl]))   irl = r;
			if (irl != ix) { Swap(ix, irl);	Heapify(irl); }
		}
	}
	void Heap::Insertt(void* x)
	{
		int i;
		if (!isFull())
		{
			Storage[i = ++Size - 1] = x;
			while (i > 0 && isLess(Storage[Parent(i)], Storage[i]))
			{
				Swap(Parent(i), i);	i = Parent(i);
			}
		}
	}
	
		void* Heap::ExtractMax() //функция удаления максимального элемента дерева
		{
			void* rc = NULL;
			if (!isEmpty())
			{
				rc = Storage[0];	Storage[0] = Storage[Size - 1];
				Size--;	Heapify(0);
			} return rc;
		}
	void* Heap::ExtractIT()
	{
		int k;
		cin >> k;
		void* rc=0;
		if (!isEmpty())
		{
			rc = Storage[k];	Storage[k] = Storage[Size - 1];
			Size--;	Heapify(0);
		} return rc;
	}
	void* Heap::ExtractMin()
	{
		int key = 9999, index = -1;
		if (Size == 0)
			cout << "Куча пуста";
		for (int u = 0; u < Size; u++)
		{
			if (((AAA*)Storage[u])->x < key)
			{
				key = ((AAA*)Storage[u])->x;
				index = u;
			}
		}
		cout << "key = " << ((AAA*)Storage[index])->x << endl;
		cout << "index =  " << index << endl;
		void* rc = NULL;
		if (!isEmpty())
		{
			rc = Storage[index];
			Storage[index] = Storage[Size - 1];
			Size--;
			Heapify((index + 1) / 2 + 1);
		}
		return rc;
	}
	void Heap::Scan(int i) const  //Вывод значений элементов на экран
	{
		int probel = 20;	std::cout << '\n';
		if (Size == 0)   std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < Size; u++)
		{
			std::cout << setw(probel + 10) << setfill(' ');
			((AAA*)Storage[u])->Print();
			if (u == y) { cout << '\n';   if (y == 0)  y = 2;  else  y += y * 2; }
			probel /= 2;
		}
		std::cout << '\n';
	}
	void Heap::Scan2(int i) const  //Вывод значений элементов на экран
	{
		if (Size == 0)
			for (int u = 0, y = 0; u < Size; u++)
			{
				((AAA*)Storage[u])->Print2();
			}
	}
	void Heap::DeleteHeap()
	{
		if (!isEmpty())
		{
			Size = 0;	this->~Heap();
		}
	}
}