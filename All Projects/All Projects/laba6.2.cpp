#include "Header.h"
using namespace std;
int main14()
{
	setlocale(LC_CTYPE, "Russian");
	int n, sot = 0, k=0;
	cout << "������� ����� �������� ����� ����� ����� ���� ���������� �����(�� 1 �� 27): ";
		cin >> n;
	for (int i = 100; i < 1000; i++) 
	{
		if (n >27 || n < 1)
		{
			break;
		}	
		else
		{
			sot = (int)(i / 100) + ((i / 10) % 10) + i % 10;
			if (sot == n)
             { cout << "��� �����: " << i << endl; 
			k++;
			}
		}
		
	}
	cout << "���������� = " << k << endl;
	return 0; 
}





