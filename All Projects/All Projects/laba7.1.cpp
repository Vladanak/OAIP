#include "Header.h"
using namespace std;
int main15()
{
	setlocale(LC_CTYPE, "Russian");
	int  m=5;                                          /*Вариант 3 */
	float z, k = 0;
	float x[10];
	for(int i=0;i<m;i++)
	{
		cout << "Введите " << i + 1 << "-й элемент массива x{-2;6;1.1;2.7;4}: ";
		cin >> x[i];
		k += ((x[i] - 2)*(x[i] - 2));
	}
	z = 8 * x[2] + k;
	cout << "Z = " << z<<endl;
	return 0;
}
