#include "Header.h"
using namespace std;
int main11()
{
	setlocale(LC_CTYPE, "Russian");
	double z, q,j=-1, y = -1.55, a = 6;
	while (j<=1)
	{
		z = sqrt(a + 1) - tan(j + y);
		q = exp((-j)*0.1*y) + pow(3 * z, 2);
		printf_s("Первое уравнение= %f\n", z);
		printf_s("Второе уравнение= %f\n", q);
		j = j + 0.2;
	}
	return 0;
}
