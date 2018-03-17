#include "Header.h"
#include "К14лабе(1).h"
#include "К14лабе(2).h"
struct AAA
{
	int key;
	char *mas;
	AAA(int k, char*z)
	{
		key = k;  mas = z;
	}
};
namespace hashTC
{
	Object Create(int size, int(*f)(void*))
	{
		return *(new Object(size, f));
	}
	int Object::HashFunction(void* data)
	{
		return (FunKey(data) % Size);
	};
	bool Object::Insert(void* data)
	{
		return (Hash[HashFunction(data)].Insert(data));
	};
	bool Object::Delete(void* data)
	{
		return (Hash[HashFunction(data)].Delete(data));
	};
	listx::Element* Object::Search(void* data)
	{
		return Hash[HashFunction(data)].Search(data);
	};
	void Object::Scan()
	{
		for (int i = 0; i < Size; i++)
		{
			Hash[i].Scan();   std::cout << '\n';
		}
	};
}