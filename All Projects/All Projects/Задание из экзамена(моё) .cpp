#include "Header.h"
using namespace std;
int main8321()
{
	setlocale(LC_CTYPE, "Russian");
	char A[] = "(a+b(c*d))";
	int a = 0, b,c=0;
	for (b = 0; b < strlen(A); b++)
	{
		if (A[b] == '(')
		{
			++a;
			cout <<a<< "-открывающая скобка" << endl;
		}
		if (A[0] == ')')
		{
			cout << "Закрывающая скобка не может идти первой" << endl;
				break;
		}
		if (A[b] == ')')
		{
			++c;
			cout <<c<< "-закрывающая скобка" << endl;
		}
		if ((a == c)&&(b==(strlen(A)-1)))
		{
			cout << "Все скобки соблюдены" << endl;
		}
		else
			if ((a != c)&&(b==(strlen(A)-1)))
			{
				cout << "Скобки не соблюдены" << endl;
				break;
			}
	}
	return 0;
}