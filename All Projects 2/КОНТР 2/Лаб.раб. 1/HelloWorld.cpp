//������������ ���� ����� �����. �������� �������, ������� ������� �� ���� ��� ��������, ������� ��������� �����.
#include "stdafx.h"
#include "targetver.h"
using namespace std;
int m = 0;
int k;
int k2[10];
int z = 0;
struct st
{
	int v;
	st *head, *next;
};
void push(int x, st *MyStk);
void pok(st *MyStk);
int pop(st *MyStk);
void main()
{
	setlocale(LC_ALL, "Rus");
	st *MOI = new st;
	MOI->head = NULL;
	for (;;)
	{
		cout << "������ �� ������. �������� �������:" << endl;
		cout << "1 - ���������� ��������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - �����" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{cout << "������� ������� ��� �������: " << endl;
		cin >> k;
		k2[m] = k;
		m++;
		push(k, MOI);
		break;
		}
		case 2:
		{
			pop(MOI);
			break;
		}
		case 3:
		{
			cout << "���� ����: " << endl;
			pok(MOI);
			break;
		}
		case 4:
		{
			return;
			break;
		}

		}
	}
}
void push(int x, st *MyStk)
{
	st* e = new st;
	e->v = x;
	e->next = MyStk->head;
	MyStk->head = e;
	z++;
}
int rek(int p,st *y,st *MySTK)
{
	if ((y->head->v > p) && (z == 1))
	{
		y->head= NULL;
		return 0;
	}
	if((y->head->v < p) && (z == 1))
		return 0;
	if (y->head->next == NULL)
	{
		if (y->head->v > p)
		{
			y->head = NULL;
			return 0;
		}
		MySTK = y;
	}
	else
	{
		if (y->head->v > p)
		{
			y->head = y->head->next;
			rek(p, y, MySTK);
		}
		else
		{
			swap(y->head->next->v, y->head->v);
			rek(p, y, MySTK);
		}
	}
}
int pop(st *MyStk)
{
	st*y = MyStk;
	int p;
	cin >> p;
	if (MyStk->head == NULL)
	{
		cout << "�����!" << endl;
		return -1;
	}
	else
	{
		rek(p, y, MyStk);
	}
		/*st*y = MyStk;
		for (int i = 0;i<z; i++)
		{
			if((y->head->v>p) && (z >= 2))
			{
				delete y;
				MyStk->head->next = NULL;
				return 0;
			}
			else
				if((y->head->v>p)&&(z==1))
			{	
				y->head =y->head->next;
				MyStk = y;
				return 0;
			}
		
		}*/
	}

void pok(st *MyStk)
{
	st* e = MyStk->head;
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->v;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}