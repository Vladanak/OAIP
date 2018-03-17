#pragma once 
struct Element                   // Ёлемент списка 
{
	Element* Prev;                // указатель на предыдущий элемент 
	Element* Next;                // указатель на следующий элемент 
	void*  Data;                  //  данные  
	Element(Element* prev, void* data, Element* next)
	{                             // конструктор
		Prev = prev;
		Data = data;
		Next = next;
	}
	Element* GetNext()            // получить следующий
	{
		return Next;
	};
	Element* GetPrev()            // получить предыдущий  
	{
		return Prev;
	};
};
struct Object                     // Ѕлок управлени€ списком 
{
	Element* Head;                 // указатель на начало списка
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // получить первый элемент списка
	{
		return Head;
	};
	Element* GetLast();            // получить последний элемент списка
	Element* Search(void* data);   // найти  первый элемент по данным 
	bool Insert(void* data);       // добавить элемент в начало
	bool InsertEnd(void* data);    // добавить в конец 
	bool Delete(Element* e);       // удалить по адресу элемента 
	bool Delete(void* data);       // удалить первый по данным
	bool DeleteList();		    // очистить список 
	void Object::PrintList(void(*f)(void*));
	void Object::PrintList(void(*f)(void*), Element*);
	int Object::CountList();
};
Object Create();                   // создать список