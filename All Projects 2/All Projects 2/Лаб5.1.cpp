#include "Header.h"
using namespace std;

int main7()
{
	char d[] = { '�','�','�','�','�','�','�','�','�' };
	int a,z=0,m=0;
	char s[100];
	int k=0;
	setlocale(LC_ALL, "Russian");
	ifstream in;
	ofstream out;
	cout << "������� ����� ������ � ������� �������� ������ �����:" << endl;
	cin >> a;
	out.open("a2.txt", ios_base::out);
	in.open("a.txt", ios_base::in);
	while (!in.getline(s, sizeof(s)).eof())
	{
		cout << s << endl;
		if ((k == a)&&(z!=5))
		{
			out << s << endl;
			z++;
			a++;
			for (int b = 0; b < strlen(s); b++)
			{
				for (int n = 0; n < strlen(d); n++)
				{
					if (s[b] == d[n])
					{
						m++;
					}
				}
			}
		}
		k++;
	}
	cout<<"�� ������ ����� ����� ������� ���� �����:"<< m <<".������ ������� ���� � ���������,���� ������������!"<< endl;
	out.close();
	in.close();
	return 0;
}