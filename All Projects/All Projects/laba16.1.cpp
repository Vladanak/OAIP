#include "Header.h"
using namespace std;
int &func(int **A, int &N, int &M)
{
	int a, b, c = 0, d = 0;
	for (a = 0; a < N; a++)
	{
		for (b = 0; b < M; b++)
		{
			if (A[a][b] >= 0 && d<2)
			{
				c = c + A[a][b];
				d++;
			}
		}
		if (d < 2)
		{
			c = 0;
			d = 0;
		}
	}
	for (a = 0; a < N; a++)
	{
		for (b = 0; b < M; b++)
		{
			A[a][b] = (A[a][b] - c);
			cout << A[a][b] << " ";
		}
		cout << endl;
	}
	cout << "Сумма элементов положительной строки матрицы:";
	return c;
}
int main49()
{
	setlocale(LC_CTYPE, "Russian");
		int N = 3, M = 2;
		int **A=new int*[N];
		int a, b, c;
		cout << "Представление массива ввиде матрицы " << N << "*" << M << ":" << endl;                                               	                                  
		srand((unsigned)time(NULL));
		for (a = 0; a < N; a++)
		{
			A[a] = new int[N];
			for (b = 0; b < M; b++)
			{
				A[a][b] = rand() % 9+(-4);
				cout << A[a][b] << " ";   
			}
			cout << endl;
		}
		cout << "Изменённая матрица с отниманием суммы положительных элементов от каждого элемента:" << endl;
	    cout << (func(A,N,M))<<endl;
		for (a = 0; a < N; a++)
			delete A[a];
		delete[]A;
	return 0;
}