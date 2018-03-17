#include "Header.h"
using namespace std;
void main111()
{
	    setlocale(LC_CTYPE, "Russian");
		const int maxSize = 99;
		int n, i, a[maxSize], kmax = 0;
		cout << "Введите размер массива (не более 99)" << endl;
		cin >> n;
		if (n > 99)
			return;
		srand((unsigned)time(NULL));
		for (i = 0; i < n; i++)
		{
			a[i] = rand() % 99;
			cout << a[i] << " ";
		}
		cout << endl;
		for (i = 1; i < n; i++)
			if (a[i] > a[kmax])
				kmax = i;
		cout << "Максимальный элемент " << a[kmax] << endl;
}