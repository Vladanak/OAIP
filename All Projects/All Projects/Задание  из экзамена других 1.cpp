#include "Header.h"
using namespace std;
int main12342134()
{
	setlocale(LC_CTYPE, "Russian");
	double x[] = { 1.7,3,-8 },s=5.2,a=10.4e+4;
	int m = 10;
	double w, v;
	for (int j = 0; j <= (m + 2); j++)
	{
		for (int i = 0; i <2; i++)
		{
			w = (sqrt(pow(s, 3) - (exp(-2 * s))) + a);
			if (2 * s > x[i] * j)
			{
				v = cos(j*x[i])*cos(j*x[i]);
			}
			if ((2 * s < x[i] * j) && (x[i] * j <= 3 * s))
			{
				v = 2 * tan(j*x[i]);
			}
			if (x[i] * j > 3 * s)
			{
				5 - exp(x[i] / 2);
			}
			cout <<"V="<< v << endl;
		}
		cout <<"W="<< w << endl;
	}
	return 0;
}