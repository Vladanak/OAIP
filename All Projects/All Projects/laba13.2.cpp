#include "Header.h"
using namespace std;
int main39()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 2, M = 2;
	int a, b, c = 0, d=1,z;
	int A[N][M] = { { 4,6 },{ 8,10 } };
	cout << "Представление массива ввиде матрицы " << N << "*" <<M<< ":" << endl;
	for (a = 0; a < N; a++)
	{
		z = 0;
		for (b = 0; b <M; b++)
		{
			z = A[a][b] / 2;
			if (z % 2 != 0)
			{
				c = c + A[a][b];
				d = d*A[a][b];
		    }
			cout << A[a][b] << "  ";
		}
		cout << endl;
	}
	cout <<"Сумма элементов по заданному условию = "<< c << endl;
	cout << "Произведение элементов по заданному условию = " << d << endl;
	return 0;
}