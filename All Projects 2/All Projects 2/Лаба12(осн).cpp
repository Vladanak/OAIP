#include "Header.h"
#include "�12����.h"
using namespace std;
heap::CMP cmpAAA(void*  a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP     rc = heap::EQUAL;
	if (A1->x  >  A2->x)   rc = heap::GREAT;
	else if (A2->x  > A1->x)  rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
bool BuildHeap(char *FileName, heap::Heap& h)      // ���������� ���� �� �����
{
	bool rc = true;   int n;
	ifstream inFile;
	inFile.open(FileName, std::ios::out);
	if (!inFile)
	{
		cout << "���������� ������� ����" << endl;  exit(1);
	}
	while (inFile >> n)
	{
		int *a = new int;
		*a = n;    h.Insertt((void*)a);
	}
	inFile.close(); return rc;
}
void SaveHeap(heap::Heap &h, char *FileName) // ������� ������ � ����
{
	ofstream  outFile(FileName, ios_base::out | ios_base::trunc);
	if (!outFile)
	{
		cout << "������ �������� ��������� �����" << std::endl;
		return;
	}
	int *a = new int;
	for (int u = 0, y = 0; u < h.Size; u++)
	{
		a = (int*)h.Storage[u];
		outFile << *a;
		outFile << endl;
	}
	outFile.close();
}
int main14()
{
	setlocale(LC_ALL, "rus");
	int k;	int choise; heap::Heap h1 = heap::Createc(30, cmpAAA); heap::Heap h2 = heap::Createc(30, cmpAAA);
	for (;;)
	{
		cout << "1 - ����� ���� �� �����" << endl;
		cout << "2 - �������� �������" << endl;
		cout << "3 - ������� ������������ �������" << endl;
		cout << "4 - �������� ����" << endl;
		cout << "5 - ��������� � ����" << endl;
		cout << "6 - ��������� �� �����" << endl;
		cout << "7 - �������� n-�� �������� " << endl;
		cout << "8 - �������� ������������ ��������" << endl;
		cout << "9 - ���������� �� 2-�� ����" << endl;
		cout << "10 - �������� 2 ����" << endl;
		cout << "11 - ����������� 2 ���" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;  cin >> choise;
		AAA *a = new AAA;
		switch (choise)
		{
		case 0:  exit(0);
		case 1: system("cls"); h1.Scan(0);   break;
		case 2: system("cls");  cout << "������� ����" << endl;    cin >> k; a->x = k;	 h1.Insertt(a);   break;
		case 3: system("cls"); h1.ExtractMax();   break;
		case 4: system("cls");  h1.DeleteHeap();    break;
		case 5: system("cls");  SaveHeap(h1, "G.txt");    break;
		case 6: system("cls");  h1.DeleteHeap(); BuildHeap("G.txt", h1); break;
		case 7:  system("cls"); h1.ExtractIT(); break;
		case 8: system("cls");  h1.ExtractMin(); break;
		case 9: system("cls");  cout << "������� ����" << endl;    cin >> k; a->x = k;	 h2.Insertt(a);   break;
		case 10:system("cls");  h2.Scan(0);   break;
		case 11: system("cls");  while (h2.Size != 0) { h1.Insertt(h2.ExtractMax()); } break;
		default:  cout << endl << "������� �������� �������!" << endl;
		}
	} 
	return 0;
}
