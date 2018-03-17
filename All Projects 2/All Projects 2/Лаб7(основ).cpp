#include "Header.h"
#include "List.h"
using namespace std;

struct Clientt
{
	char name[20];
	char tipscheta[20];
	int nomerscheta;
	int summa;
	char data[20];
	Clientt *next;
};
Object L2 = Create();
void f(void* b)
{
	Clientt *a = (Clientt*)b;
	cout << a->name << " " << a->nomerscheta << " " << a->tipscheta << " " << a->summa << " " << a->data << endl;
}
int main10()
{
	int i, y, u, ii;
	setlocale(LC_ALL, "Russian");
	Object L1 = Create();
	Clientt pl[10];
		do
		{
		cout << "1-Ввод информации " << endl;
		cout << "2-Вывод информации " << endl;
		cout << "3-Удаление определенной записи " << endl;
		cout << "4-Поиск элемента " << endl;
		cout << "5-Подсчет элементов " << endl;
		cout << "6-Удаление всех элементов " << endl;
		cout << "7-Удаление каждого M-ного элемента " << endl;
		cout << "8-Выход " << endl;
			cin >> y;
				if (y == 1)
				{
					system("cls");
					cout << "Введите количество элементов" << endl;
					cin >> u;

					for (i = 0; i < u; i++) {
						cout << "Введите Имя ";
						cin >> pl[i].name;
						cout << endl;
						cout << "Введите Номер Счёта ";
						cin >> pl[i].nomerscheta;
						cout << endl;
						cout << "Введите Тип Счёта ";
						cin >> pl[i].tipscheta;
						cout << endl;
						cout << "Введите Сумму На Счёте ";
						cin >> pl[i].summa;
						cout << endl;
						cout << "Введите Дату Заполнения ";
						cin >> pl[i].data;
						cout << endl;
						L1.Insert(&pl[i]);
					}
					system("cls");
				}

				if (y == 2)
				{
					system("cls");
					cout << "Вывод " << endl;
					L1.PrintList(f);
				}


				if (y == 3)
				{
					system("cls");
					cout << "Введите номер удаленной записи" << endl;
					cin >> ii;
					L1.Delete(&pl[ii - 1]);
				}

				if (y == 4)
				{
					system("cls");
					int yy;
					Clientt* aa;
					Element* e = L1.GetLast();
					cout << "Введите номер элемента " << endl;
					cin >> yy;
					L1.Search(&pl[yy - 1]);
					e = L1.Search(&pl[yy - 1]);
					aa = (Clientt*)e->Data;
					cout << "Найден элемент= " << aa->name << " " << aa->nomerscheta << " " << aa->tipscheta << " " << aa->summa << " " << aa->data<< endl;
				}
				if (y == 5)
				{
					system("cls");
					cout << "Количество равно ";
					cout << L1.CountList() << endl;
				}

				if (y == 6)
				{
					int io;
					io = L1.CountList();
					for (int vv = 0; vv <= io; vv++)
					{
						L1.Delete(&pl[vv]);
					}
				}

				if (y == 7)
				{
					system("cls");
					int io, jl,mm;
					io = L1.CountList();
					cout << "Введиет номер M-ного элемента" << endl;
					cin >> mm;
					jl = mm;
					L1.Delete(&pl[jl - 1]);
					while (mm <= io)
					{
						L1.Delete(&pl[mm + 1]);
						mm = mm + mm;
					}
					system("cls");
				}
			}while (y != 8);
	return 0;
}
