#include"Header.h"
#include "�8����.h"
using namespace std;
int z = 0;
void push(int x, stack *MyStk)   //���������� �������� � � ����	
{
	stack* e = new stack;       //��������� ������ ��� ������ ��������
	e->v = x;                             //������ �������� x � ���� v 
	e->next = MyStk->head;  //������� ������� �� ��������� ������� 
	MyStk->head = e;             //����� ������� �� ������� ������
	z++;
}
int pop(stack *MyStk)   //���������� (��������) �������� �� �����
{
	z--; 
	if (MyStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;    //���� ���� ���� - ������� -1 
	}
	else
	{
		stack*e = MyStk->head;  //� - ��������� ���������� ��� �������� ������ ���-�����
		int a = MyStk->head->v;   //������ �������� �� ���� v � ���������� a 
		MyStk->head = MyStk->head->next; //������� �������
		delete e;                             //�������� ��������� ����������
		return a;                            //������� �������� ���������� ��������
	}
}
void show(stack *MyStk)
{
	stack* e = MyStk->head;
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
int Clear(stack *MyStk)
{
	for (int y = 0; y<z; y++)
	{
		if (MyStk->head == NULL)
		{
			cout << "���� ����!" << endl;
			return -1;    //���� ���� ���� - ������� -1 
		}
		else
		{
			stack*e = MyStk->head;  //� - ��������� ���������� ��� �������� ������ ���-�����
			int a = MyStk->head->v;   //������ �������� �� ���� v � ���������� a 
			MyStk->head = MyStk->head->next; //������� �������
			delete e;                             //�������� ��������� ����������
												  //������� �������� ���������� ��������
		}
	}
	z = 0;
}
void Zapis(stack *MyStk)
{
	FILE *fp;
	int a;
	fp = fopen("z.txt", "wb");
	stack* e = MyStk->head;
	while (e != NULL)
	{
		a = e->v;                  //������ �������� �� ���� v � ���������� a 
		fwrite(&a, sizeof(a), 1, fp);
		e = e->next;
	} fclose(fp);
}
void Viv(stack *MyStk)
{
	FILE *fp;
	fp = fopen("z.txt", "rb");
	int a, b[10], b2[10], i = 0, i2 = 0, rr;
	while (!feof(fp))
	{
		fread(&a, sizeof(a), 1, fp);
		b[i] = a;
		i++;
	}
	i--; 
	fclose(fp);
	rr = i - 1;
	for (int u = 0; u<i; u++)
	{
		b2[u] = b[rr];
		rr = rr - 1;
	}
	for (int y = 0; y<i; y++)
		push(b2[y], MyStk);
}
int Funcc(stack *MyStk)
{
	int  i, f;
	struct stack* y = MyStk->head;
	struct stack* d = MyStk->head;
	struct stack* c = MyStk->head;
	if (MyStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;    //���� ���� ���� - ������� -1 
	}
	else
	{
	for (i = 0; i<z; i++)
	  {
		if (c->v>0)
		{
			struct stack*d = c;
			f = c->v;
			y = y->next;
			break;
		}
		c = c->next;
		y = y->next;
	   }
	}
	if (z == i)
	{
		return -1;
	}
	delete c;
	if (z == 2)
	{
		MyStk->head = y;
		z--;
		return f;
	}
	else
	{
		if (i==0)
		{
			MyStk->head = y;
			z--;
			return f;
		}
		else
		{
			if (y == NULL)
			{
				MyStk->head->next->next = NULL;
				z--;
				return f;
			}
			else
			{
				z--;
				MyStk->head->next = y;
				return f;
			}
		}
	}
}