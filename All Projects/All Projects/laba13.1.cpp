#include "Header.h"
using namespace std;
int main37()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 2,M=2;
	int a,b,c=0,d;
	int A[N][M] = { {1,2},{3,4} };
	cout << "Представление массива ввиде матрицы "<<N<<"*"<<M<<":"<< endl;
	for (a=0; a < N; a++)
	{
		for (b = 0; b < M; b++)
		{
			cout << A[a][b]<<" ";
			c = c + A[a][b];
		}
		cout << endl;
	}
	cout <<"Сумма всех элементов массива = "<< c <<"."<< endl;
	cout << "Является ли сумма чётным числом?" << endl;
	if (c % 2 == 0)
	{
		cout << "Да" << endl;
	}
	else
	{
		cout << "Нет" << endl;
	}
		return 0;
}