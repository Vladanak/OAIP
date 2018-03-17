#include "Header.h"
using namespace std;
int main31()
{
	setlocale(LC_CTYPE, "Russian");
	int  z, q = 0, c = 0, max = 0,k=0,l=0;
	int A[] = { 1,3,5,6,7,9,11,12,13,14,15,16 };
	float B[] = { 1,2,4,6,7,9,11.1,12,13,14,15,17 };
	for (int i = 0; i < 12; i++)
	{
		if (c == q)	c = 0;
		q = c;
	
		for (z = 0; z < 13; z++)
		{
			if (*(A+i) == *(B+z))
			{
				k = z;
				c++;
				break;
			}
		}
		if (c > max)
		{
			max = c;
			l = k+1;
		}
	}
	k = l - max;
	for (k; k < l; k++)
	{
		cout << "Последовательность " << *(B+k) << endl;
	}
	cout << "Количество " << max << endl;
	return 0;
}