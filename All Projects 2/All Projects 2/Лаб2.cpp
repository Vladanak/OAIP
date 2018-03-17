#include "Header.h"
# define str_len 50                             
# define size 30  
int change;
using namespace std;
struct Client
{
	string name;
	char tipscheta[str_len];
	int nomerscheta;
	int summa;
	char data[str_len];
};

struct Client list[size];
struct Client bad;
int kolich = 0;

void enter_new()
{
	cout << "���� ����������:" << endl;
	if (kolich < size)
	{
		cout << "������ �����:";
		cout << kolich + 1;
		cout << endl << "�.�.�.:" << endl;
	    cin.ignore();
		getline(cin, list[kolich].name);
		cout << "��� �����(�������, ��������,�������):" << endl;
		cin >> list[kolich].tipscheta;
		cout << "����� �����:" << endl;
		cin >> list[kolich].nomerscheta;
	    cout << "��������� ����� �� ����:" << endl;
		cin >> list[kolich].summa;
		cout << "���� ����������:" << endl;
		cin >> list[kolich].data;
		kolich++;
	}
	else
	{
		cout << "������� ������������ ���-�� �����";
	}
	cout << "��� ������?" << endl;
	cin >> change;
}

void Ydalenie()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < kolich; de1++)
			list[de1] = list[de1 + 1];
		kolich = kolich - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list[i] = bad;
	cout << "��� ������?" << endl;
	cin >> change;
}

void Izmenit()
{
	int n, per,dob;
	cout << "\n������� ����� ������" << endl; 	cin >> n;
	do
	{
		cout << "�������:" << endl;
		cout << "1-��� ��������� �.�.�." << endl;
		cout << "2-��� ��������� ���� �����" << endl;
		cout << "3-��� ��������� ������ �����" << endl;
		cout << "4-��� ��������� ����� �����" << endl;
		cout << "5-��� ��������� ����" << endl;
		cout << "6-��� ���������� ����� (��� ������) ��(�) ����" << endl;
		cout << "7-�����\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "����� �.�.�.:";
			cin.ignore();
			getline(cin, list[n-1].name);   break;
		case 2: cout << "����� ��� �����:";
			cin >> list[n - 1].tipscheta; break;
		case 3: cout << "����� ����� �����:";
			cin >> list[n - 1].nomerscheta; break;
		case 4: cout << "����� ����� �����:";
			cin >> list[n - 1].summa; break;
		case 5:cout << "����� ���� ���������:";
			cin >> list[n - 1].data; break;
		case 6:
			puts("1-����������,2-������");
			cin >> per;
			switch (per)
			{
			case 1:
			{
				cout << "������� �������� ����� �� ����?" << endl;
				cin >> dob;
				list[n - 1].summa += dob;
				break;
			}
			case 2:
			{
				cout << "������� ����� ����� �� �����?" << endl;
				cin >> dob;
				list[n - 1].summa -= dob;
				break;
			}
			}
		default:
		{
			cout << "�������� ����� �� 1 �� 7!" << endl;
			break;
			Izmenit();
		}
		}
	} while (per != 7);
	cout << "��� ������?" << endl;
	cin >> change;
}

void Vivesti()
{
	int sw, n;
	cout << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ " << endl;   cin >> n;  cout << endl;
		cout << "�.�.�.:";
		cout << list[n - 1].name << endl;
		cout << "��� �����:";
		cout << list[n - 1].tipscheta << endl;
		cout << "����� �����:";
		cout << list[n - 1].nomerscheta << endl;
		cout << "��������� �����:" << endl;
		cout << list[n - 1].summa << endl;
		cout << "���� ���������: " << list[n-1].data << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < kolich; i++)
		{
			cout << "�.�.�.:";
			cout << list[i].name << endl;
			cout << "��� �����:";
			cout << list[i].tipscheta << endl;
			cout << "����� �����:";
			cout << list[i].nomerscheta << endl;
			cout << "��������� �����:" << endl;
			cout << list[i].summa << endl;
			cout << "���� ���������: " << list[i].data<< endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
		cout << "�������� ����� �� 1 �� 2!" << endl;
		Vivesti();
	}
	cout << "��� ������?" << endl;
	cin >> change;
}
void Poisk()
{
	int x;
	cout << endl << "1 - ����� �� ������ �����" << endl;
	cout << "2 - ����� �� ��������� �������� �����" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		int temp;
		bool fl = false;
		cout << "������� ����� ����� �� �������� ������ ��������� �����: ";
		cin >> temp;
		for (int i = 0; i <= kolich; i++)
		{
			if (list[i].nomerscheta == temp)
			{
				cout << endl << "������� �" << i + 1;
				cout << endl << "�.�.� �������: " << list[i].name;
				cout << endl << "��� �����: " << list[i].tipscheta;
				cout << endl << "����� �� �����: " << list[i].summa;
				cout << endl << "���� ��������� �����: " << list[i].data;
				cout << endl;
				fl = true;
			}
		}
		if (fl == false)
		{
			cout << endl << "��� ������ ������ �����";
		}
		break;
	}
	case 2: {
		int a, b, c;
		bool f2 = false;
		cout << "������� �������� ����� �� �������� ������ ��������: ";
		cout << endl;
		cout << "������� a: ";
		cin >> a;
		cout << "������� b: ";
		cin >> b;
		cout << "1-a>����� � b>�����;\n2-a<����� � b>����� ";
		cin >> c;
		switch (c) {
		case 1:
		{
			for (int i = 0; i <= kolich; i++)
			{
				if (list[i].summa < a && b > list[i].summa)
				{
					cout << endl << "������� �" << i + 1;
					cout << endl << "�.�.� �������: " << list[i].name;
					cout << endl << "��� �����: " << list[i].tipscheta;
					cout << endl << "����� �� �����: " << list[i].summa;
					cout << endl << "���� ��������� �����: " << list[i].data;
					cout << endl;
					f2 = true;
				}
				else
					break;
			}
			if (f2 == false)
			{
				cout << endl << "��� ����� ���������";
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i <= kolich; i++)
			{
				if (list[i].summa > a && b > list[i].summa)
				{
					cout << endl << "������� �" << i + 1;
					cout << endl << "�.�.� �������: " << list[i].name;
					cout << endl << "��� �����: " << list[i].tipscheta;
					cout << endl << "����� �� �����: " << list[i].summa;
					cout << endl << "���� ��������� �����: " << list[i].data;
					cout << endl;
					f2 = true;
				}
			}
			if (f2 == false)
			{
				cout << endl << "��� ����� ���������";
			}
			break;
		}
		}
	}
	default:
	{
		cout << "�������� ����� �� 1 �� 2!" << endl;
		Poisk();
	}
	}
	cout << endl << "��� ������?" << endl;
	cin >> change;
}
int main3()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	cout << "������ ���" << endl;
	cout << "�������:" << endl;
	cout << "1-��� �������� ������" << endl;
	cout << "2-��� ����� ����� ������" << endl;
	cout << "3-��� ��������� ������" << endl;
	cout << "4-��� ������ ������(��)" << endl;
	cout << "5-����� ����������" << endl;
	cout << "6-��� ������" << endl;
	cin >> change;
	do
	{
		switch (change)
		{
		case 1:  Ydalenie();	break;
		case 2:  enter_new();  break;
		case 3:  Izmenit();  break;
		case 4:  Vivesti();	break;
		case 5: Poisk(); break;
		default:
		{
			cout << "�������� ����� �� 1 �� 6!" << endl;
			main3();
		}
		}
	} while (change != 6);
	return 0;
}