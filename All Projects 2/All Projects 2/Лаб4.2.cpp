#include "Header.h"
using namespace std;
# define str_len 50                             
# define si 30  
int chan;
using namespace std;
typedef struct Lombard
{
	char name[19];
	char tovar[5];
	char cena[4];
	char zalog[5];
	char data[12];
	char srok[6];
} LOM;
FILE *file;
struct Lombard list[si];
struct Lombard bad;
int kolkov = 0;

void neww()
{
	cout << "���� ����������:" << endl;
	if (kolkov < si)
	{
		cout << "������ �����:";
		cout << kolkov + 1;
		cout << endl << "�������:" << endl;
		cin >> list[kolkov].name;
		cout << "������������ ������:" << endl;
		cin >> list[kolkov].tovar;
		cout << "���� ������:" << endl;
		cin >> list[kolkov].cena;
		cout << "�����,�������� ��� �����:" << endl;
		cin >> list[kolkov].zalog;
		cout << "���� ����������:" << endl;
		cin >> list[kolkov].data;
		cout << "���� ��������(����):" << endl;
		cin >> list[kolkov].srok;
		kolkov++;
	}
	else
	{
		cout << "������� ������������ ���-�� �����";
	}
	cout << "��� ������?" << endl;
	cin >> chan;
}

void YDAL()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < kolkov; de1++)
			list[de1] = list[de1 + 1];
		kolkov = kolkov - 1;
	}
	if (d == 99)
		for (int i = 0; i < si; i++)
			list[i] = bad;
	cout << "��� ������?" << endl;
	cin >> chan;
}

void IZMEN()
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
			cin >> list[n-1].name;;   break;
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
			IZMEN();
		}
		}
	} while (per != 7);
	cout << "��� ������?" << endl;
	cin >> chan;
}

void VIVOD()
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
		for (int i = 0; i < kolkov; i++)
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
		VIVOD();
	}
	cout << "��� ������?" << endl;
	cin >> chan;
}
void Searching()
{
	int x;
	cout << endl << "1 - ����� �� ������������ ������" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		char temp[30];
		bool fl = false;
		cout << "������� ������������ ������ �� �������� ��������� �����: ";
		cin >> temp;
		for (int i = 0; i <= kolkov; i++)
		{
			if (strcmp(list[i].tovar ,temp)==0)
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
			cout << endl << "��� ������ ������ �����";
		}
		break;
	}
	default:
	{
		cout << "�������� ����� 1!" << endl;
		Searching();
	}
	}
	cout << endl << "��� ������?" << endl;
	cin >> chan;
}
void Infa()
{
	setlocale(LC_ALL, "Russian");
	LOM tr;
	if (!fopen_s(&file, "a.txt", "rb"))
	{
		fread(&tr, sizeof(tr), 1, file);
			cout << tr.name << endl<< tr.tovar << endl<< tr.cena << endl<< tr.zalog << endl<< tr.data << endl<< tr.srok << endl;
			fread(&tr, sizeof(tr), 1, file);
		cout << endl;
		fclose(file);
	}
	else {
		cout << "OSIBKA";
		return;
	}
	cout << endl << "��� ������?" << endl;
	cin >> chan;
}
void input(int size)
{
	setlocale(LC_ALL, "Russian");
	LOM buf = { ' ', ' ', ' ', ' ',' ',' ' };
	if (!fopen_s(&file, "a.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "�������: ";
			cin >> buf.name;
			cout << "������������ ������: ";
			cin >> buf.tovar;
			cout << "���������: ";
			cin >> buf.cena;
			cout << "�����: ";
			cin >> buf.zalog;
			cout << "����: ";
			cin >> buf.data;
			cout << "���� ��������: ";
			cin >> buf.srok;
			fwrite(&buf, sizeof(buf), 1, file);
		}
		fclose(file);
	}
	else {
		cout << "������ �������� �����";
		return;
	}
	cout << endl << "��� ������?" << endl;
	cin >> chan;
}
int main6()
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
	cin >> chan;
	do
	{
		switch (chan)
		{
		case 1:  YDAL();	break;
		case 2:  neww();  break;
		case 3:  IZMEN();  break;
		case 4:  VIVOD();	break;
		case 5: Searching(); break;
		case 6: Infa(); break;
		case 7: input(1); break;
		default:
		{
			cout << "�������� ����� �� 1 �� 8!" << endl;
			main6();
		}
		}
	} while (chan != 8);
	return 0;
}