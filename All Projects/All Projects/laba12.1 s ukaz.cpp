#include "Header.h"
using namespace std;
int main32()
{
	setlocale(LC_CTYPE, "Russian");
	char* str = "DEAD * START * MAYBE";
	int c = 0;
	for (int i = 0; i <21; i++)
	{
		if (c == 0)
		{
			if (*(str+i) == '*')
				c++;
		}
		else
			if (*(str + i) == '*')
				break;
			else
				cout << *(str + i);
	}
	cout << endl;
	return 0;
}