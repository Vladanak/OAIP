#include "Header.h"
using namespace std;
int main235321()
{
	setlocale(LC_CTYPE, "Russian");
	const int sz = 100;
	int a, c,l;
	float A[sz];
	for (;;)
	{
		cout << "������� ������ �������(�� ����� 100):";
		cin >> c;
		if (c > 100)
			continue;
		else
			break;
	}
	srand((unsigned)time(NULL));
	for (a = 0; a <= c; a++)
	{
		A[a] = rand() % 10;
		cout <<"������� "<<a<<" �����:"<< A[a]<<endl;
	}
	cout << "������� ����� ���������� ��������:";
	cin >> l;
	for (a=l;a<=c-1;a++)
	{
		A[a] = A[a + 1];
	}
	c--;
	for (a = 0; a <= c; a++)
	{
		cout << A[a] << endl;
	}
	return 0;
}