#include "Header.h"
#include "�11.h"
#include <fstream>
using namespace std;
int a[20];
int i = 0, zs = 800;
btree::CMP cmpfnc(void* x, void* y)    // ���������
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key  <  ((NodeTree*)y)->key)        rc = btree::LESS;
	else   if (((NodeTree*)x)->key  >((NodeTree*)y)->key)       rc = btree::GREAT;
	return rc;
}
void Print(void* x)    // ����� ��� ������
{
	cout << ((NodeTree*)x)->key << " " << ends;

}
void Print2(void* x)    // ����� ��� ������
{
	cout << ((NodeTree*)x)->key << ends;
	a[i] = ((NodeTree*)x)->key;
	i++;
}
bool BuildTree(char *FileName, btree::Object& tree)     //���������� ������ �� �����
{
	bool rc = true;     FILE *inFile = fopen(FileName, "r");
	if (inFile == NULL) { cout << "������ �������� �������� �����" << endl; rc = false; }
	cout << "    �������� ������" << endl;     // ���������� ������ � �����  �������� ������
	while (!feof(inFile))
	{
		int num;   fscanf(inFile, "%d", &num, 1);
		NodeTree *a = new NodeTree();
		a->key = num;  tree.Insert(a);    cout << num << endl;
	}
	fclose(inFile);  return rc;
}
FILE * outFile;
void SaveToFile(void *x)     // ������ ������ �������� � ����
{
	NodeTree *a = (NodeTree*)x;      int q = a->key;
	fprintf(outFile, "%d\n", q);
}
void SaveTree(btree::Object &tree, char *FileName)    //���������� ������ � ���� 
{
	outFile = fopen(FileName, "w");
	if (outFile == NULL)
	{
		cout << "������ �������� ��������� �����" << endl;  return;
	}
	tree.Root->ScanDown(SaveToFile);
	fclose(outFile);
}
int main13()
{
	setlocale(LC_CTYPE, "Russian");
	btree::Object t1 = btree::Create(cmpfnc);  int k = 0, choise;
	for (;;)
	{
		NodeTree *a = new NodeTree;
		cout << "1 - ����� ������ �� �����" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ��������� � ����" << endl;
		cout << "5 - ��������� �� �����" << endl;
		cout << "6 - �������� ������" << endl;
		cout << "7 - ���������� �����" << endl;
		cout << "8 - ��������� �����" << endl;
		cout << "9 - �������� ������������������" << endl;
		cout << "10 - ������� �� 10 ����" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl; cin >> choise;
		switch (choise)
		{
		case 0:   exit(0);
		case 2:   cout << "������� ����" << endl;   cin >> k;
			a->key = k;	t1.Insert(a);   break;
		case 1:   if (t1.Root)    t1.Root->ScanByLevel(Print);
				  else    cout << "������ ������" << endl;	break;
		case 3:   cout << "������� ����" << endl;  cin >> k; zs = k;
			a->key = k;  	t1.Delete(a);   break;
		case 4:    SaveTree(t1, "G.txt");	break;
		case 5:    BuildTree("G.txt", t1);	break;
		case 6: {      while (t1.Root)	  t1.Delete(t1.Root);     }   break;
		case 7:    t1.Root->DescScan(Print); cout << endl; break;
		case 8:    t1.Root->MixedScan(Print); cout << endl; break;
		case 9:    t1.Balance(t1.Root); break;
		case 10:  if (t1.Root)    t1.Root->ScanByLevel(Print);
				  else    cout << "������ ������" << endl;	break;
		}
	}
	return 0;
}
