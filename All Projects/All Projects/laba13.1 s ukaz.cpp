#include "Header.h"
using namespace std;
int main36()
{
	setlocale(LC_CTYPE, "Russian");
	const int N = 2;
	int a, b, c = 0, d;
	int A[N][N] = { { 1,2 },{ 3,4 } };
	cout << "������������� ������� ����� ������� " << N << "*" << N << ":" << endl;
	for (a = 0; a < N; a++)
	{
		for (b = 0; b < N; b++)
		{
			cout << *(*(A+a)+b) << " ";
			c = c + *(*(A + a) + b);
		}
		cout << endl;
	}
	cout << "����� ���� ��������� ������� = " << c << "." << endl;
	cout << "�������� �� ����� ������ ������?" << endl;
	if (c % 2 == 0)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "���" << endl;
	}
	return 0;
}