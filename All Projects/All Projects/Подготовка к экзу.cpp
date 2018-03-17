#include "Header.h"
using namespace std;
int main35251()
{
	setlocale(LC_CTYPE, "Russian");
	const int a = 4;
	int b, c,**A,z=0,max=0,s=0,p=1;
	srand((unsigned)time(NULL));
	A = new int *[a];
	for (b = 0; b < a; b++)
	{
		A[b] = new int[a];
		for (c = 0; c < a; c++)
		{
			A[b][c] = rand() % (10)+(-5);
			cout << A[b][c] << " ";
			if (z == 0)
			{
				max = A[b][c];
				z++;
			}
			if (max < A[b][c])
			{
				max = A[b][c];
			}

		}
		cout << endl;
	}
	cout << max << endl;;
	for (int k = 0; k < a; k++)
	{
		delete A[k];
	}
	delete[] A;
	return 0;
}