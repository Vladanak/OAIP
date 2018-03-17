#include "Header.h"
#define size 10
using namespace std;
int main14256()
{
	system("cls");
	setlocale(LC_CTYPE, "Russian");
	int m;
	int kol = 1;
	int maxcol = 0;
	const int SZ = 10;
	int A[SZ] = { 4,4,4,4,4,5,5,5,5,7 };
	printf("Найти в массиве наибольшее число подряд идущих одинаковых элементов \n");
	for (m = 0; m<SZ; m++)
	{
		printf("A[m%d]=%d\n", m, A[m]);
	}
	for (m = 0; m<SZ - 1; m++)
	{
		if (A[m] == A[m + 1])
		{
			kol++;
			if (kol>maxcol)
				maxcol = kol;
		}
		else
		{
			kol = 1;
		}
	}
	printf(" Hаибольшее число подряд идущих одинаковых элементов=%d\n", maxcol);
	return 0;
}
