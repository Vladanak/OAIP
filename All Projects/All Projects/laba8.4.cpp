#include "Header.h"
using namespace std;
int main23()
{
	setlocale(LC_CTYPE, "Russian");
	double e = 0.0001;
	float x = 0,a,b;
	cout << "������� a: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (x*x*x + 2 * x - 1 > 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}
	}
	cout << "������ ��������� �� ������ ��������� (x^3 + 2x - 1) ����� " << x << endl;
	return 0;
}
