#include "Header.h"
using namespace std;
int main1233432()
{
	setlocale(LC_CTYPE, "Russian");
	const int maxSize = 99;
	int n, i, A, B, max = 0,x,z=0,c=0;
	float  a[maxSize];
	cout << "Введите размер массива (не более 99)" << endl;
	cin >> n;
	cout << "Ввести позицию A" << endl;
	cin >> A;
	cout << "Ввести позицию B" << endl;
	cin >> B;
	cout << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 99;
		cout << a[i] << endl;
	}
	cout <<"Элементы от А до В "<< endl;
	for (i = A; i <= B; i++)
	{
		a[i];
		cout << a[i] << endl;
	}
	for (i = A; i <= B; i++)
	{
		c++;
	}
	for (i = 0; i <=n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			x = i + 1;
		}
	}
	cout << endl;
	for (i = x; i < n; i++)
	{
		z+= a[i];
	}
	cout <<"Сумма элементов равна "<< z << endl;
	cout << "Количество " << c << endl;
	return 0;
}