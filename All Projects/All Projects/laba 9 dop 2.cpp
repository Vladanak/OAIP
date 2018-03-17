#include "Header.h"
using namespace std;
int main2342()
{
	setlocale(LC_CTYPE, "Russian");
	int k=0, q = 0,l=0,c = 0, max=0, n=0,z;
	int const a = 99;
	int A[a];
	int B[a];
	cout << "Введите размер массива (не более 99)" << endl;
	for (; ;)
	{
		cin >> n;
		if (n > 99)
		{
			cout << "Требуется ввести размер массива меньше или равный 99." << endl;
			continue;
		}
		else
			break;
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		if (c == q)	c = 0;
		q = c;

		for (z = 0; z < n; z++)
		{
			if (*(A + i) == *(B + z))
			{
				k = z;
				c++;
				break;
			}
		}
		if (c > max)
		{
			max = c;
			l = k + 1;
		}
	}
	k = l - max;
	cout << "Количество:" <<max << endl;
	return 0;
}