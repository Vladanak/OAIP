#include "Header.h"
using namespace std;
int main20()               
{
	setlocale(LC_CTYPE, "Russian");
	int  b = 6, n = 200;
        double h, z, x, s,a=1;
		h = (b - a) / n;
		x = a;
		s = 0;
		while (x < b)
		{
			s += h*((1 + pow(x,3)) + (1 + (pow(h+x,3)))) / 2;
			x += h;
		}
	cout << "s= " << s << endl;
	return 0;
}