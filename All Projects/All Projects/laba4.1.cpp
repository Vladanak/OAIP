#include "Header.h"
using namespace std;
int main7()
{
	setlocale(LC_CTYPE, "Russian");
	float x, y, z, A,B;
	printf("Введите x "); scanf_s("%f", &x);
	printf("Введите y "); scanf_s("%f", &y);
	printf("Введите z "); scanf_s("%f", &z);
	if ((x + y + z) > (x*y*z))
	{
		A = ((x + y + z) * 3);
		cout << "Сумма= " << A << endl;
	}
	else
	{
		B = ((x*y*z) * 3);
		cout << "Произведение= " << B << endl;
	}
	return 0;
}