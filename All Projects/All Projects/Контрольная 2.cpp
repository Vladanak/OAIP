#include "Header.h"
using namespace std;
int main1233432()
{
	setlocale(LC_CTYPE, "Russian");
	const int maxSize = 99;
	int n, i, A, B, max = 0,x,z=0,c=0;
	float  a[maxSize];
	cout << "������� ������ ������� (�� ����� 99)" << endl;
	cin >> n;
	cout << "������ ������� A" << endl;
	cin >> A;
	cout << "������ ������� B" << endl;
	cin >> B;
	cout << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 99;
		cout << a[i] << endl;
	}
	cout <<"�������� �� � �� � "<< endl;
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
	cout <<"����� ��������� ����� "<< z << endl;
	cout << "���������� " << c << endl;
	return 0;
}