#include "Header.h"
using namespace std;   
int main25()
{
	setlocale(LC_CTYPE, "Russian");
	const int maxSize = 99;
	int n, i, C[maxSize], d=3 ;
	cout << "������� ������ ������� (�� ����� 99)" << endl;
	for (; ;)
	{
		cin >> n;
		if (n > 99)
		{
			cout << "��������� ������ ������ ������� ������ ��� ������ 99." << endl;
			continue;
		}
		else
			break;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		C[i] = rand() % 99;
		if (i % d == 0 && i!=0)
		{
			C[i] = (C[i - 2] + C[i - 1]) / 2;
			cout << "����� �������� : " << i << ". ������� : " << C[i] << "." << endl;
			d = d + 3;
		}
		else
			cout << "����� �������� : " << i << ". ������� : " << C[i] << "." << endl;
			continue;
	}
	return 0;
}