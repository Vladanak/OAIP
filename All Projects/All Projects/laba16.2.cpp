#include "Header.h"
using namespace std;
int fun(int a,int n, ...)
{
	int min;
	int *p = &n;
	min = *p;
	for ( int i = 1; i <= a; i++)
	{
		if (min > *p)
		{
			min = *p;
		}
		*(p++);
	}
	return min;
}
int main46()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Первое обращение к функции с нахождением минимального числа:" << endl;
	cout << fun((4),3,5,0,1) << endl;
	cout << "Второе обращение к функции с нахождением минимального числа:" << endl;
	cout << fun((5),3,6,7,11,9) << endl;
	cout << "Третье обращение к функции с нахождением минимального числа:" << endl;
	cout << fun((3),3,6,9) << endl;
	return 0;
}