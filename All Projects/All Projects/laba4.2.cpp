#include "Header.h"
using namespace std;
int main8()
{
	setlocale(LC_CTYPE, "Russian");
	float a, b, c, d, f;
	printf("¬ведите a "); scanf_s("%f", &a);
	printf("¬ведите b "); scanf_s("%f", &b);
	printf("¬ведите c "); scanf_s("%f", &c);
	if (a,b,c!=0)
	{
		d = (a*b*c) / 3;
		cout << "d= " << d << endl;
	}
	else
	{
		f = (a + b + c) / 3;
		cout << "f= " << f << endl;
	}
	return 0;
}