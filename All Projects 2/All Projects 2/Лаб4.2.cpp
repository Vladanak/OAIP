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
	cout << "Ввод информации:" << endl;
	if (kolkov < si)
	{
		cout << "Строка номер:";
		cout << kolkov + 1;
		cout << endl << "Фамилия:" << endl;
		cin >> list[kolkov].name;
		cout << "Наименование товара:" << endl;
		cin >> list[kolkov].tovar;
		cout << "Цена товара:" << endl;
		cin >> list[kolkov].cena;
		cout << "Сумма,выданная под залог:" << endl;
		cin >> list[kolkov].zalog;
		cout << "Дата заполнения:" << endl;
		cin >> list[kolkov].data;
		cout << "Срок хранения(дней):" << endl;
		cin >> list[kolkov].srok;
		kolkov++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}
	cout << "Что дальше?" << endl;
	cin >> chan;
}

void YDAL()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк ввести 99)" << endl;
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
	cout << "Что дальше?" << endl;
	cin >> chan;
}

void IZMEN()
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
			cin >> list[n-1].name;;   break;
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
			IZMEN();
		}
		}
	} while (per != 7);
	cout << "Что дальше?" << endl;
	cin >> chan;
}

void VIVOD()
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
		for (int i = 0; i < kolkov; i++)
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
		VIVOD();
	}
	cout << "Что дальше?" << endl;
	cin >> chan;
}
void Searching()
{
	int x;
	cout << endl << "1 - Поиск по Наименования Товара" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		char temp[30];
		bool fl = false;
		cout << "Введите Наименование товара по которому проводить поиск: ";
		cin >> temp;
		for (int i = 0; i <= kolkov; i++)
		{
			if (strcmp(list[i].tovar ,temp)==0)
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
			cout << endl << "Нет такого номера счёта";
		}
		break;
	}
	default:
	{
		cout << "Выберите цифру 1!" << endl;
		Searching();
	}
	}
	cout << endl << "Что дальше?" << endl;
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
	cout << endl << "Что дальше?" << endl;
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
			cout << "Фамилия: ";
			cin >> buf.name;
			cout << "Наименование товара: ";
			cin >> buf.tovar;
			cout << "Стоимость: ";
			cin >> buf.cena;
			cout << "Залог: ";
			cin >> buf.zalog;
			cout << "Дата: ";
			cin >> buf.data;
			cout << "Срок Хранения: ";
			cin >> buf.srok;
			fwrite(&buf, sizeof(buf), 1, file);
		}
		fclose(file);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
	cout << endl << "Что дальше?" << endl;
	cin >> chan;
}
int main6()
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
			cout << "Выберите цифру от 1 до 8!" << endl;
			main6();
		}
		}
	} while (chan != 8);
	return 0;
}