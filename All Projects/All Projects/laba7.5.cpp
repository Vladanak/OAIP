#include "Header.h"
using namespace std;
int main19()
{
	setlocale(LC_CTYPE, "Russian");                /*Вариант 15 */
	float t = 0.45, q, s, k = 1;
	int n = 6;
	float x[10];
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите " << i << "-й элемент массива y{1.1;6.2;3;-4;6;1}: ";
		cin >> x[i];
		k += ((x[i]+1)/x[i]);
	}
	q = t + k;
	cout << "Q = " << q << endl;
	return 0;
}