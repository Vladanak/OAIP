#include "К9лабе.h"
#include"Header.h"
using namespace std;
int main()
{
	item *head, *tail;
	item *head1, *tail1;
	item *head2, *tail2;
	setlocale(LC_CTYPE, "Russian");
	int i = 1, num = 1, z;
	head = NULL;head1 = NULL;head2 = NULL;
	tail = NULL;tail1 = NULL;tail2 = NULL;
	while (num != 0)
	{
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Получить элемент с начала" << endl;
		cout << "3 - Извлечь элемент с начала" << endl;
		cout << "4 - Вывести элементы" << endl;
		cout << "5 - Очистить очередь" << endl;
		cout << "6 - Удаление отрицательного элемента" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберите действие:";
		cin >> num;
		switch (num)
		{
		case 1: cout << "Введите элемент:  ";
			cin >> z; 
			add(z);
			out();
			break;
		case 2: fromhead(); break;
		case 3: delet1(); break;
		case 4: out(); break;
		case 5: clrscr(); break;
		case 6: delenie(); break;
		}
	}
	return 0;
}
