#include "�9����.h"
#include"Header.h"
using namespace std;
int main()
{
	item *head, *tail;
	item *head1, *tail1;
	item *head2, *tail2;
	setlocale(LC_CTYPE, "Russian");
	int i = 1, num = 1, z;
	head = NULL;head1 = NULL;head2 = NULL;
	tail = NULL;tail1 = NULL;tail2 = NULL;
	while (num != 0)
	{
		cout << "1 - �������� �������" << endl;
		cout << "2 - �������� ������� � ������" << endl;
		cout << "3 - ������� ������� � ������" << endl;
		cout << "4 - ������� ��������" << endl;
		cout << "5 - �������� �������" << endl;
		cout << "6 - �������� �������������� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� ��������:";
		cin >> num;
		switch (num)
		{
		case 1: cout << "������� �������:  ";
			cin >> z; 
			add(z);
			out();
			break;
		case 2: fromhead(); break;
		case 3: delet1(); break;
		case 4: out(); break;
		case 5: clrscr(); break;
		case 6: delenie(); break;
		}
	}
	return 0;
}
