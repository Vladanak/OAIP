#include "Header.h"
using namespace std;
int main21()
{
	setlocale(LC_CTYPE, "Russian");
	double a=1, b=6, n=200, s1=0, s2=0;
	float x=0, h=0, z, s;
	h = (b - a) /(double) (2 * n); x = a + 2 * h; s1 = 0; s2 = 0; 
	int i = 1;
	while (i<n)
	{
		s2 +=(1 + (x*x*x)); 
		x +=h; 
		s1 +=(1 + (x*x*x)); 
		x +=h; 
		i += 1; 
	}
	s = h * ((1 + (a*a*a)) + 4 * (1 + ((((a+h)*(a+h)*(a+h))+1))) + 4 * s1 + 2 * s2 + (1 + (b*b*b)))/3;
	cout << "s= " << s << endl;
	return 0;
}
