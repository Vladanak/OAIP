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
	cout << "Ввод информации:" << endl;
	if (skolko < size)
	{
		cout << "Строка номер:";
		cout << skolko + 1;
		cout << endl << "Ф.И.О.:" << endl;
		cin.ignore();
		getline(cin, list[skolko].name);
		cout << "Дата Поступления" << endl;
		cin >> data;
		bb[skolko].data = data;
		cout << "Специальность:" << endl;
		cin >> list[skolko].spec;
		cout << "Группа:" << endl;
		cin >> list[skolko].gruppa;
		cout << "Факультет:" << endl;
		cin.ignore();
		getline(cin, list[skolko].fakylt);
		skolko++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}
	cout << "Что дальше?" << endl;
	cin >> Change2;
}

void DELET()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк ввести 99)" << endl;
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
	cout << "Что дальше?" << endl;
	cin >> Change2;
}

void MENIAT()
{
	int data,per,n;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для изменения Ф.И.О." << endl;
		cout << "2-для изменения Даты Поступления" << endl;
		cout << "3-для изменения Специальности" << endl;
		cout << "4-для изменения Группы" << endl;
		cout << "5-для изменения Факультета" << endl;
		cout << "6-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: {
			cout << "Новое Ф.И.О.:";
			cin.ignore();
			getline(cin, list[n - 1].name);
			break;
		}
		case 2:
		{
			cout << "Новая Дата:";
			cin >> data;
			bb[n - 1].data = data;
			break;
		}
		case 3:
		{
			cout << "Новая Специальность:";
			cin >> list[n-1].spec;
			break;
		}
		case 4:
		{
			cout << "Новая Группа:";
			cin >> list[n - 1].gruppa;
			break;
		}
		case 5:
		{
			cout << "Новый Факультет:";
			cin.ignore();
			getline(cin, list[n - 1].fakylt);
			break;
		}
		default:
		{
			cout << "Выберите цифру от 1 до 6!" << endl;
			break;
			MENIAT();
		}
		}

	} while (per != 6);
	cout << "Что дальше?" << endl;
	cin >> Change2;
}

void VUVOD()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "Ф.И.О.:";
		cout << list[n - 1].name << endl;
		cout << "Дата Поступления:";
		cout << bb[n - 1].data << endl;
		cout << "Специальность:";
		cout << list[n - 1].spec << endl;
		cout << "Группа:" << endl;
		cout << list[n - 1].gruppa << endl;
		cout << "Факультет: " << list[n - 1].fakylt << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < skolko; i++)
		{
			cout << "Номер выводимой строки " << endl;
			cout << "Ф.И.О.:";
			cout << list[i].name << endl;
			cout << "Дата Поступления:";
			cout << bb[i].data << endl;
			cout << "Специальность:";
			cout << list[i].spec << endl;
			cout << "Группа:";
			cout << list[i].gruppa << endl;
			cout << "Факультет: " << list[i].fakylt << endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
		cout << "Выберите цифру от 1 до 2!" << endl;
		VUVOD();
	}
	cout << "Что дальше?" << endl;
	cin >> Change2;
}
void ISKAT()
{
	int x;
	cout << endl << "1 - Поиск по Ф.И.О." << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		string temp;
		bool fl = false;
		cout << "Введите Ф.И.О. по которому хотите проводить поиск: ";
		cin.ignore();
		getline(cin, temp);
		for (int i = 0; i <= skolko; i++)
		{
			if (list[i].name == temp)
			{
				cout << endl << "Позиция №" << i + 1;
				cout << endl << "Ф.И.О: " << list[i].name;
				cout << endl << "Дата Поступления" << bb[i].data;
				cout << endl << "Специальность: " << list[i].spec;
				cout << endl << "Группа:" << list[i].gruppa;
				cout << endl << "Факультет: " << list[i].fakylt;
				cout << endl;
				fl = true;
			}
		}
		if (fl == false)
		{
			cout << endl << "Нет студентов с таким Ф.И.О!";
		}
		break;
	}
	default:
	{
		cout << "Выберите цифру 1!" << endl;
		ISKAT();
	}
	}
	cout << endl << "Что дальше?" << endl;
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
		cout << "Ф.И.О.:";
		cin.ignore();
		getline(cin, TA.name);
		zap.write((char*)&TA, sizeof(TA));
		cout << "Дата Поступления:";
		cin >> data;
		TA.data = data;
		zap.write((char*)&TA, sizeof(TA));
		cout << "Специальность:";
		cin >> TA.spec;
		zap.write((char*)&TA, sizeof(TA));
		cout << "Группа:";
		cin >> TA.gruppa;
		zap.write((char*)&TA, sizeof(TA));
		cout << "Факультет:";
		cin.ignore();
		getline(cin, TA.fakylt);
		zap.write((char*)&TA, sizeof(TA));
	}
		cout << endl << "Что дальше?" << endl;
		cin >> Change2;
	
}
void SCHITOV()
{
	ifstream schit("FALLEN.txt");
	while (!schit.eof())
	{
		STUD TO = { ' ' };
		cout << "Фамилия:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.name << endl;
		cout << "Дата поступления:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.data << endl;
		cout << "Специальность:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.spec << endl;
		cout << "Группа:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.gruppa << endl;
		cout << "Факультет:";
		schit.read((char *)&TO, sizeof(TO));
		cout << TO.fakylt << endl;
	}
	cout << endl << "Что дальше?" << endl;
	cin >> Change2;
}
int main111()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	cout << "Данных нет" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для изменения записи" << endl;
	cout << "4-для вывода записи(ей)" << endl;
	cout << "5-поиск информации" << endl;
	cout << "6-Запись данных в файл" << endl;
	cout << "7-Считывание данных с файла" << endl;
	cout << "8-для выхода" << endl;
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
			cout << "Выберите цифру от 1 до 8!" << endl;
			main111();
		}
		}
	} while (Change2 != 8);
	return 0;
}
