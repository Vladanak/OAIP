#include "Header.h"
using namespace std;
int func(int m, int n)
{
	int k;
	if (m == 0 || m == n) k = 1;
	else k = func(m, n - 1) + func(m - 1, n - 1);
	return k;
}
void main2()
{
	setlocale(LC_ALL, "Russian");
	int m, n;
	cout << "������� m:" << endl;
	cin >> m;
	cout << "������� n:" << endl;
	cin >> n;
	cout << "������������� ����������� = " << func(m, n) << endl;
}