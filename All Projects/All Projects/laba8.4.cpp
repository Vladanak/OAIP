#include "Header.h"
using namespace std;
int main23()
{
	setlocale(LC_CTYPE, "Russian");
	double e = 0.0001;
	float x = 0,a,b;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (x*x*x + 2 * x - 1 > 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}
	}
	cout << "Корень уравнения по методу дихотомии (x^3 + 2x - 1) равен " << x << endl;
	return 0;
}
