#include "Header.h"
#include "К14лабе(2).h"
struct AAA        //элемент таблицы
{
	int key;
	char *mas;
};

namespace listx
{
	bool Object::Insert(void* data)
	{
		bool rc = NULL;
		if (Head == NULL)   Head = new Element(NULL, data, Head);
		else Head = (Head->Prev = new Element(NULL, data, Head));
		return rc;
	}
	Element* Object::Search(void* data)
	{
		Element* rc = Head;
		while ((rc != NULL) && ((((AAA*)rc->Data)->key) != ((AAA*)data)->key))
			rc = rc->Next;
		return rc;
	}
	bool Object::Delete(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->Next != NULL)   e->Next->Prev = e->Prev;
			if (e->Prev != NULL)   e->Prev->Next = e->Next;
			else Head = e->Next;
			delete e;
		}
		std::cout << "Элемент удален" << std::endl;
		return rc;
	}

	bool Object::Delete(void* data)
	{
		return Delete(Search(data));
	}
	Element* Object::GetLast()
	{
		listx::Element* e = this->GetFirst(), *rc = this->GetFirst();
		while (e != NULL)
		{
			rc = e;   e = e->GetNext();
		};
		return rc;
	}
	Object Create()
	{
		return *(new Object());
	};
	void Object::Scan()    // просмотр
	{
		listx::Element* e = this->GetFirst();
		while (e != NULL)
		{
			std::cout << ((AAA*)e->Data)->key << '-' << ((AAA*)e->Data)->mas << " / ";
			e = e->GetNext();
		};
	}
}
