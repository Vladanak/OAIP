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
		cout << "Ф.И.О.:";
		cin>>TO.name;
		cout << "Дата Поступления:";
		cin >> data;
		TO.data = data;
		cout << "Специальность:";
		cin >> TO.spec;
		cout << "Группа:";
		cin >> TO.gruppa;
		cout << "Факультет:";
		cin>>TO.fakylt;
		zap.write((char*)&TO, sizeof(TO));
		if (o == 0)
		{
			cout <<endl<< "Следуюший:" << endl;
		}
	}
	zap.close();
	ifstream schit;
	schit.open("FALLEN.txt", ios_base::in);
	schit.read((char *)&TO, sizeof(TO));
	while (!schit.eof())
	{
		cout << endl;
		cout << "Фамилия:";
		cout << TO.name << endl;
		cout << "Дата поступления:";
		cout << TO.data << endl;
		cout << "Специальность:";
		cout << TO.spec << endl;
		cout << "Группа:";
		cout << TO.gruppa << endl;
		cout << "Факультет:";
		cout << TO.fakylt << endl;
		schit.read((char *)&TO, sizeof(TO));
	}
	schit.close();
	ifstream schitt;
	schitt.open("FALLEN.txt", ios_base::in);
		cout << endl << "Поиск по Ф.И.О." << endl;
		char temp[str];
		bool fl = false;
		cout << "Введите Ф.И.О. по которому хотите проводить поиск: ";
		cin >> temp;
		schit.read((char *)&TO, sizeof(TO));
		while(!schitt.eof())
		{
			if (strcmp(TO.name,temp)==0)
			{
				cout << endl << "Ф.И.О: " << TO.name;
				cout << endl << "Дата Поступления:" << TO.data;
				cout << endl << "Специальность: " << TO.spec;
				cout << endl << "Группа:" << TO.gruppa;
				cout << endl << "Факультет: " << TO.fakylt;
				cout << endl;
				fl = true;
			}
			schitt.read((char *)&TO, sizeof(TO));
		}
		if (fl == false)
		{
			cout << endl << "Нет студентов с таким Ф.И.О!";
		}
		schitt.close();
}
