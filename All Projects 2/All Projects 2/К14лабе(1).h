#pragma once              //Заголовочный файл Hash_ Twin_Chain.h
#include "К14лабе(2).h"
namespace hashTC
{
	struct Object
	{
		int Size;
		int(*FunKey)(void*);
		listx::Object* Hash;
		Object(int size, int(*f)(void*))
		{
			Size = size;	 FunKey = f;  Hash = new listx::Object[Size];
		};
		int HashFunction(void* data);
		bool Insert(void* data);
		listx::Element* Search(void* data);
		bool Delete(void* data);
		void Scan();
	};
	Object Create(int size, int(*f)(void*));
}
