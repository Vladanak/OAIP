#include "Header.h"
using namespace std;
# define str_len 50                             
# define size 30  
int ch;
enum predmet {
	Matra=1, Russki, Angliski, Istoria
}Pr;
struct Uchenik
{
	char bykv;
	unsigned cifra : 4;
    string name;
	string predmet;
	string ocenki;
	double sredni;
};
struct Uchenik list[size];
struct Uchenik bad;
int kol = 0;
Uchenik a[5];
void ent()
{
	char bykv;
	int cifra,d;
	cout << "���� ����������:" << endl;
	if (kol < size)
	{
		cout << "������ �����:";
		cout << kol + 1;
		cout << endl << "�.�.�.:" << endl;
		cin.ignore();
		getline(cin, list[kol].name);
		cout << "����� � ������(������� �����,� ����� �����):" << endl;
		cin >> cifra;
	    cin>>list[kol].bykv;
		a[kol].cifra = cifra;
		cout << "��������(1-Matra,2-Russki,3-Angliski,4-Istoria):" << endl;
		cin >> d;
		switch (d)
		{
		case(Matra):{
				a[kol].predmet = "����������";
				break;
			}
		case(Russki): {
			a[kol].predmet = "�������";
			break;
		}
		case(Angliski): {
			a[kol].predmet = "����������";
			break;
		}
		case(Istoria): {
			a[kol].predmet = "�������";
			break;
		}
		}
		cout << "������:" << endl;
		cin.ignore();
		getline(cin, list[kol].ocenki);
		cout << "������� ����:" << endl;
		cin >> list[kol].sredni;
		kol++;
	}
	else
	{
		cout << "������� ������������ ���-�� �����";
	}
	cout << "��� ������?" << endl;
	cin >> ch;
}

void del()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < kol; de1++)
			list[de1] = list[de1 + 1];
		kol = kol - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list[i] = bad;
	cout << "��� ������?" << endl;
	cin >> ch;
}

void Izm()
{
	int n, per, dob,cifra,d;
	char bykv;
	cout << "\n������� ����� ������" << endl; 	cin >> n;
	do
	{
		cout << "�������:" << endl;
		cout << "1-��� ��������� �.�.�." << endl;
		cout << "2-��� ��������� ������" << endl;
		cout << "3-��� ��������� ��������" << endl;
		cout << "4-��� ��������� ������" << endl;
		cout << "5-��� ��������� �������� �����" << endl;
		cout << "6-�����\n";
		cin >> per;
		switch (per)
		{
		case 1: {
			cout << "����� �.�.�.:";
			cin.ignore();
			getline(cin, list[n-1].name);  
			break;
		}
		case 2:
		{
			cout << "����� �����(������� �����,� ����� �����):";
			cin >> cifra >> list[n-1].bykv;
			a[n-1].cifra = cifra;
			break;
		}
		case 3:
		{
			cout << "����� �������(1-Matra,2-Russki,3-Angliski,4-Istoria):";
			cin >> d;
			switch (d)
			{
			case(Matra): {
				a[n-1].predmet = "����������";
				break;
			}
			case(Russki): {
				a[n-1].predmet = "�������";
				break;
			}
			case(Angliski): {
				a[n-1].predmet = "����������";
				break;
			}
			case(Istoria): {
				a[n-1].predmet = "�������";
				break;
			}
			}
			break;
		}
		case 4:
		{
			cout << "����� ������ �� ��������:";
			cin.ignore();
			getline(cin, list[n-1].ocenki);
			break;
		}
		case 5:
		{
			cout << "����� ������� ����:";
			cin >> list[n-1].sredni;
			break;
		}
		default:
		{
			cout << "�������� ����� �� 1 �� 6!" << endl;
			break;
			Izm();
		}
			}
		
	} while (per != 6);
	cout << "��� ������?" << endl;
	cin >> ch;
}

void Vive()
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
		cout << "�����:";
		cout << a[n - 1].cifra<<" "<< list[n-1].bykv << endl;
		cout << "�������:";
		cout << a[n - 1].predmet << endl;
		cout << "������ �� ��������:" << endl;
		cout << list[n - 1].ocenki << endl;
		cout << "������� ����: " << list[n - 1].sredni << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < kol; i++)
		{
			cout << "����� ��������� ������ " << endl; 
			cout << "�.�.�.:";
			cout << list[i].name << endl;
			cout << "�����:";
			cout << a[i].cifra << " " << list[i].bykv << endl;
			cout << "�������:";
			cout << a[i].predmet << endl;
			cout << "������ �� ��������:";
			cout << list[i].ocenki << endl;
			cout << "������� ����: " << list[i].sredni << endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
			cout << "�������� ����� �� 1 �� 2!" << endl;
			Vive();
	}
	cout << "��� ������?" << endl;
	cin >> ch;
}
void Poi()
{
	int x;
	cout << endl << "1 - ����� �� �.�.�." << endl;
	cout << "2 - ����� �� �������� �����." << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		string temp;
		bool fl = false;
		cout << "������� �.�.�. �� �������� ������ ��������� �����: ";
		cin.ignore();
		getline(cin, temp);
		for (int i = 0; i <= kol; i++)
		{
			if (list[i].name==temp)
			{
				cout << endl << "������� �" << i + 1;
				cout << endl << "�.�.�: " << list[i].name;
				cout << endl << "�����: " << a[i].cifra << " " << list[i].bykv;
				cout << endl << "�������:" << a[i].predmet;
				cout << endl << "������ �� ��������: " << list[i].ocenki;
				cout << endl << "������� ����: " << list[i].sredni;
				cout << endl;
				fl = true;
			}
		}
		if (fl == false)
		{
			cout << endl << "��� ��������� � ����� �.�.�!";
		}
		break;
	}
	case 2: {
		int n;
		bool f2 = false;
		cout << "������� ������� ���� �� �������� ������: " << endl;
		cin >> n;
			for (int i = 0; i <= kol; i++)
			{
				if (list[i].sredni == n)
				{
					cout << endl << "������� �" << i + 1;
					cout << endl << "�.�.�: " << list[i].name;
					cout << endl << "�����: " << a[i].cifra << " " << list[i].bykv;
					cout << endl << "�������:" << a[i].predmet;
					cout << endl << "������ �� ��������: " << list[i].ocenki;
					cout << endl << "������� ����: " << list[i].sredni;
					cout << endl;
					f2 = true;
				}
			}
			if (f2 == false)
			{
				cout << endl << "��� ��������� � ����� ������� ������!";
			}
			break;
	}
	default:
	{
		cout << "�������� ����� �� 1 �� 2!" << endl;
		Poi();
	}
	}
	cout << endl << "��� ������?" << endl;
	cin >> ch;
}
int main4()
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
	cin >> ch;
	do
	{
		switch (ch)
		{
		case 1: del();	break;
		case 2:  ent();  break;
		case 3:  Izm();  break;
		case 4:  Vive();	break;
		case 5:  Poi(); break; 
		default: 
		{
			cout << "�������� ����� �� 1 �� 6!" << endl;
			main4();
		}
		}
	} while (ch != 6);
	return 0;
} 
