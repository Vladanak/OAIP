#include "Header.h"
# define str_len 50                             
# define size 30  
int change;
using namespace std;
struct Client
{
	string name;
	char tipscheta[str_len];
	int nomerscheta;
	int summa;
	char data[str_len];
};

struct Client list[size];
struct Client bad;
int kolich = 0;

void enter_new()
{
	cout << "Ввод информации:" << endl;
	if (kolich < size)
	{
		cout << "Строка номер:";
		cout << kolich + 1;
		cout << endl << "Ф.И.О.:" << endl;
	    cin.ignore();
		getline(cin, list[kolich].name);
		cout << "Тип счета(срочный, льготный,детский):" << endl;
		cin >> list[kolich].tipscheta;
		cout << "Номер счёта:" << endl;
		cin >> list[kolich].nomerscheta;
	    cout << "Начальный вклад на счёт:" << endl;
		cin >> list[kolich].summa;
		cout << "Дата заполнения:" << endl;
		cin >> list[kolich].data;
		kolich++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}
	cout << "Что дальше?" << endl;
	cin >> change;
}

void Ydalenie()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк ввести 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < kolich; de1++)
			list[de1] = list[de1 + 1];
		kolich = kolich - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> change;
}

void Izmenit()
{
	int n, per,dob;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для изменения Ф.И.О." << endl;
		cout << "2-для изменения Типа счёта" << endl;
		cout << "3-для изменения Номера счёта" << endl;
		cout << "4-для изменения Суммы счёта" << endl;
		cout << "5-для изменения Даты" << endl;
		cout << "6-для добавления денег (или снятия) на(с) счёт" << endl;
		cout << "7-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новое Ф.И.О.:";
			cin.ignore();
			getline(cin, list[n-1].name);   break;
		case 2: cout << "Новый тип Счёта:";
			cin >> list[n - 1].tipscheta; break;
		case 3: cout << "Новый Номер Счёта:";
			cin >> list[n - 1].nomerscheta; break;
		case 4: cout << "Новая Сумма Счёта:";
			cin >> list[n - 1].summa; break;
		case 5:cout << "Новая Дата Изменения:";
			cin >> list[n - 1].data; break;
		case 6:
			puts("1-добавление,2-снятие");
			cin >> per;
			switch (per)
			{
			case 1:
			{
				cout << "Сколько положить денег на счёт?" << endl;
				cin >> dob;
				list[n - 1].summa += dob;
				break;
			}
			case 2:
			{
				cout << "Сколько денег снять со счёта?" << endl;
				cin >> dob;
				list[n - 1].summa -= dob;
				break;
			}
			}
		default:
		{
			cout << "Выберите цифру от 1 до 7!" << endl;
			break;
			Izmenit();
		}
		}
	} while (per != 7);
	cout << "Что дальше?" << endl;
	cin >> change;
}

void Vivesti()
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
		cout << "Тип счёта:";
		cout << list[n - 1].tipscheta << endl;
		cout << "Номер счёта:";
		cout << list[n - 1].nomerscheta << endl;
		cout << "Состояние счёта:" << endl;
		cout << list[n - 1].summa << endl;
		cout << "Дата изменения: " << list[n-1].data << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < kolich; i++)
		{
			cout << "Ф.И.О.:";
			cout << list[i].name << endl;
			cout << "Тип счёта:";
			cout << list[i].tipscheta << endl;
			cout << "Номер счёта:";
			cout << list[i].nomerscheta << endl;
			cout << "Состояние счёта:" << endl;
			cout << list[i].summa << endl;
			cout << "Дата изменения: " << list[i].data<< endl;
		}
	}
	if (sw != 1 && sw != 2)
	{
		cout << "Выберите цифру от 1 до 2!" << endl;
		Vivesti();
	}
	cout << "Что дальше?" << endl;
	cin >> change;
}
void Poisk()
{
	int x;
	cout << endl << "1 - Поиск по номеру счёта" << endl;
	cout << "2 - Поиск по диапазону значений счёта" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		int temp;
		bool fl = false;
		cout << "Введите номер счёта по которому хотите проводить поиск: ";
		cin >> temp;
		for (int i = 0; i <= kolich; i++)
		{
			if (list[i].nomerscheta == temp)
			{
				cout << endl << "Позиция №" << i + 1;
				cout << endl << "Ф.И.О клиента: " << list[i].name;
				cout << endl << "Тип счёта: " << list[i].tipscheta;
				cout << endl << "Сумма на счёте: " << list[i].summa;
				cout << endl << "Дата изменения счёта: " << list[i].data;
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
	case 2: {
		int a, b, c;
		bool f2 = false;
		cout << "Введите диапазон суммы по которому искать клиентов: ";
		cout << endl;
		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		cout << "1-a>суммы и b>суммы;\n2-a<суммы и b>суммы ";
		cin >> c;
		switch (c) {
		case 1:
		{
			for (int i = 0; i <= kolich; i++)
			{
				if (list[i].summa < a && b > list[i].summa)
				{
					cout << endl << "Позиция №" << i + 1;
					cout << endl << "Ф.И.О клиента: " << list[i].name;
					cout << endl << "Тип счёта: " << list[i].tipscheta;
					cout << endl << "Сумма на счёте: " << list[i].summa;
					cout << endl << "Дата изменения счёта: " << list[i].data;
					cout << endl;
					f2 = true;
				}
				else
					break;
			}
			if (f2 == false)
			{
				cout << endl << "Нет таких студентов";
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i <= kolich; i++)
			{
				if (list[i].summa > a && b > list[i].summa)
				{
					cout << endl << "Позиция №" << i + 1;
					cout << endl << "Ф.И.О клиента: " << list[i].name;
					cout << endl << "Тип счёта: " << list[i].tipscheta;
					cout << endl << "Сумма на счёте: " << list[i].summa;
					cout << endl << "Дата изменения счёта: " << list[i].data;
					cout << endl;
					f2 = true;
				}
			}
			if (f2 == false)
			{
				cout << endl << "Нет таких студентов";
			}
			break;
		}
		}
	}
	default:
	{
		cout << "Выберите цифру от 1 до 2!" << endl;
		Poisk();
	}
	}
	cout << endl << "Что дальше?" << endl;
	cin >> change;
}
int main3()
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
	cin >> change;
	do
	{
		switch (change)
		{
		case 1:  Ydalenie();	break;
		case 2:  enter_new();  break;
		case 3:  Izmenit();  break;
		case 4:  Vivesti();	break;
		case 5: Poisk(); break;
		default:
		{
			cout << "Выберите цифру от 1 до 6!" << endl;
			main3();
		}
		}
	} while (change != 6);
	return 0;
}