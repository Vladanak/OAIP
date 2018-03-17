#include "Header.h"                /*16 вар 1 зад */
using namespace std;
int main27()
{
	setlocale(LC_CTYPE, "Russian");
	int A, B; char tmp[33];
	cout<<"Введите целое число А:";
	cin>>A;
	cout<<"Введите целое число B:";
	cin>>B;
	_itoa_s(A, tmp, 2); cout<<"Число А в двоичной системе: "<<tmp<<endl;
	_itoa_s(B, tmp, 2); cout<<"Число B в двоичной системе: "<<tmp<<endl;
	_itoa_s(0xE, tmp, 2); cout<<"Маска для числа А "<<tmp<<endl;
	_itoa_s(A & 0xE, tmp, 2);
	 cout<<"Взятые 3 бита из числа А начиная со второго: "<<tmp<<endl;
	_itoa_s(0x1F8, tmp, 2); cout<<"Маска для В: "<<tmp<<endl;
	_itoa_s(B & 0x1F8, tmp, 2); cout<<"Очищенные биты в В: "<<tmp<<endl;
	_itoa_s(((B & 0x1F8) | ((A & 0xE)>>1)), tmp, 2);
	cout<<"Результат В="<<tmp<<endl;
	return 0;
}