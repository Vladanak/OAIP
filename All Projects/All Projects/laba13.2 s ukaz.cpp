#include "Header.h"
using namespace std;
int main38()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 2;
	int a, b, c = 0, d = 1, z;
	int A[N][N] = { { 4,6 },{ 8,10 } };
	cout << "������������� ������� ����� ������� " << N << "*" << N << ":" << endl;
	for (a = 0; a < N; a++)
	{
		z = 0;
		for (b = 0; b <N; b++)
		{
			z = *(*(A + a) + b) / 2;
			if (z % 2 != 0)
			{
				c = c + *(*(A + a) + b);
				d = d* *(*(A + a) + b);
			}
			cout << *(*(A + a) + b) << "  ";
		}
		cout << endl;
	}
	cout << "����� ��������� �� ��������� ������� = " << c << endl;
	cout << "������������ ��������� �� ��������� ������� = " << d << endl;
	return 0;
}