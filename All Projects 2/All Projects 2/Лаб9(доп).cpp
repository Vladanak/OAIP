#include"�9����.h"
using namespace std;
item *head, *tail;
item *head1, *tail1;
item *head2, *tail2;
int y, ll = 0;
bool isnull(void)  //�������� �� �������
{
	return (head == NULL);
}
void add1(int z)          //���������� �������� � ������� 
{
	item *p = new item;      //����� ��������� 
	p->data = z;
	p->next = NULL;
	item *v = new item;      //��������� ��� ������ �����
	item *p1 = new item;
	item *p2 = new item;
	int i = 0;                          // ������
	if (head1==NULL) head1 = tail1 = p;
	else
	{
		p2 = head1;
		p1 = head1;
		while (p1 != NULL) //���� ������� �� ����������
		{
			if (i == 1)
			{
				p2 = p2->next;  // ��������� �����
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail1->next = p;
			tail1 = p;
		}
	}
}
void out1()             //����� �������
{
	item *p = new item;
	item *n = new item;
	if ((head1==NULL)||(head2==NULL))
		cout << "���� �� �������� �����" << endl;
	else
	{
		p = head1;
		n = head2;
		cout << "������� 1:" << endl;
		while (head1!=NULL)
		{
			if (p != NULL)
			{
				cout << p->data << " ";
				cout << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				break;
			}
		}
		cout << "������� 2:" << endl;
		while (head2 != NULL)
		{
			if (n != NULL)
			{
				cout << n->data << " ";
				cout << "->";
				n = n->next;
			}
			else
			{
				cout << "NULL" << endl;
				break;
			}
		}
	}
}
void add2(int y)          //���������� �������� � ������� 
{
	item *p = new item;      //����� ��������� 
	p->data = y;
	p->next = NULL;
	item *v = new item;      //��������� ��� ������ �����
	item *p1 = new item;
	item *p2 = new item;
	int i = 0;                          // ������
	if (head2==NULL) head2 = tail2 = p;
	else
	{
		p2 = head2;
		p1 = head2;
		while (p1 != NULL) //���� ������� �� ����������
		{
			if (i == 1)
			{
				p2 = p2->next;  // ��������� �����
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail2->next = p;
			tail2 = p;
		}
	}
}
void delet1()        //���������� �������� �� ������
{
	if (isnull())
		cout << "������� �����" << endl;
	else
	{
		item *p = head;
		head = head->next;
		delete p;
	}
}
void fromhead()     //��������� �������� �� ������
{
	if (isnull())  cout << "������� �����" << endl;
	else              cout << "������ = " << head->data << endl;
}
void add(int x)          //���������� �������� � ������� 
{
	y++;
	item *p = new item;      //����� ��������� 
	p->data = x; 
	p->next = NULL;
	item *v = new item;      //��������� ��� ������ �����
	item *p1 = new item;
	item *p2 = new item;
	int i = 0;                          // ������
	if (isnull()) head = tail = p;
	else
	{
		p2 = head;
		p1 = head;
		while (p1 != NULL) //���� ������� �� ����������
		{
			if (i == 1)
			{
				p2 = p2->next;  // ��������� �����
			}
			p1 = p1->next;  
			i = 1;
		}
		if (p1 == NULL) 
		{
			tail->next = p;
			tail = p;
		}
	}
}
void out()             //����� �������
{
	item *p = new item;
	if (isnull())
		cout << "������� �����" << endl;
	else
	{
		cout << "������� = ";
		p = head;
		while (!isnull())
		{
			if (p != NULL)
			{ 
				cout << p->data << " ";
				cout << "->"; 
				p = p->next; 
			}
			else
			{
				cout << "NULL" << endl;  
				return;
			}
		}
	}
}
void clrscr() //������� �������
{
	while (!isnull())
		delet1();
}
void delenie()
{
	if (isnull())
		cout << "������� �����" << endl;
	else
	{
		while (head!=NULL)
		{
			if (head->data > 0)
			{
				add1(head->data);
				head = head->next;
			}
			else
			{
				add2(head->data);
				head = head->next;
			}
		}
		out1();
	}
}