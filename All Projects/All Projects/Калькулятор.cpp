#include "Header.h"
using namespace std;
int main() 
{
	setlocale(LC_ALL, "Russian");
	long double a, b, c, h;
	int d, f;
	char y[20], x[20],m;
	for ( ; ; )
	{
		cout << "�����������  VERSION 0.1"<< endl;
		cout << "������� ������ �����:";
		cin >> a;
		cout<<"������� ������ �����:";
		cin >> b;
		puts("�������� ��������: (1-��������,2-��������,3-���������,4-�������,5-���������� ����������� �����,6-���������� � �������,7-������������������ ��������,8-������� ������� ��� ������� ����� � �������� ������� ���������)");
		cin >> d;
		switch (d)
		{
		case 1:
			cout << a << "+" << b << "=" << a + b << endl;
			break;
		case 2:
			cout << a << "-" << b << "=" << a - b << endl;
			break;
		case 3:
			cout << a << "*" << b << "=" << a*b << endl;
			break;
		case 4:
			cout << a << "/" << b << "=" << a / b << endl;
			if (b == 0)
				printf_s(" �� ���� ������ ������! \n");
			break;
		case 5:
			puts("�� ������ ����� ��������� ������? ��(1-��� ��� 2-���):");
			cin >> d;
			switch (d)
			{
			case 1:
				if (a < 0)
				{
					cout << "��������� ������ �� �������������� ����� ������!" << endl;
				}
				else
				{
					cout << "���������� ������ �� " << a << " = " << sqrt(a) << endl;
				}
				break;
			case 2:
				if (b < 0)
				{
					cout << "��������� ������ �� �������������� ����� ������!" << endl;
				}
				else
				{
					cout << "���������� ������ �� " << b << " = " << sqrt(b) << endl;
				}
				break;
			}
			break;
		case 6:
			cout << "� ����� ������� �������� ����� " << a << " ? " << endl;
			cout << "� ";
			cin >> f;
			cout << "����� " << a << " � ������� " << f << " ����� ����� " << pow(a, f) << "." << endl;
			break;
		case 7:
			puts("��������,� ����� ������ ��������� ����������(� 1-�� ��� 2-��):");
			cin >> d;
			switch (d)
			{
			case 1:
				puts("��������,��� ��������� (1-Sin,2-Cos,3-Tan) ");
				cin >> d;
				switch (d)
				{
				case 1:
					cout << "����� ����� " << a << " ����� " << sin(a) << endl;
					break;
				case 2:
					cout << "������� ����� " << a << " ����� " << cos(a) << endl;
					break;
				case 3:
					cout << "������� ����� " << a << " ����� " << tan(a) << endl;
					break;
				}
				break;
			case 2:
				puts("��������,��� ��������� (1-Sin,2-Cos,3-Tan) ");
				cin >> d;
				switch (d)
				{
				case 1:
					cout << "����� ����� " << b << " ����� " << sin(b) << endl;
					break;
				case 2:
					cout << "������� ����� " << b << " ����� " << cos(b) << endl;
					break;
				case 3:
					cout << "������� ����� " << b << " ����� " << tan(b) << endl;
					break;
				}
				break;
			}
			break;
		case 8:
			puts("�������� ���������� ������ ����� ��� ������?(1-������,2-������)");
			cin >> d;
			switch (d)
			{
			case 1:
				_itoa_s(a, y, 2);
				cout << "������ ����� � �������� ������� ��������� : " << y << endl;
				break;
			case 2:
				_itoa_s(b, x, 2);
				cout << "������ ����� � �������� ������� ��������� : " << x << endl;
				break;
			}
		}
		s:
		cout << "����������?" << endl <<"Y ��� N"<<endl;
		if (cin >> m && m == 'Y' || m =='y')
		{
			system("cls");
			continue;
		}
		else
			if (m == 'N'||m =='n')
			{
				system("cls");
				cout << "����� ��������!" << endl;
				break;
			}
			else
				goto s;
	}
	return 0;
}