#include "Header.h"
using namespace std;
int main41()
{
	setlocale(LC_ALL, "Russian");
	const int N = 4, M = 4;
	int a, b, s1=0,s2=0,min,max=0,c;
	int A[N][M];
	srand((unsigned)time(NULL));
	cout << "Представление массива в виде матрицы " << N << "*" << M << ":" << endl;
	for (a = 0; a < N; a++)
	{
		for (b = 0; b < M; b++)
		{
			A[a][b] = rand() % 100;
			cout << A[a][b] << " ";
		}
		cout << endl;
	}
	for (a = 0; a < N; a++)
	{
		c = 0;
		for (b = 0; b < M; b++)
		{
			if (a % 2 == 0)
			{
				if (c != 1)
				{
					min = A[a][b];
					c++;
				}
				if (A[a][b] < min)
				{
					min = A[a][b];
				}
				if (b == M - 1)
				{
					s1 += min;
				}
			}
			else
				if (a % 2 !=0)
				{
					if (c != 1)
					{
						max = A[a][b];
						c++;
					}
					if (A[a][b] > max)
					{
						max = A[a][b];
					}
					if (b == M - 1)
					{
						s2 += max;
					}
				}
		}
	}
	cout <<"Сумма наименьших элементов нечётных строк="<< s1 << endl;
	cout << "Сумма наибольших элементов чётных строк=" << s2 << endl;
	cout << "Их сумма=" << s1+s2 << endl;
	return 0;
}