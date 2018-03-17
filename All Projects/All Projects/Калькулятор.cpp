#include "Header.h"
using namespace std;
int main() 
{
	setlocale(LC_ALL, "Russian");
	long double a, b, c, h;
	int d, f;
	char y[20], x[20],m;
	for ( ; ; )
	{
		cout << "КАЛЬКУЛЯТОР  VERSION 0.1"<< endl;
		cout << "Введите первое число:";
		cin >> a;
		cout<<"Введите второе число:";
		cin >> b;
		puts("Выберите дейсвтие: (1-сложение,2-разность,3-умножение,4-деление,5-извлечение квадратного корня,6-возведение в степень,7-Триганометрические действия,8-Перевод первого или второго числа в двоичную систему счисления)");
		cin >> d;
		switch (d)
		{
		case 1:
			cout << a << "+" << b << "=" << a + b << endl;
			break;
		case 2:
			cout << a << "-" << b << "=" << a - b << endl;
			break;
		case 3:
			cout << a << "*" << b << "=" << a*b << endl;
			break;
		case 4:
			cout << a << "/" << b << "=" << a / b << endl;
			if (b == 0)
				printf_s(" На ноль делить нельзя! \n");
			break;
		case 5:
			puts("Из какого числа извлекать корень? Из(1-ого или 2-ого):");
			cin >> d;
			switch (d)
			{
			case 1:
				if (a < 0)
				{
					cout << "Извлекать корень из отрицательного числа нельзя!" << endl;
				}
				else
				{
					cout << "Квадратный корень из " << a << " = " << sqrt(a) << endl;
				}
				break;
			case 2:
				if (b < 0)
				{
					cout << "Извлекать корень из отрицательного числа нельзя!" << endl;
				}
				else
				{
					cout << "Квадратный корень из " << b << " = " << sqrt(b) << endl;
				}
				break;
			}
			break;
		case 6:
			cout << "В какую степень возвести число " << a << " ? " << endl;
			cout << "В ";
			cin >> f;
			cout << "Число " << a << " в степени " << f << " будет равно " << pow(a, f) << "." << endl;
			break;
		case 7:
			puts("Выберите,с каким числом проводить вычисления(с 1-ым или 2-ым):");
			cin >> d;
			switch (d)
			{
			case 1:
				puts("Выберите,что вычислять (1-Sin,2-Cos,3-Tan) ");
				cin >> d;
				switch (d)
				{
				case 1:
					cout << "Синус числа " << a << " равен " << sin(a) << endl;
					break;
				case 2:
					cout << "Косинус числа " << a << " равен " << cos(a) << endl;
					break;
				case 3:
					cout << "Тангенс числа " << a << " равен " << tan(a) << endl;
					break;
				}
				break;
			case 2:
				puts("Выберите,что вычислять (1-Sin,2-Cos,3-Tan) ");
				cin >> d;
				switch (d)
				{
				case 1:
					cout << "Синус числа " << b << " равен " << sin(b) << endl;
					break;
				case 2:
					cout << "Косинус числа " << b << " равен " << cos(b) << endl;
					break;
				case 3:
					cout << "Тангенс числа " << b << " равен " << tan(b) << endl;
					break;
				}
				break;
			}
			break;
		case 8:
			puts("Выберите переводить первое число или второе?(1-первое,2-второе)");
			cin >> d;
			switch (d)
			{
			case 1:
				_itoa_s(a, y, 2);
				cout << "Первое число в двоичной системе счисления : " << y << endl;
				break;
			case 2:
				_itoa_s(b, x, 2);
				cout << "Второе число в двоичной системе счисления : " << x << endl;
				break;
			}
		}
		s:
		cout << "Продолжить?" << endl <<"Y или N"<<endl;
		if (cin >> m && m == 'Y' || m =='y')
		{
			system("cls");
			continue;
		}
		else
			if (m == 'N'||m =='n')
			{
				system("cls");
				cout << "Всего хорошего!" << endl;
				break;
			}
			else
				goto s;
	}
	return 0;
}