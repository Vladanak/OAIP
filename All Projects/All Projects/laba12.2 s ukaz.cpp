#include "Header.h"
using namespace std;
int main34()
{
	setlocale(LC_CTYPE, "Russian");
	int i, k = 0;
	char* b = "bcd*d*trk*";
	char c[30];
	cout << "�������� ������:" << b << endl;
	for (i = 0; i<10; i++)
	{
		if (*(b+i) != '*') {
			*(c+k) = *(b + i);
			*(c + k+1) = *(b + i);
			k = k + 2;
		}
	}
	cout << "������ � �������� ��������� * � � ����������� �������� �� ���� ��������:" << endl;
	for (i = 0; i < k; i++)
	{
		cout << *(c+i);
	}
	cout << endl;
	return 0;
}