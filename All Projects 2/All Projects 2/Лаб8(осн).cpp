#include "Header.h"
#include "�8����.h"
using namespace std;
int m = 0;
int kkk;
int k2[10];
void main11()
{
	setlocale(LC_ALL, "Rus");
	stack *MyStk = new stack; //��������� ������ ��� �����w+
	MyStk->head = NULL;       //������������� ������� ��������	
	for (;;)
	{
		cout << "������ �� ������. �������� �������:" << endl;
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ���������� �������� �� �����" << endl;
		cout << "3 - ����� �����" << endl;
		cout << "4 - ������� ������" << endl;
		cout << "5 - ������ � ����" << endl;
		cout << "6 - ����� �� �����" << endl;
		cout << "7 - �������" << endl;
		cout << "8 - �����" << endl;
		cin >> kkk;
		switch (kkk)
		{
		case 1:
		{cout << "������� ������� ��� �������: " << endl;
		cin >> kkk;
		k2[m] = kkk;
		m++;
		push(kkk, MyStk);
		break;
		}
		case 2:
		{
			kkk = pop(MyStk);
			m--;
			if (kkk != -1) cout << "����������� �������: " << kkk << endl;
			break;
		}
		case 3:
		{
			cout << "���� ����: " << endl;
			show(MyStk);
			break;
		}
		case 4:
		{
			Clear(MyStk);
			break;
		}
		case 8:
		{
			return;
			break;
		}
		case 5:
		{
			Zapis(MyStk);
			break;
		}
		case 6:
		{
			Viv(MyStk);
			break;
		}
		case 7:
		{
			Funcc(MyStk);
			break;
		}
	}
  }
}