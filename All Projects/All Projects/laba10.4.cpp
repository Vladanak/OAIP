#include "Header.h"
using namespace std;
int main29()
{
	setlocale(LC_CTYPE, "Russian");
	int A,n,p; char tmp[33];
	cout << "Введите число(не более 15): ";
	cin >> A;
	cout << "Сколько влево битов: ";
	cin >> n;
	cout << "Позиция: ";
	cin >> p;
	_itoa_s(A, tmp, 2);
	cout << " Число А: " << tmp << endl;
	for (int i = p; i < p+n+1; i++)
	{
		A |= (1 << n);
		n--;
	}
	_itoa_s(A, tmp, 2);
	cout << " Число А(конечное): " << tmp << endl;
	return 0;
}
