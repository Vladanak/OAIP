#include "Header.h"
using namespace std;
int main9()
{
	setlocale(LC_CTYPE, "Russian");
	int b;
	puts("���� �� ������:������ ��� �������� ��� ����������� �����������?(1-������,2-��������,3-����.�����������)");
	cin >> b;
	switch (b)
	{case 1:
	{puts("������� ����?(1-����,2-�����,3-����)");
	cin >> b;
	switch (b)
	{
	case 1:puts("� ���� 5 ������!"); break;
	case 2:puts("� ���� 7 ������!"); break;
	case 3:puts("� ���� 9 ������!"); 
		puts("��,���-�� �� ���.(1-����,2-��������� �������.)");
		cin >> b;
		switch (b)
		{
		case 1:puts("� ��� �� ������� ������?� ����� � ������ ����� �����."); break;
		case 2:puts("� ����� �����������?"); break;
		}break;
	}break;
	}
	case 2:puts("����� ��������."); break;
	case 3:puts("� ����� ����� ����?"); break;
	default:puts("������������ �������."); break;
	}
	return 0;
}