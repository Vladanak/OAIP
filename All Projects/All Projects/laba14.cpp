#include "Header.h"
using namespace std;
void mas();
void matr();
int main42(void)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	for(;;)
	{
		cout << "Введите" << endl;
		cout << "1-одномерный массив" << endl;
		cout << "2-работа с матрицей" << endl;
		cout << "3-выход" << endl;
		cin >> c;
		cout << endl;
		if (c == 3)
		{
			system("cls");
			cout << "Всего хорошего!" << endl;
			break;
		}
		switch (c)
		{
		case 1:   mas();
			cout << endl;
			break;
		case 2:   matr();
			cout << endl;
			break;
		}
	} 
	return 0;
}
void mas()
{
	int i, n, max = 0, s = 0, pr = 1, d = 0;
	float *N;
	const int a = 100;
	N=new float[a];
	cout << "Введите размер массива (не более 100)" << endl;
	for (; ;)
	{
		cin >> n;
		if (n > 100)
		{
			cout << "Требуется ввести размер массива меньше или равный 100." << endl;
			continue;
		}
		else
			break;
	}

	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		N[i] = rand() % 100 + (-50);
		cout << "Номер элемента : " << i << ". Элемент : " << N[i] << "." << endl;
		if (N[i] > max)
		{
			max = N[i];
			d = i;
		}
	}
	cout << "Максимальный элемент=" << max << "." << "Его индекс:" << d << endl;
	for (i = 0; i < n; i++)
	{
		if (i < d && N[i] < 0)
		{
			pr *= N[i];
		}
		if (i < d && N[i]>0)
		{
			s += N[i];
		}
	}
	cout << "Произведение=" << pr << endl;
	cout << "Сумма=" << s << endl;
	delete[] N;
}
void matr()
{
	const int N = 4;
	int **A;
	int a, b, s1 = 0, s2 = 0, min, max = 0, c;
	A=new int*[N];
	srand((unsigned)time(NULL));
	cout << "Представление массива в виде матрицы " << N << "*" << N << ":" << endl;
	for (a = 0; a < N; a++)
	{
		A[a] = new int[N];
		for (b = 0; b < N; b++)
		{
			A[a][b] = rand() % 100;
			cout << A[a][b] << " ";
		}
		cout << endl;
	}
	for (a = 0; a < N; a++)
	{
		c = 0;
		for (b = 0; b < N; b++)
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
				if (b == N - 1)
				{
					s1 += min;
				}
			}
			else
				if (a % 2 != 0)
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
					if (b == N - 1)
					{
						s2 += max;
					}
				}
		}
	}
	cout << "Сумма наименьших элементов нечётных строк=" << s1 << endl;
	cout << "Сумма наибольших элементов чётных строк=" << s2 << endl;
	cout << "Их сумма=" << s1 + s2 << endl;
	for (int k = 0; k < N; k++)
	{
		delete A[k];
	}
	delete[] A;
}
