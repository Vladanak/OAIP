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
	cout << "Ввод информации:" << endl;
	if (kolo < si)
	{
		cout << "Строка номер:";
		cout << kolo + 1;
		cout << endl << "Фамилия:" << endl;
		cin >> list[kolo].name;
		cout << "Наименование товара:" << endl;
		cin >> list[kolo].tovar;
		cout << "Цена товара:" << endl;
		cin >> list[kolo].cena;
		cout << "Сумма,выданная под залог:" << endl;
		cin >> list[kolo].zalog;
		cout << "Дата заполнения:" << endl;
		cin >> list[kolo].data;
		cout << "Срок хранения(дней):" << endl;
		cin >> list[kolo].srok;
		kolo++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}
	cout << "Что дальше?" << endl;
	cin >> cha;
}

void Y()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк ввести 99)" << endl;
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
	cout << "Что дальше?" << endl;
	cin >> cha;
}

void I()
{
	int n, per, dob;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для изменения Ф.И.О." << endl;
		cout << "2-для изменения Наименования товара" << endl;
		cout << "3-для изменения Стоимость" << endl;
		cout << "4-для изменения Сумма Залога" << endl;
		cout << "5-для изменения Даты" << endl;
		cout << "6-для изменения Срока Хранения" << endl;
		cout << "7-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новая Фамилия:";
			cin.ignore();
			cin >> list[n - 1].name;;   break;
		case 2: cout << "Новое Наименование товара:";
			cin >> list[n - 1].tovar; break;
		case 3: cout << "Новая Стоимость:";
			cin >> list[n - 1].cena; break;
		case 4: cout << "Новая Сумма Залога:";
			cin >> list[n - 1].zalog; break;
		case 5:cout << "Новая Дата:";
			cin >> list[n - 1].data; break;
		case 6:cout << "Новый Срок Хранения:";
			cin >> list[n - 1].srok; break;
		default:
		{
			cout << "Выберите цифру от 1 до 7!" << endl;
			break;
			I();
		}
		}
	} while (per != 7);
	cout << "Что дальше?" << endl;
	cin >> cha;
}

void V()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "Фамилия:";
		cout << list[n - 1].name << endl;
		cout << "Наименование Товара:";
		cout << list[n - 1].tovar << endl;
		cout << "Стоимость:";
		cout << list[n - 1].cena << endl;
		cout << "Сумма Залога:" << endl;
		cout << list[n - 1].zalog << endl;
		cout << "Дата: " << list[n - 1].data << endl;
		cout << "Срок Хранения:" << endl;
		cout << list[n - 1].srok << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < kolo; i++)
		{
			cout << "Фамилия:";
			cout << list[i].name << endl;
			cout << "Наименование Товара:";
			cout << list[i].tovar << endl;
			cout << "Стоимость:";
			cout << list[i].cena << endl;
			cout << "Сумма Залога:" << endl;
			cout << list[i].zalog << endl;
			cout << "Дата: " << list[i].data << endl;
			cout << "Срок Хранения:" << endl;
			cout << list[i].srok << endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
		cout << "Выберите цифру от 1 до 2!" << endl;
		V();
	}
	cout << "Что дальше?" << endl;
	cin >> cha;
}
void S()
{
	int x;
	cout << endl << "1 - Поиск по Наименования Товара" << endl;
	cout << endl << "2 - Поиск по Сроку Хранения" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		char temp[30];
		bool fl = false;
		cout << "Введите Наименование товара по которому проводить поиск: ";
		cin >> temp;
		for (int i = 0; i <= kolo; i++)
		{
			if (strcmp(list[i].tovar, temp) == 0)
			{
				cout << endl << "Позиция №" << i + 1;
				cout << endl << "Фамилия: " << list[i].name;
				cout << endl << "Наименование Товара: " << list[i].tovar;
				cout << endl << "Стоимость: " << list[i].cena;
				cout << endl << "Сумма Залога: " << list[i].zalog;
				cout << endl << "Дата: " << list[i].data;
				cout << endl << "Срок Хранения: " << list[i].srok;
				cout << endl;
				fl = true;
			}
		}
		if (fl == false)
		{
			cout << endl << "Нет такого товара";
		}
		break;
	}
	case 2:
	{
		char chislo[30];
		bool f2 = false;
		cout << "Введите Срок Хранения по которому проводить поиск: ";
		cin >> chislo;
		for (int a = 0; a <= kolo; a++)
		{
			if (strcmp(list[a].srok, chislo) == 0)
			{
				cout << endl << "Позиция №" << a + 1;
				cout << endl << "Фамилия: " << list[a].name;
				cout << endl << "Наименование Товара: " << list[a].tovar;
				cout << endl << "Стоимость: " << list[a].cena;
				cout << endl << "Сумма Залога: " << list[a].zalog;
				cout << endl << "Дата: " << list[a].data;
				cout << endl << "Срок Хранения: " << list[a].srok;
				cout << endl;
				f2 = true;
			}
		}
		if (f2 == false)
		{
			cout << endl << "Нет такого !";
		}
		break;
	}
	default:
	{
		cout << "Выберите цифру 1 или 2!" << endl;
		S();
	}
	}
	cout << endl << "Что дальше?" << endl;
	cin >> cha;
}
void inPut( int sizes)
{
	ofstream lol;
	lol.open("DATA.txt", ios_base::out);
	LOMD T = { ' ' };
	for (int o = 0; o < sizes; o++)
	{
		cout << "Фамилия:";
		cin >> T.name;
		lol.write((char*)&T, sizeof(T));
		cout << "Наименование Товара:";
		cin >> T.tovar;
		lol.write((char*)&T, sizeof(T));
		cout << "Стоимость:";
		cin >> T.cena;
		lol.write((char*)&T, sizeof(T));
		cout << "Сумма Залога:";
		cin >> T.zalog;
		lol.write((char*)&T, sizeof(T));
		cout << "Дата:";
		cin >> T.data;
		lol.write((char*)&T, sizeof(T));
		cout << "Срок Хранения:";
		cin >> T.srok;
		lol.write((char*)&T, sizeof(T));
		cout << endl << "Что дальше?" << endl;
		cin >> cha;
	}
}
void outPut()
{
	ifstream in("DATA.txt");
	while (!in.eof())
	{
		LOMD T = { ' ' };
		cout << "Фамилия:";
		in.read((char *)&T, sizeof(T));
		cout << T.name << "\t    ";
		cout << "Наименование Товара:";
		in.read((char *)&T, sizeof(T));
		cout << T.tovar << endl;
		cout << "Стоимость:";
		in.read((char *)&T, sizeof(T));
		cout << T.cena << endl;
		cout << "Сумма Залога:";
		in.read((char *)&T, sizeof(T));
		cout << T.zalog << endl;
		cout << "Дата:";
		in.read((char *)&T, sizeof(T));
		cout << T.data << endl;
		cout << "Срок Хранения:";
		in.read((char*)&T, sizeof(T));
		cin >> T.srok;
	}
	cout << endl << "Что дальше?" << endl;
	cin >> cha;
}

int main8()
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
	cout << "6-Считывания Информации с Файла" << endl;
	cout << "7-Запись информации в Файл" << endl;
	cout << "8-для выхода" << endl;
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
			cout << "Выберите цифру от 1 до 8!" << endl;
			main8();
		}
		}
	} while (cha != 8);
	return 0;
}