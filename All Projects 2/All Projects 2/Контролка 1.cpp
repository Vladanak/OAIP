#include "Header.h"
using namespace std;
# define str_len 30                             
# define size 10  
int Change2;
typedef struct Stud
{
	unsigned data : 8;
	string name;
	char spec[str_len];
	int gruppa;
	string fakylt;
}STUD;
struct Stud list[size];
struct Stud plox;
int skolko = 0;
Stud bb[5];
void ENTE()
{
	int data;
	cout << "���� ����������:" << endl;
	if (skolko < size)
	{
		cout << "������ �����:";
		cout << skolko + 1;
		cout << endl << "�.�.�.:" << endl;
		cin.ignore();
		getline(cin, list[skolko].name);
		cout << "���� �����������" << endl;
		cin >> data;
		bb[skolko].data = data;
		cout << "�������������:" << endl;
		cin >> list[skolko].spec;
		cout << "������:" << endl;
		cin >> list[skolko].gruppa;
		cout << "���������:" << endl;
		cin.ignore();
		getline(cin, list[skolko].fakylt);
		skolko++;
	}
	else
	{
		cout << "������� ������������ ���-�� �����";
	}
	cout << "��� ������?" << endl;
	cin >> Change2;
}

void DELET()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < skolko; de1++)
			list[de1] = list[de1 + 1];
		skolko = skolko - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list[i] = plox;
	cout << "��� ������?" << endl;
	cin >> Change2;
}

void MENIAT()
{
	int data,per,n;
	cout << "\n������� ����� ������" << endl; 	cin >> n;
	do
	{
		cout << "�������:" << endl;
		cout << "1-��� ��������� �.�.�." << endl;
		cout << "2-��� ��������� ���� �����������" << endl;
		cout << "3-��� ��������� �������������" << endl;
		cout << "4-��� ��������� ������" << endl;
		cout << "5-��� ��������� ����������" << endl;
		cout << "6-�����\n";
		cin >> per;
		switch (per)
		{
		case 1: {
			cout << "����� �.�.�.:";
			cin.ignore();
			getline(cin, list[n - 1].name);
			break;
		}
		case 2:
		{
			cout << "����� ����:";
			cin >> data;
			bb[n - 1].data = data;
			break;
		}
		case 3:
		{
			cout << "����� �������������:";
			cin >> list[n-1].spec;
			break;
		}
		case 4:
		{
			cout << "����� ������:";
			cin >> list[n - 1].gruppa;
			break;
		}
		case 5:
		{
			cout << "����� ���������:";
			cin.ignore();
			getline(cin, list[n - 1].fakylt);
			break;
		}
		default:
		{
			cout << "�������� ����� �� 1 �� 6!" << endl;
			break;
			MENIAT();
		}
		}

	} while (per != 6);
	cout << "��� ������?" << endl;
	cin >> Change2;
}

void VUVOD()
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
		cout << "���� �����������:";
		cout << bb[n - 1].data << endl;
		cout << "�������������:";
		cout << list[n - 1].spec << endl;
		cout << "������:" << endl;
		cout << list[n - 1].gruppa << endl;
		cout << "���������: " << list[n - 1].fakylt << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < skolko; i++)
		{
			cout << "����� ��������� ������ " << endl;
			cout << "�.�.�.:";
			cout << list[i].name << endl;
			cout << "���� �����������:";
			cout << bb[i].data << endl;
			cout << "�������������:";
			cout << list[i].spec << endl;
			cout << "������:";
			cout << list[i].gruppa << endl;
			cout << "���������: " << list[i].fakylt << endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
		cout << "�������� ����� �� 1 �� 2!" << endl;
		VUVOD();
	}
	cout << "��� ������?" << endl;
	cin >> Change2;
}
void ISKAT()
{
	int x;
	cout << endl << "1 - ����� �� �.�.�." << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		string temp;
		bool fl = false;
		cout << "������� �.�.�. �� �������� ������ ��������� �����: ";
		cin.ignore();
		getline(cin, temp);
		for (int i = 0; i <= skolko; i++)
		{
			if (list[i].name == temp)
			{
				cout << endl << "������� �" << i + 1;
				cout << endl << "�.�.�: " << list[i].name;
				cout << endl << "���� �����������" << bb[i].data;
				cout << endl << "�������������: " << list[i].spec;
				cout << endl << "������:" << list[i].gruppa;
				cout << endl << "���������: " << list[i].fakylt;
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
	default:
	{
		cout << "�������� ����� 1!" << endl;
		ISKAT();
	}
	}
	cout << endl << "��� ������?" << endl;
	cin >> Change2;
}
void ZAPIS(int sizes)
{
	int data;
	ofstream zap;
	zap.open("FALLEN.txt", ios_base::out);
	STUD TA = { ' ' };
	for (int o = 0; o < sizes; o++)
	{
		cout << "�.�.�.:";
		cin.ignore();
		getline(cin, TA.name);
		zap.write((char*)&TA, sizeof(TA));
		cout << "���� �����������:";
		cin >> data;
		TA.data = data;
		zap.write((char*)&TA, sizeof(TA));
		cout << "�������������:";
		cin >> TA.spec;
		zap.write((char*)&TA, sizeof(TA));
		cout << "������:";
		cin >> TA.gruppa;
		zap.write((char*)&TA, sizeof(TA));
		cout << "���������:";
		cin.ignore();
		getline(cin, TA.fakylt);
		zap.write((char*)&TA, sizeof(TA));
	}
		cout << endl << "��� ������?" << endl;
		cin >> Change2;
	
}
void SCHITOV()
{
	ifstream schit("FALLEN.txt");
	while (!schit.eof())
	{
		STUD TO = { ' ' };
		cout << "�������:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.name << endl;
		cout << "���� �����������:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.data << endl;
		cout << "�������������:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.spec << endl;
		cout << "������:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.gruppa << endl;
		cout << "���������:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.fakylt << endl;
	}
	cout << endl << "��� ������?" << endl;
	cin >> Change2;
}
int main111()
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
	cout << "6-������ ������ � ����" << endl;
	cout << "7-���������� ������ � �����" << endl;
	cout << "8-��� ������" << endl;
	cin >> Change2;
	do
	{
		switch (Change2)
		{
		case 1: DELET();	break;
		case 2:  ENTE();  break;
		case 3:  MENIAT();  break;
		case 4:  VUVOD();	break;
		case 5:  ISKAT(); break;
		case 6: ZAPIS(2); break;
		case 7: SCHITOV(); break;
		default:
		{
			cout << "�������� ����� �� 1 �� 8!" << endl;
			main111();
		}
		}
	} while (Change2 != 8);
	return 0;
}
