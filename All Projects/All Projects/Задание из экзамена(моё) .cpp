#include "Header.h"
using namespace std;
int main8321()
{
	setlocale(LC_CTYPE, "Russian");
	char A[] = "(a+b(c*d))";
	int a = 0, b,c=0;
	for (b = 0; b < strlen(A); b++)
	{
		if (A[b] == '(')
		{
			++a;
			cout <<a<< "-����������� ������" << endl;
		}
		if (A[0] == ')')
		{
			cout << "����������� ������ �� ����� ���� ������" << endl;
				break;
		}
		if (A[b] == ')')
		{
			++c;
			cout <<c<< "-����������� ������" << endl;
		}
		if ((a == c)&&(b==(strlen(A)-1)))
		{
			cout << "��� ������ ���������" << endl;
		}
		else
			if ((a != c)&&(b==(strlen(A)-1)))
			{
				cout << "������ �� ���������" << endl;
				break;
			}
	}
	return 0;
}