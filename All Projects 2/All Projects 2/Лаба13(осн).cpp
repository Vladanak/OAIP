#include "�13����.h"
#include "Header.h"
using namespace std;
double b = 0;
clock_t dtime;
struct AAA
{
	int key;
	char *mas;
	AAA(int k, char*z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------

int _tmain433(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	AAA a1(1, "one"), a2(2, "two"), a3(4, "three"), a4(2, "fo");
	int siz = 10;
	cout << "������� ������ ���-�������" << endl;
	cin >> siz;
	Object H = create(siz, key);   //�������	
	int choice;  int k;
	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "5 - ����������� ���������� ���-�������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			H.scan(AAA_print);
			break;
		case 2:
		{b++;
		AAA *a = new AAA;
		char *str = new char[20];
		cout << "������� ����" << endl;
		cin >> k;
		a->key = k;
		cout << "������� ������" << endl;
		cin >> str; a->mas = str;
		if (H.N == H.size)
		{ b--;  cout << "������� ���������" << endl;}
		else
			H.insert(a);
		}  break;
		case 3:
		{	b--;
			cout << "������� ���� ��� ��������" << endl;
		cin >> k;
		H.deleteByKey(k);
		}  break;
		case 4:
		{
		cout << "������� ���� ��� ������" << endl;
		cin >> k;
		if (H.search(k) == NULL)
			cout << "������� �� ������" << endl;
		else
		{
			dtime = clock();
			AAA_print(H.search(k));
			dtime = clock() - dtime;
			cout << dtime<<endl;
		}
		}
		break;
		case 5: double z = b / siz * 100; cout << "����������� ����� " << z << " %" << endl;  break;
		}
	}
	return 0;
}
