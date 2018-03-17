#include "Header.h"
using namespace std;
int main85932()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 4;
	int Y, x[2 * N] = { 5,-2,0,7,1,-4,10,3 };
	Y = (x[0] - x[1] + x[2] - x[3] + x[4] - x[5] + x[6] - x[7]);
	cout << "Y=" << Y << endl;
	return 0;
}