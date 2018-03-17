#include "Header.h"
using namespace std;
int main35()
{
	setlocale(LC_CTYPE, "Russian");
	int i,k=0;
	char* b = "bcd*d*trk*";
		char c[30];
		cout << "Заданная строка:" <<b<< endl;
	for (i = 0; i<(strlen(b)+1); i++)
	{ 
		if (b[i] != '*') {
			c[k] = b[i];
			c[k + 1] = b[i];
			k=k+2;
		}
	}
	cout <<"Строка с удалённым элементом * и с повторением отличных от него символов:"<< endl;
	for (i = 0; i < k; i++)
	{
		cout << c[i];
	}
	cout << endl;
	return 0;
}
