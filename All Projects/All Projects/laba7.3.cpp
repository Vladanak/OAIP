#include "Header.h"
using namespace std;
int main17()
{
	setlocale(LC_CTYPE, "Russian");
	int  n = 6;
		float k = 1,q;                              /*Вариант 10 */
	float x[10];
	float y[10];
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите " << i << "-й элемент массива x{3;-2;0.7;-1;-2;7): ";
		cin >> x[i];
		cout << "Введите " << i << "-й элемент массива y{1;5;-1.2;6;9;-4}: ";
		cin >> y[i];
		k *= (x[i]*y[i]);
	}
	q = k;
	cout << "Q = " << q << endl;
	return 0;
}