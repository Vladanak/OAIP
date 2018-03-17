#include "Header.h"
using namespace std;
int main0()
{
	setlocale(LC_CTYPE, "Russian");               
	float y,d;
	int n;
	for (int i = 1; i <= 4; i++)
	{
		cout << "¬ведите число: ";
		cin >> d;
		n = 1;
		while (n<=5)
		{
			y = 3 * n + d;
			cout <<"Y = "<< y << endl;
			n += 2;
		}
	}
	return 0;
}