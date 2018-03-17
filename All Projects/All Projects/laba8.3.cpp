#include "Header.h"
using namespace std;                 
int main22()                             
{
	setlocale(LC_CTYPE, "Russian");
	double e = 0.0001;  
	float t = 0, a, b, r, f, x = 0, y, z;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	x = a;
	f = (x*x*x) + (2*x) - 1;
	z = (3 * x * x) + 2;
	y = (6 * x);
	if (f*y > 0)
		r = a;
	else
	{
		r = b;
	}
	t = abs(r - x);
	while (t > e && r > a)
	{
		x = r;
		r = x - abs((double)(f / z));
		t = abs(r - x);
	}
	cout << "Корень уравнения по методу касательных (x^3 + 2x - 1) равен " << x << endl;
	return 0;
}

