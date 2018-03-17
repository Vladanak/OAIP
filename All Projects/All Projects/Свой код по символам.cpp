#include "Header.h"
using namespace std;
int main12332578()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;
	char symb, next_symbol;
	for (; ;)
	{
		cout << "Введите первый символ:";
		cin >> symb;
		cout << "Введите второй символ:";
		cin >> next_symbol;
		if (symb < next_symbol)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	cout << "Все символы от первого символа до второго:" << endl;
	for (a = symb; a <= next_symbol; a++)
	{
		printf("%c,", a);
	}
	cout << endl;
	return 0;
}
