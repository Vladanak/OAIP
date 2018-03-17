#include "Header.h"
using namespace std;
double func(int n,int d)
{
	if (n < 1)
		return 0;
	if (n==d)
		return sqrt(1+n+n);
	else
		return sqrt(1+(n+d)*func(n,d+1));
}
void main1()
{
	setlocale(LC_ALL, "Russian");
	double n,b;
	cout << "Введите n:";
	cin >> n;
	b=func(n,1);
	cout <<"Ответ:"<< b << endl;
}