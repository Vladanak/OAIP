#include "Header.h"                /*16 ��� 1 ��� */
using namespace std;
int main27()
{
	setlocale(LC_CTYPE, "Russian");
	int A, B; char tmp[33];
	cout<<"������� ����� ����� �:";
	cin>>A;
	cout<<"������� ����� ����� B:";
	cin>>B;
	_itoa_s(A, tmp, 2); cout<<"����� � � �������� �������: "<<tmp<<endl;
	_itoa_s(B, tmp, 2); cout<<"����� B � �������� �������: "<<tmp<<endl;
	_itoa_s(0xE, tmp, 2); cout<<"����� ��� ����� � "<<tmp<<endl;
	_itoa_s(A & 0xE, tmp, 2);
	 cout<<"������ 3 ���� �� ����� � ������� �� �������: "<<tmp<<endl;
	_itoa_s(0x1F8, tmp, 2); cout<<"����� ��� �: "<<tmp<<endl;
	_itoa_s(B & 0x1F8, tmp, 2); cout<<"��������� ���� � �: "<<tmp<<endl;
	_itoa_s(((B & 0x1F8) | ((A & 0xE)>>1)), tmp, 2);
	cout<<"��������� �="<<tmp<<endl;
	return 0;
}