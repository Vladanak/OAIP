#include "Header.h"
using namespace std;
int main10()
{
	setlocale(LC_CTYPE, "Russian");
	double z, q, y = -1.55, a = 6,j;
	for ( int i = 1; i <= 4; i++)
	{
		cout << "������� ����� j(8;-0.6;1;6.4): ";
		cin >> j;
		z = sqrt(a + 1) - tan((j) + y);
		q = exp(-(j)*0.1*y) + pow((3 * z), 2);
		printf("������ ��������� = %f\n", z);
		printf("������ ��������� = %f\n", q);
	}
	return 0;
}
