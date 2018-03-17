#include "Header.h"
using namespace std;
void dr(char *str);
char  *fmax(char *c, int n,char *A,char *B)
{
	int i; 
	char *pm;
	for (pm = c; n>0; c++,n--)
		if (*B == *pm)
			*pm=*A;
	return pm;
}
int main44()
{
	setlocale(LC_CTYPE, "Russian");
	int i, k = 0,d=0;
	char *c,*m,*n;
	char* b = "Cool Boy with His Brother"; \
		n = new char[1];
	    m = new char[1];
		n[0] = '*';
		m[0] = 'O';
	c=new char [30];
	cout << "Заданная строка:" << b << endl;
	for (i = 0; i<(strlen(b) + 1); i++)
	{
		if (b[i] != 'B') {
			c[k] = b[i];
			c[k + 1] = b[i];
			k = k + 1;
		}
	}
	cout << "Строка с удалённым символом B:";
	for (i = 0; i < strlen(b); i++)
	{
		cout << c[i];
	}
	cout << endl;
	dr(c);
	cout <<"Указатель как результат выполнения"<< endl;
	(*fmax(c, strlen(c), m, n));
	for (i = 0; i < strlen(c); i++)
	{
		cout << c[i] ;
	}
	cout << endl;
	return 0;                                           
	delete[] n;
	delete[] m;
	delete[] c;
}
void dr(char *str)
{
	cout << "Указатель как ф.параметр:" << endl;
	for (int t = 0; str[t]; ++t)
	{
			str[t] = toupper(str[t]);
			if (t % 2 == 0)
			{
				str[t] = '*';
			}
			cout << str[t];
	}
	cout << endl;
}



