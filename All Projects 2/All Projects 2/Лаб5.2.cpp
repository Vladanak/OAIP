#include "Header.h"
using namespace std;
# define str_len 50                             
# define si 30  
int cha;
using namespace std;
typedef union Lomb
{
	char name[19];
	char tovar[5];
	char cena[4];
	char zalog[5];
	char data[12];
	char srok[6];
} LOMD;
union Lomb list[si];
union Lomb bad;
int kolo = 0;

void N()
{
	cout << "���� ����������:" << endl;
	if (kolo < si)
	{
		cout << "������ �����:";
		cout << kolo + 1;
		cout << endl << "�������:" << endl;
		cin >> list[kolo].name;
		cout << "������������ ������:" << endl;
		cin >> list[kolo].tovar;
		cout << "���� ������:" << endl;
		cin >> list[kolo].cena;
		cout << "�����,�������� ��� �����:" << endl;
		cin >> list[kolo].zalog;
		cout << "���� ����������:" << endl;
		cin >> list[kolo].data;
		cout << "���� ��������(����):" << endl;
		cin >> list[kolo].srok;
		kolo++;
	}
	else
	{
		cout << "������� ������������ ���-�� �����";
	}
	cout << "��� ������?" << endl;
	cin >> cha;
}

void Y()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < kolo; de1++)
			list[de1] = list[de1 + 1];
		kolo = kolo - 1;
	}
	if (d == 99)
		for (int i = 0; i < si; i++)
			list[i] = bad;
	cout << "��� ������?" << endl;
	cin >> cha;
}

void I()
{
	int n, per, dob;
	cout << "\n������� ����� ������" << endl; 	cin >> n;
	do
	{
		cout << "�������:" << endl;
		cout << "1-��� ��������� �.�.�." << endl;
		cout << "2-��� ��������� ������������ ������" << endl;
		cout << "3-��� ��������� ���������" << endl;
		cout << "4-��� ��������� ����� ������" << endl;
		cout << "5-��� ��������� ����" << endl;
		cout << "6-��� ��������� ����� ��������" << endl;
		cout << "7-�����\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "����� �������:";
			cin.ignore();
			cin >> list[n - 1].name;;   break;
		case 2: cout << "����� ������������ ������:";
			cin >> list[n - 1].tovar; break;
		case 3: cout << "����� ���������:";
			cin >> list[n - 1].cena; break;
		case 4: cout << "����� ����� ������:";
			cin >> list[n - 1].zalog; break;
		case 5:cout << "����� ����:";
			cin >> list[n - 1].data; break;
		case 6:cout << "����� ���� ��������:";
			cin >> list[n - 1].srok; break;
		default:
		{
			cout << "�������� ����� �� 1 �� 7!" << endl;
			break;
			I();
		}
		}
	} while (per != 7);
	cout << "��� ������?" << endl;
	cin >> cha;
}

void V()
{
	int sw, n;
	cout << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ " << endl;   cin >> n;  cout << endl;
		cout << "�������:";
		cout << list[n - 1].name << endl;
		cout << "������������ ������:";
		cout << list[n - 1].tovar << endl;
		cout << "���������:";
		cout << list[n - 1].cena << endl;
		cout << "����� ������:" << endl;
		cout << list[n - 1].zalog << endl;
		cout << "����: " << list[n - 1].data << endl;
		cout << "���� ��������:" << endl;
		cout << list[n - 1].srok << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < kolo; i++)
		{
			cout << "�������:";
			cout << list[i].name << endl;
			cout << "������������ ������:";
			cout << list[i].tovar << endl;
			cout << "���������:";
			cout << list[i].cena << endl;
			cout << "����� ������:" << endl;
			cout << list[i].zalog << endl;
			cout << "����: " << list[i].data << endl;
			cout << "���� ��������:" << endl;
			cout << list[i].srok << endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
		cout << "�������� ����� �� 1 �� 2!" << endl;
		V();
	}
	cout << "��� ������?" << endl;
	cin >> cha;
}
void S()
{
	int x;
	cout << endl << "1 - ����� �� ������������ ������" << endl;
	cout << endl << "2 - ����� �� ����� ��������" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		char temp[30];
		bool fl = false;
		cout << "������� ������������ ������ �� �������� ��������� �����: ";
		cin >> temp;
		for (int i = 0; i <= kolo; i++)
		{
			if (strcmp(list[i].tovar, temp) == 0)
			{
				cout << endl << "������� �" << i + 1;
				cout << endl << "�������: " << list[i].name;
				cout << endl << "������������ ������: " << list[i].tovar;
				cout << endl << "���������: " << list[i].cena;
				cout << endl << "����� ������: " << list[i].zalog;
				cout << endl << "����: " << list[i].data;
				cout << endl << "���� ��������: " << list[i].srok;
				cout << endl;
				fl = true;
			}
		}
		if (fl == false)
		{
			cout << endl << "��� ������ ������";
		}
		break;
	}
	case 2:
	{
		char chislo[30];
		bool f2 = false;
		cout << "������� ���� �������� �� �������� ��������� �����: ";
		cin >> chislo;
		for (int a = 0; a <= kolo; a++)
		{
			if (strcmp(list[a].srok, chislo) == 0)
			{
				cout << endl << "������� �" << a + 1;
				cout << endl << "�������: " << list[a].name;
				cout << endl << "������������ ������: " << list[a].tovar;
				cout << endl << "���������: " << list[a].cena;
				cout << endl << "����� ������: " << list[a].zalog;
				cout << endl << "����: " << list[a].data;
				cout << endl << "���� ��������: " << list[a].srok;
				cout << endl;
				f2 = true;
			}
		}
		if (f2 == false)
		{
			cout << endl << "��� ������ !";
		}
		break;
	}
	default:
	{
		cout << "�������� ����� 1 ��� 2!" << endl;
		S();
	}
	}
	cout << endl << "��� ������?" << endl;
	cin >> cha;
}
void inPut( int sizes)
{
	ofstream lol;
	lol.open("DATA.txt", ios_base::out);
	LOMD T = { ' ' };
	for (int o = 0; o < sizes; o++)
	{
		cout << "�������:";
		cin >> T.name;
		lol.write((char*)&T, sizeof(T));
		cout << "������������ ������:";
		cin >> T.tovar;
		lol.write((char*)&T, sizeof(T));
		cout << "���������:";
		cin >> T.cena;
		lol.write((char*)&T, sizeof(T));
		cout << "����� ������:";
		cin >> T.zalog;
		lol.write((char*)&T, sizeof(T));
		cout << "����:";
		cin >> T.data;
		lol.write((char*)&T, sizeof(T));
		cout << "���� ��������:";
		cin >> T.srok;
		lol.write((char*)&T, sizeof(T));
		cout << endl << "��� ������?" << endl;
		cin >> cha;
	}
}
void outPut()
{
	ifstream in("DATA.txt");
	while (!in.eof())
	{
		LOMD T = { ' ' };
		cout << "�������:";
		in.read((char *)&T, sizeof(T));
		cout << T.name << "\t    ";
		cout << "������������ ������:";
		in.read((char *)&T, sizeof(T));
		cout << T.tovar << endl;
		cout << "���������:";
		in.read((char *)&T, sizeof(T));
		cout << T.cena << endl;
		cout << "����� ������:";
		in.read((char *)&T, sizeof(T));
		cout << T.zalog << endl;
		cout << "����:";
		in.read((char *)&T, sizeof(T));
		cout << T.data << endl;
		cout << "���� ��������:";
		in.read((char*)&T, sizeof(T));
		cin >> T.srok;
	}
	cout << endl << "��� ������?" << endl;
	cin >> cha;
}

int main8()
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
	cout << "6-���������� ���������� � �����" << endl;
	cout << "7-������ ���������� � ����" << endl;
	cout << "8-��� ������" << endl;
	cin >> cha;
	do
	{
		switch (cha)
		{
		case 1:  Y();  break;
		case 2:  N();  break;
		case 3:  I();  break;
		case 4:  V();  break;
		case 5:  S();  break;
		case 6: outPut(); break;
		case 7: inPut(1); break;
		default:
		{
			cout << "�������� ����� �� 1 �� 8!" << endl;
			main8();
		}
		}
	} while (cha != 8);
	return 0;
}