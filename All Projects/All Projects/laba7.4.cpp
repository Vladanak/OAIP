#include "Header.h"
using namespace std;
int main18()
{
	setlocale(LC_CTYPE, "Russian");
	float a = 5.45, q, s,k=1;                       /*Вариант 11 */
	int n = 5;
	float y[10];
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите " << i << "-й элемент массива y{2.1;7.7;-4;5;9}: ";
		cin >> y[i];
		k = (k * (y[i]/((i*i)+1)));
	}
	q = 4 * k;
	s = 2 * a + q*sin(a);
	cout << "S = " << s << endl;
	cout << "Q = " << q << endl;
	return 0;
}