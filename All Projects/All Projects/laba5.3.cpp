#include "Header.h"
using namespace std;
int main12()
{
	setlocale(LC_CTYPE, "Russian");
	double z,y, q, j,a;
	cout << "������� ����� j: ";
	cin >> j;
		for (int i = 1; i <= 3; i++)
		{
			cout << "������� y(3.3;-4;0.9): ";
			cin >> y;
			a = 1;
			while (a <= 2)
			{
				z = sqrt(a + 1) - tan(j + y);
				q = exp((-j)*0.1*y) + pow((3 * z), 2);
				printf_s("������ ���������= %f\n", z);
				printf_s("������ ���������= %f\n", q);
				a += 0.2;
			}
		}
	return 0;
}
