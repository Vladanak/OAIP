#include "Header.h"
#include "К8лабе.h"
using namespace std;
int m = 0;
int kkk;
int k2[10];
void main11()
{
	setlocale(LC_ALL, "Rus");
	stack *MyStk = new stack; //выделение памяти для стекаw+
	MyStk->head = NULL;       //инициализация первого элемента	
	for (;;)
	{
		cout << "Работа со стеком. Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Очистка списка" << endl;
		cout << "5 - Запись в файл" << endl;
		cout << "6 - Вывод из файла" << endl;
		cout << "7 - ФУНКЦИЯ" << endl;
		cout << "8 - Выход" << endl;
		cin >> kkk;
		switch (kkk)
		{
		case 1:
		{cout << "Введите элемент для вставки: " << endl;
		cin >> kkk;
		k2[m] = kkk;
		m++;
		push(kkk, MyStk);
		break;
		}
		case 2:
		{
			kkk = pop(MyStk);
			m--;
			if (kkk != -1) cout << "Извлеченный элемент: " << kkk << endl;
			break;
		}
		case 3:
		{
			cout << "Весь стек: " << endl;
			show(MyStk);
			break;
		}
		case 4:
		{
			Clear(MyStk);
			break;
		}
		case 8:
		{
			return;
			break;
		}
		case 5:
		{
			Zapis(MyStk);
			break;
		}
		case 6:
		{
			Viv(MyStk);
			break;
		}
		case 7:
		{
			Funcc(MyStk);
			break;
		}
	}
  }
}