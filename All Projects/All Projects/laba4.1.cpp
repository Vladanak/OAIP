#include "Header.h"
using namespace std;
int main7()
{
	setlocale(LC_CTYPE, "Russian");
	float x, y, z, A,B;
	printf("������� x "); scanf_s("%f", &x);
	printf("������� y "); scanf_s("%f", &y);
	printf("������� z "); scanf_s("%f", &z);
	if ((x + y + z) > (x*y*z))
	{
		A = ((x + y + z) * 3);
		cout << "�����= " << A << endl;
	}
	else
	{
		B = ((x*y*z) * 3);
		cout << "������������= " << B << endl;
	}
	return 0;
}