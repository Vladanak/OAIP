#include "Header.h"
using namespace std;
void zadanie1();
void zadanie2();
void zadanie3();
void zadanie4();
float f3(float x);
float f(float);
void main43() 
{
	int c;
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите" << endl;
	cout << "1-метод касательных" << endl;
	cout << "2-метод дихотомии" << endl;
	cout << "3-метод парабол" << endl;
	cout << "4-метод трапеции" << endl;
	cout << "5-выход" << endl;
	cin >> c;
	switch (c)
	{
	case 1: zadanie1(); main43();
	case 2: zadanie2(); main43();
	case 3: zadanie3(); main43();
	case 4: zadanie4(); main43();
	case 5: break;
	default:
		main43();
		break;
	}
}
void zadanie2()
{
	double e = 0.0001;
	float x = 0, a, b;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (f(x) > 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}
	}
	cout << "Корень уравнения по методу дихотомии (x^3 + 2x - 1) равен " << float(x) << endl;
	system("pause");
}
void zadanie1()
{
	double e = 0.0001;
	float t = 0, a, b, r, f1, x = 0, y, z;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	x = a;
	f1 = f(x);
	z = (3 * x * x) + 2;
	y = (6 * x);
	if (f1*y > 0)
		r = a;
	else
		r = b;
	t = abs(r - x);
	while (t > e && r > a)
	{
		x = r;
		r = x - abs((float)(f1 / z));
		t = abs(r - x);
	}
	cout << "Корень уравнения по методу касательных (x^3 + 2x - 1) равен " << x << endl;
	system("pause");
}
void zadanie3()
{
	cout << "Метод парабол" << endl;
	double a = 1, b = 6, n = 200, s1 = 0, s2 = 0;
	float x = 0, h = 0, z, s;
	h = (b - a) / (double)(2 * n); x = a + 2 * h; s1 = 0; s2 = 0;
	int i = 1;
	while (i<n)
	{
		s2 += (1 + (x*x*x));
		x += h;
		s1 += (1 + (x*x*x));
		x += h;
		i += 1;
	}
	s = h * ((1 + (a*a*a)) + 4 * (1 + ((((a + h)*(a + h)*(a + h)) + 1))) + 4 * s1 + 2 * s2 + (1 + (b*b*b))) / 3;
	cout << "Интеграл равен" << s<<endl;
	system("pause");
}
void zadanie4()
{
	cout << "Метод трапеции" << endl;
	int  b = 6, n = 200;
	double h, z, x, s, a = 1;
	h = (b - a) / n;
	x = a;
	s = 0;
	while (x < b)
	{
		s += h*((1 + f3(x)) + (1 + (pow(h + x, 3)))) / 2;
		x += h;
	}
	cout << "Интеграл равен:" << s << endl;
	system("pause");
}
float f(float x)
{
	float result = ((x*x*x) + (2 * x) - 1);
	return result;
}
float f3(float x)
{
	float result = (pow(x, 3));
	return result;
}
