#pragma once              //Заголовочный файл List.h
#define LISTNIL (Element*)-1
namespace listx
{
	struct Element
	{
		Element* Prev;
		Element* Next;
		void* Data;
		Element(Element* prev, void* data, Element* next)
		{
			Prev = prev; Data = data; Next = next;
		}
		Element* GetNext()
		{
			return Next;
		};
		Element* GetPrev()
		{
			return Prev;
		};
	};
	static Element* NIL = NULL;
	struct Object
	{
		Element* Head;
		Object() { Head = NIL; };
		Element* GetFirst() { return Head; };
		Element* GetLast(); Element* Search(void* data);
		bool Insert(void* data);  bool Delete(Element* e);
		bool Delete(void* data);  void Scan();
	};
	Object Create();
}
#undef LISTNIL 