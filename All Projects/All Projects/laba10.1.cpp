#include "Header.h" 
using namespace std;
int main26()
{
	setlocale(LC_CTYPE, "Russian");
	unsigned int value;
	int i;
	const unsigned int mask = 1 << 15;
	cout << "¬ведите целое число ";
	cin >> value;
	cout << "ƒвоичный вид: ";
	for (i = 1; i <= 16; i++)
	{
		if (i >= 2 && i <= 14)
		{
			putchar(mask & ~value ? '1' : '0');
			value <<= 1;
			if (i % 8 == 0)  putchar(' ');
		}
		else
		{
			putchar(mask & value ? '1' : '0');
			value <<= 1;
			if (i % 8 == 0)  putchar(' ');
		}
	}
	cout << endl;
	return 0;
}