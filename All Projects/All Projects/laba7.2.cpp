#include "Header.h"
using namespace std;
int main16()
{
	setlocale(LC_CTYPE, "Russian");
	int  n = 5;                             /*Вариант 1 */
	float k = 0,h;
	float d = 12.5*pow(10, -4);
	float a[10];
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите " << i << "-й элемент массива a{0.8;4;-7;2;0.91}: ";
		cin >> a[i];
		k += (a[i] * a[i]);
	}
	h = d+k;
	cout << "H = " << h << endl;
	return 0;
}