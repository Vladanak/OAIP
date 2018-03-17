#include "Header.h"
using namespace std;
int main4()
{
	double t, u, s, y = 0.956, n = 4, a = 5e-6;
	t = 1 / sqrt(y) + 14 * a;
	u = (t + 1) / (a + 2);
	s = log((2 * n / 3) + exp(-n) / u);
	cout << "t= " << t << endl ;
	cout << "u= " << u << endl;
	cout << "s= " << s << endl;
	return 0;
}
