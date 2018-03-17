#include "Header.h"
using namespace std;
int main40()
{
	setlocale(LC_ALL, "Russian");
	int i, n, max=0,s=0,pr=1,d=0;
	const int a = 100;
	float N[a];
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
		N[i] = rand() % 100+(-50);
		cout << "Номер элемента : " << i << ". Элемент : " <<N[i] << "." << endl;
		if (N[i] > max)
		{
			max=N[i];
			d=i;
		}
	}
	cout << "Максимальный элемент=" << max<<"."<<"Его индекс:"<<d<< endl;
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
	cout << "Произведение=" <<pr<< endl;
	cout << "Сумма=" << s << endl;
	return 0;
}