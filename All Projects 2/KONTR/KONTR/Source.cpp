#include "Header.h"
using namespace std;
# define str 30                             
# define size 10  
typedef struct Stud
{
	unsigned data : 4;
	char name[str];
	char spec[str];
	int gruppa;
	char fakylt[str];
}STUD;
struct Stud list[size];
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	int data;
	ofstream zap;
	zap.open("FALLEN.txt", ios_base::out);
	STUD TO = { ' ' };
	for (int o = 0; o < 2; o++)
	{
		cout << "�.�.�.:";
		cin>>TO.name;
		cout << "���� �����������:";
		cin >> data;
		TO.data = data;
		cout << "�������������:";
		cin >> TO.spec;
		cout << "������:";
		cin >> TO.gruppa;
		cout << "���������:";
		cin>>TO.fakylt;
		zap.write((char*)&TO, sizeof(TO));
		if (o == 0)
		{
			cout <<endl<< "���������:" << endl;
		}
	}
	zap.close();
	ifstream schit;
	schit.open("FALLEN.txt", ios_base::in);
	schit.read((char *)&TO, sizeof(TO));
	while (!schit.eof())
	{
		cout << endl;
		cout << "�������:";
		cout << TO.name << endl;
		cout << "���� �����������:";
		cout << TO.data << endl;
		cout << "�������������:";
		cout << TO.spec << endl;
		cout << "������:";
		cout << TO.gruppa << endl;
		cout << "���������:";
		cout << TO.fakylt << endl;
		schit.read((char *)&TO, sizeof(TO));
	}
	schit.close();
	ifstream schitt;
	schitt.open("FALLEN.txt", ios_base::in);
		cout << endl << "����� �� �.�.�." << endl;
		char temp[str];
		bool fl = false;
		cout << "������� �.�.�. �� �������� ������ ��������� �����: ";
		cin >> temp;
		schit.read((char *)&TO, sizeof(TO));
		while(!schitt.eof())
		{
			if (strcmp(TO.name,temp)==0)
			{
				cout << endl << "�.�.�: " << TO.name;
				cout << endl << "���� �����������:" << TO.data;
				cout << endl << "�������������: " << TO.spec;
				cout << endl << "������:" << TO.gruppa;
				cout << endl << "���������: " << TO.fakylt;
				cout << endl;
				fl = true;
			}
			schitt.read((char *)&TO, sizeof(TO));
		}
		if (fl == false)
		{
			cout << endl << "��� ��������� � ����� �.�.�!";
		}
		schitt.close();
}
