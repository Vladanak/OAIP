#include "Header.h"
using namespace std;
int main30()
{
	setlocale(LC_CTYPE, "Russian");
	int t,d=0,w=0,z;
	int *pk;
	int *pn;
	int const a = 99;
	int A[a];
	int B[a];
	cout << "������� ������ ��������: ";
	cin >> z;
	cout << "������� �����,��� �������� ���������� �������� ��������� � ������ �������,������� ������ ����� �����: ";
	cin >> t;
	for (pk=A; pk < A+z; pk++)
	{
		*pk = rand() % 99;
		if ( *pk < t)
		{
			d++;
		}
	}
	cout << "���������� � ������ ������� = " << d << endl;
	for (pn=B; pn < B+z; pn++)
	{
		*pn = rand() % 99;
		if (*pn < t)
		{
			w++;
		}
	}
	cout << "���������� �� ������ ������� = " << w << endl;
	cout << endl;
	if (d > w)
	{
		for (pk=A; pk<A+z; pk++)
		{
			cout << "����� �������� ������� ������� : " << pk << ". ������� : " << *pk << "." << endl;
		}
		cout << endl;
		for (pn=B; pn < B+z; pn++)
		{
			cout << "����� �������� ������� ������� : " << pn << ". ������� : " << *pn << "." << endl;
		}
	}
	else
	{ 
		for (pn = B; pn < B+z; pn++)
		{
			cout << "����� �������� ������� ������� : " << pn << ". ������� : " << *pn << "." << endl;
		}
		cout << endl;
		for (pk = A; pk<A+z; pk++)
		{
			cout << "����� �������� ������� ������� : " << pk << ". ������� : " << *pk << "." << endl;
		}
	
	}
	return 0;
}