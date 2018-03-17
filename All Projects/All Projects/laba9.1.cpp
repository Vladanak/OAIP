#include "Header.h"
using namespace std;
int main24()
{
	setlocale(LC_CTYPE, "Russian");
	const int maxSize = 99;
	int n, k=0, c=0, b, i, a[maxSize], p[maxSize], v[maxSize];
	cout << "Введите размер массива (не более 99)" << endl;
	for (; ;)
	{
		cin >> n;
		if (n > 99)
		{
			cout << "Требуется ввести размер массива меньше или равный 99."<<endl;
			continue;
		}
		else
			break;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 99;
		cout<< "Номер элемента : " << i <<". Элемент : "<< a[i]<<"."<<endl;
	}
	cout << endl;
	b = n;
	for (i = 1; i < n; i++)
	{
		if ((i % 7) != 0)
		{
				p[k] = a[i];
				k++;
		}
		else continue;
	}
	for (i = 0; i < k; i++)
	{
		cout << "Номер элемента : " << i << ". Элемент : " << p[i] << "." << endl;
	}
	cout << endl;
	for (i = 0; i < k; i++)
	{
		v[c] = p[i];
		if ((i % 2) != 0)
		{
				c++;
				v[c] = 4;
		}
		c++;
	}
	for (i = 0; i < c; i++)
		cout << "Номер элемента : " << i << ". Элемент : " << v[i] << "." << endl;
	return 0;
}