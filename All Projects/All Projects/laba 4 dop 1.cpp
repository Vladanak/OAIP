#include "Header.h"
using namespace std;
int main2()
{
	setlocale(LC_CTYPE, "Russian");
	int count;
	double a, b; 
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	cout << "Какое действие выполнить: 1-сложение; 2-вычитание; 3-умножение; 4-деление; ";
	cin >> count;
	switch (count) 
	{
	case 1: 
	{
		cout << a << " + " << b << " = " << a + b << endl; 
		break;
	}
	case 2: 
	{
		cout << a << " - " << b << " = " << a - b << endl; 
		break;
	}
	case 3: 
	{
		cout << a << " * " << b << " = " << a * b << endl;
		break;
	}
	case 4: 
	{
		cout << a << " / " << b << " = " << a / b << endl;
		break;
	}
	default: 
		cout << "Неправильный ввод" << endl;
	}
	return 0;
}
