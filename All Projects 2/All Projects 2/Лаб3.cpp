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
	cout << "Ввод информации:" << endl;
	if (kol < size)
	{
		cout << "Строка номер:";
		cout << kol + 1;
		cout << endl << "Ф.И.О.:" << endl;
		cin.ignore();
		getline(cin, list[kol].name);
		cout << "Класс с буквой(вначале цифру,а потом букву):" << endl;
		cin >> cifra;
	    cin>>list[kol].bykv;
		a[kol].cifra = cifra;
		cout << "Предметы(1-Matra,2-Russki,3-Angliski,4-Istoria):" << endl;
		cin >> d;
		switch (d)
		{
		case(Matra):{
				a[kol].predmet = "Математика";
				break;
			}
		case(Russki): {
			a[kol].predmet = "Русский";
			break;
		}
		case(Angliski): {
			a[kol].predmet = "Английский";
			break;
		}
		case(Istoria): {
			a[kol].predmet = "История";
			break;
		}
		}
		cout << "Оценка:" << endl;
		cin.ignore();
		getline(cin, list[kol].ocenki);
		cout << "Средний балл:" << endl;
		cin >> list[kol].sredni;
		kol++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}
	cout << "Что дальше?" << endl;
	cin >> ch;
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк ввести 99)" << endl;
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
	cout << "Что дальше?" << endl;
	cin >> ch;
}

void Izm()
{
	int n, per, dob,cifra,d;
	char bykv;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для изменения Ф.И.О." << endl;
		cout << "2-для изменения Класса" << endl;
		cout << "3-для изменения Предмета" << endl;
		cout << "4-для изменения Оценки" << endl;
		cout << "5-для изменения Среднего балла" << endl;
		cout << "6-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: {
			cout << "Новое Ф.И.О.:";
			cin.ignore();
			getline(cin, list[n-1].name);  
			break;
		}
		case 2:
		{
			cout << "Новый класс(вначале цифру,а потом букву):";
			cin >> cifra >> list[n-1].bykv;
			a[n-1].cifra = cifra;
			break;
		}
		case 3:
		{
			cout << "Новый Предмет(1-Matra,2-Russki,3-Angliski,4-Istoria):";
			cin >> d;
			switch (d)
			{
			case(Matra): {
				a[n-1].predmet = "Математика";
				break;
			}
			case(Russki): {
				a[n-1].predmet = "Русский";
				break;
			}
			case(Angliski): {
				a[n-1].predmet = "Английский";
				break;
			}
			case(Istoria): {
				a[n-1].predmet = "История";
				break;
			}
			}
			break;
		}
		case 4:
		{
			cout << "Новая Оценка по Предмету:";
			cin.ignore();
			getline(cin, list[n-1].ocenki);
			break;
		}
		case 5:
		{
			cout << "Новый средний балл:";
			cin >> list[n-1].sredni;
			break;
		}
		default:
		{
			cout << "Выберите цифру от 1 до 6!" << endl;
			break;
			Izm();
		}
			}
		
	} while (per != 6);
	cout << "Что дальше?" << endl;
	cin >> ch;
}

void Vive()
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
		cout << "Класс:";
		cout << a[n - 1].cifra<<" "<< list[n-1].bykv << endl;
		cout << "Предмет:";
		cout << a[n - 1].predmet << endl;
		cout << "Оценка по предмету:" << endl;
		cout << list[n - 1].ocenki << endl;
		cout << "Средний балл: " << list[n - 1].sredni << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < kol; i++)
		{
			cout << "Номер выводимой строки " << endl; 
			cout << "Ф.И.О.:";
			cout << list[i].name << endl;
			cout << "Класс:";
			cout << a[i].cifra << " " << list[i].bykv << endl;
			cout << "Предмет:";
			cout << a[i].predmet << endl;
			cout << "Оценка по предмету:";
			cout << list[i].ocenki << endl;
			cout << "Средний балл: " << list[i].sredni << endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
			cout << "Выберите цифру от 1 до 2!" << endl;
			Vive();
	}
	cout << "Что дальше?" << endl;
	cin >> ch;
}
void Poi()
{
	int x;
	cout << endl << "1 - Поиск по Ф.И.О." << endl;
	cout << "2 - Поиск по среднему баллу." << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		string temp;
		bool fl = false;
		cout << "Введите Ф.И.О. по которому хотите проводить поиск: ";
		cin.ignore();
		getline(cin, temp);
		for (int i = 0; i <= kol; i++)
		{
			if (list[i].name==temp)
			{
				cout << endl << "Позиция №" << i + 1;
				cout << endl << "Ф.И.О: " << list[i].name;
				cout << endl << "Класс: " << a[i].cifra << " " << list[i].bykv;
				cout << endl << "Предмет:" << a[i].predmet;
				cout << endl << "Оценка по предмету: " << list[i].ocenki;
				cout << endl << "Средний балл: " << list[i].sredni;
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
	case 2: {
		int n;
		bool f2 = false;
		cout << "Введите средний балл по которому искать: " << endl;
		cin >> n;
			for (int i = 0; i <= kol; i++)
			{
				if (list[i].sredni == n)
				{
					cout << endl << "Позиция №" << i + 1;
					cout << endl << "Ф.И.О: " << list[i].name;
					cout << endl << "Класс: " << a[i].cifra << " " << list[i].bykv;
					cout << endl << "Предмет:" << a[i].predmet;
					cout << endl << "Оценка по предмету: " << list[i].ocenki;
					cout << endl << "Средний балл: " << list[i].sredni;
					cout << endl;
					f2 = true;
				}
			}
			if (f2 == false)
			{
				cout << endl << "Нет студентов с таким средним баллом!";
			}
			break;
	}
	default:
	{
		cout << "Выберите цифру от 1 до 2!" << endl;
		Poi();
	}
	}
	cout << endl << "Что дальше?" << endl;
	cin >> ch;
}
int main4()
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
	cout << "6-для выхода" << endl;
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
			cout << "Выберите цифру от 1 до 6!" << endl;
			main4();
		}
		}
	} while (ch != 6);
	return 0;
} 
