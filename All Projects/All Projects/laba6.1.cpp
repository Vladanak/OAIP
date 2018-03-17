#include "Header.h"
using namespace std;
int main13()
{
	setlocale(LC_CTYPE, "Russian");
	double s, i=7, m=4,x, a=105*pow(10,-4),p;
	for (int d = 1; d <= 4;d++)
	{
		cout << "¬ведите x(8;1,9;-4;1): ";
		cin >> x;
		s = exp(-a*x) - log(i / abs(x)*m)*log(m)*log(m);
		if (s > 2 * x)
		{
			p = (-i*s)*(-i*s);
		}
		else
			if (s <= 2 * x)
			{
				p = sin(-6 * s);
			}
		cout << "S= " << s << endl;
		cout << "P= " << p << endl;
	}
	return 0;
}