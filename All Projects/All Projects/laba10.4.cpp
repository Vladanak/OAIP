#include "Header.h"
using namespace std;
int main29()
{
	setlocale(LC_CTYPE, "Russian");
	int A,n,p; char tmp[33];
	cout << "������� �����(�� ����� 15): ";
	cin >> A;
	cout << "������� ����� �����: ";
	cin >> n;
	cout << "�������: ";
	cin >> p;
	_itoa_s(A, tmp, 2);
	cout << " ����� �: " << tmp << endl;
	for (int i = p; i < p+n+1; i++)
	{
		A |= (1 << n);
		n--;
	}
	_itoa_s(A, tmp, 2);
	cout << " ����� �(��������): " << tmp << endl;
	return 0;
}
