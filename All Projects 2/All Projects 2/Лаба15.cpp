#include "Header.h"
using namespace std;
int N, A[1000],io,j,key;
void SortPuz(int A[], int N) //сортировка пузырьком
{
	int count;
	for (io = 0; io < N; io++)
	{
		for (j = 0; j < N - 1; j++)
		{
			key = j + 1;  count = A[key];
			if (A[j] > A[key])
			{
				A[key] = A[j];   A[j] = count;
			}
		}
	}
	cout << "Результирующий массив: ";
	for (io = 0; io < N; io++) cout << A[io] << " ";
	cout << endl;
}
void SortSel(int A[], int n) //сортировка выбором
{
	int count;
	for ( io = 0; io<n - 1; io++)
	{
		count = A[io]; key = io;
		for ( j = io + 1; j<n; j++)
			if (A[j]<A[key]) key = j;
		if (key != io)
		{
			A[io] = A[key];
			A[key] = count;
		}
	}
	cout << "Результирующий массив: ";
	for (io = 0; io < n; io++) cout << A[io] << " ";
	cout << endl;
}
void SortShel(int A[],int N)
{
	int buf;
	bool sort;
	for (int g = N / 2; g > 0; g /= 2)
		do
		{
			sort = false;
			for ( io = 0, j = g; j < N; io++, j++)
				if (A[io] > A[j])
				{
					sort = true;
					buf = A[io];
					A[io] = A[j];
					A[j] = buf;
				}
		} while (sort);
		cout << "Результирующий массив: ";
		for (io = 0; io < N; io++) cout << A[io] << " ";
		cout << endl;
}
int main2321()
{
	clock_t ctime;
	int choise;
	bool t = true;
	for (;;)
	{
		setlocale(LC_ALL, "Russian");
		srand((unsigned)time(NULL));
		cout << "Введите кол-во элементов:"; cin >> N;
		for (io = 0; io < N; io++)
		{
			cout << io + 1 << " элемент ";
			A[io] = rand() % 99;
			cout << A[io] << endl;
		}
		cout << "1 - сортировка Пузырьком " << endl;
		cout << "2 - сортировка выбором" << endl;
		cout << "3 - сортировка Шелла" << endl;
		cout << "4 - Выход" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			ctime = clock();
			SortPuz(A, N);
			ctime = clock() - ctime;
			cout << ctime;
			break;
		}
		case 2:
		{
			ctime = clock();
			SortSel(A, N);
			ctime = clock() - ctime;
			cout << ctime;
			break;
		}
		case 3:
		{
			ctime = clock();
			SortShel(A, N);
			ctime = clock() - ctime;
			cout << ctime;
			break;
		}
		case 4:t = false; break;
		}
		cout << endl;
		if (t == false) break;
	}
	return 0;
	}
