#include "Header.h"
using namespace std;
int main30()
{
	setlocale(LC_CTYPE, "Russian");
	int t,d=0,w=0,z;
	int *pk;
	int *pn;
	int const a = 99;
	int A[a];
	int B[a];
	cout << "Введите размер массивов: ";
	cin >> z;
	cout << "Введите число,для подсчёта количества значений элементов в каждом массиве,которые меньше этого числа: ";
	cin >> t;
	for (pk=A; pk < A+z; pk++)
	{
		*pk = rand() % 99;
		if ( *pk < t)
		{
			d++;
		}
	}
	cout << "Количество в первом массиве = " << d << endl;
	for (pn=B; pn < B+z; pn++)
	{
		*pn = rand() % 99;
		if (*pn < t)
		{
			w++;
		}
	}
	cout << "Количество во втором массиве = " << w << endl;
	cout << endl;
	if (d > w)
	{
		for (pk=A; pk<A+z; pk++)
		{
			cout << "Номер элемента первого массива : " << pk << ". Элемент : " << *pk << "." << endl;
		}
		cout << endl;
		for (pn=B; pn < B+z; pn++)
		{
			cout << "Номер элемента второго массива : " << pn << ". Элемент : " << *pn << "." << endl;
		}
	}
	else
	{ 
		for (pn = B; pn < B+z; pn++)
		{
			cout << "Номер элемента второго массива : " << pn << ". Элемент : " << *pn << "." << endl;
		}
		cout << endl;
		for (pk = A; pk<A+z; pk++)
		{
			cout << "Номер элемента первого массива : " << pk << ". Элемент : " << *pk << "." << endl;
		}
	
	}
	return 0;
}