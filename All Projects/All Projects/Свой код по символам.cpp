#include "Header.h"
using namespace std;
int main12332578()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, c;
	char symb, next_symbol;
	for (; ;)
	{
		cout << "������� ������ ������:";
		cin >> symb;
		cout << "������� ������ ������:";
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
	cout << "��� ������� �� ������� ������� �� �������:" << endl;
	for (a = symb; a <= next_symbol; a++)
	{
		printf("%c,", a);
	}
	cout << endl;
	return 0;
}
