#include "Header.h"
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int STREET_SIZE = 40;
const unsigned int CITY_SIZE = 20;
int L = 0;
struct Address
{
	char name[NAME_SIZE];
	char street[STREET_SIZE];
	char city[CITY_SIZE];
	Address *next;
	Address *prev;

};
int menu(void)
{
	char s[80];
	int c;
	cout << "1. ���� �����" << endl;
	cout << "2. �������� �����" << endl;
	cout << "3. ����� �� �����" << endl;
	cout << "4. �����" << endl;
	cout << "5. ��������� � ����" << endl;
	cout << "6. ��������� �� �����" << endl;
	cout << "7. �������� ������������� ���������" << endl;
	cout << "8. �����" << endl; cout << endl;
	do
	{
		cout << "��� �����: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 7);
	return c;

}
void create(Address *i, Address **phead, Address **plast)
{
	Address *old = NULL, *p = *phead;
	if (*plast == NULL)
	{
		i->next = NULL;
		i->prev = NULL;
		*plast = i;
		*phead = i;
		return;
	}
	while (p)
	{
		if (strcmp(p->name, i->name) < 0)
		{
			old = p;
			p = p->next;
		}
		else
		{
			if (p->prev)
			{
				p->prev->next = i;
				i->next = p;
				i->prev = p->prev;
				p->prev = i;
				return;
			}
			i->next = p;
			i->prev = NULL;
			p->prev = i;
			*phead = i;
			return;
		}
	}
	old->next = i;
	i->next = NULL;
	i->prev = old;
	*plast = i;
	L++;
}

Address* setElement()      
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "������ ��������� ������";
		return NULL;
	}
	cout << "������� ���: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �����: ";
	cin.getline(temp->street, STREET_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �����: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputList(Address **phead, Address **plast)     
{
	Address *t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->street
			<< ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
void find(char name[NAME_SIZE], Address **phead)    
{
	Address *t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))
			break;
		t = t->next;
	}
	if (!t)
		cerr << "��� �� �������" << endl;
	else
		cout << t->name << ' ' << t->street << ' ' << t->city << endl;
}
void delet(char name[NAME_SIZE], Address **phead, Address **plast) 
{
	struct Address *t = *phead;

	while (t)
	{
		if (!strcmp(name, t->name))
			break;
		t = t->next;
	}
	if (t)
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		} delete t;
	}
}
void writeToFile(Address **phead)     
{
	struct Address *t = *phead;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "���������� � ����" << endl;

	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
void readFromFile(Address **phead, Address **plast)         
{
	struct Address *t;
	FILE *fp;
	errno_t err = fopen_s(&fp, "ab.txt", "rb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete *phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "�������� �� �����" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "������ ��������� ������ ������" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp))
			break;
		create(t, phead, plast);
	}
	fclose(fp);

}
int DeleteDouble(Address **phead, Address **plast)
{
	int i, c = 0, m = 0, n = 0,bb=0;
	struct Address *t = *phead;
	struct Address *zz = *plast;
	for (i = 0; t->next != NULL; i++)
	{
		c++;
		t = t->next;
	}
	t = *phead;
	while (t)
	{
		if (t == zz)
		{
			return 0;
		}
		else
		{
			for (i = 0; i < c; i++)
			{
				if ((strcmp(t->name, t->next->name) == 0) || (strcmp(t->street, t->next->street) == 0) || (strcmp(t->city, t->next->city) == 0))
				{
					if(c<2)
					{
						bb++;
						break;
					}
					else
					{
						m++;
						break;
					}
				}
				if ((strcmp(t->name, zz->name) == 0) || (strcmp(t->street, zz->street) == 0) || (strcmp(t->city, zz->city) == 0))
				{
					if (t == zz)
					{
						return 0;
					}
					n++;
					break;
				}
				t = t->next;
			}
		}
		if (m == 1)
		{
			break;
		}
		if (n == 1)
		{
			break;
		}
		if (bb == 1)
		{
			break;
		}
	}
	if (t)
	{
		if (m == 1)
		{

			*phead = NULL;
			*plast = NULL;
			if (t->prev == NULL)
			{
				t->next->next->next = NULL;
				*phead = t->next->next;
				*plast = t->next->next;
				L = L - 2;
			}
			else
			{
				t->prev->next = NULL;
				*phead = t->prev;
				*plast = t->prev;
				L = L - 2;
			}
		}
		else
		{
			if (n == 1)
			{
				*phead = NULL;
				*plast = NULL;
				t->next->next = NULL;
				t->next->prev = NULL;
				*phead = t->next;
				*plast = t->next;
				L = L - 2;
			}
			else
			{
					*phead = NULL;
					*plast = NULL;
					if (L > 1)
					{
						L = L - 2;
					}
			}
		}
	}
}
int main9(void)
{
	Address *head = NULL;
	Address *last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1: 
		{
			if (L >= 3)
			{
				cout << "������ ��������� ������!" << endl;
				break;
				cout << endl;
			}
			create(setElement(), &head, &last);
		}
				break;
		case 2: {
			char dname[NAME_SIZE];
			cout << "������� ���: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
				break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {
			char fname[NAME_SIZE];
			cout << "������� ���: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
				break;
		case 5:  writeToFile(&head);
			break;
		case 6:  readFromFile(&head, &last);
			break;
		case 7: {
			DeleteDouble(&head,&last);
		}
				break;
		case 8:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
