#include "Header.h"
#include "К11.h"
#include <fstream>
using namespace std;
int a[20];
int i = 0, zs = 800;
btree::CMP cmpfnc(void* x, void* y)    // Сравнение
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key  <  ((NodeTree*)y)->key)        rc = btree::LESS;
	else   if (((NodeTree*)x)->key  >((NodeTree*)y)->key)       rc = btree::GREAT;
	return rc;
}
void Print(void* x)    // Вывод при обходе
{
	cout << ((NodeTree*)x)->key << " " << ends;

}
void Print2(void* x)    // Вывод при обходе
{
	cout << ((NodeTree*)x)->key << ends;
	a[i] = ((NodeTree*)x)->key;
	i++;
}
bool BuildTree(char *FileName, btree::Object& tree)     //Построение дерева из файла
{
	bool rc = true;     FILE *inFile = fopen(FileName, "r");
	if (inFile == NULL) { cout << "Ошибка открытия входного файла" << endl; rc = false; }
	cout << "    Исходные данные" << endl;     // заполнение дерева и вывод  исходных данных
	while (!feof(inFile))
	{
		int num;   fscanf(inFile, "%d", &num, 1);
		NodeTree *a = new NodeTree();
		a->key = num;  tree.Insert(a);    cout << num << endl;
	}
	fclose(inFile);  return rc;
}
FILE * outFile;
void SaveToFile(void *x)     // Запись одного элемента в файл
{
	NodeTree *a = (NodeTree*)x;      int q = a->key;
	fprintf(outFile, "%d\n", q);
}
void SaveTree(btree::Object &tree, char *FileName)    //Сохранение дерева в файл 
{
	outFile = fopen(FileName, "w");
	if (outFile == NULL)
	{
		cout << "Ошибка открытия выходного файла" << endl;  return;
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
		cout << "1 - Вывод дерева на экран" << endl;
		cout << "2 - Добавление элемента" << endl;
		cout << "3 - Удаление элемента" << endl;
		cout << "4 - Сохранить в файл" << endl;
		cout << "5 - Загрузить из файла" << endl;
		cout << "6 - Очистить дерево" << endl;
		cout << "7 - Нисходящий обход" << endl;
		cout << "8 - Смешанный обход" << endl;
		cout << "9 - Проверка сбалансированности" << endl;
		cout << "10 - Функция из 10 лабы" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choise;
		switch (choise)
		{
		case 0:   exit(0);
		case 2:   cout << "введите ключ" << endl;   cin >> k;
			a->key = k;	t1.Insert(a);   break;
		case 1:   if (t1.Root)    t1.Root->ScanByLevel(Print);
				  else    cout << "Дерево пустое" << endl;	break;
		case 3:   cout << "введите ключ" << endl;  cin >> k; zs = k;
			a->key = k;  	t1.Delete(a);   break;
		case 4:    SaveTree(t1, "G.txt");	break;
		case 5:    BuildTree("G.txt", t1);	break;
		case 6: {      while (t1.Root)	  t1.Delete(t1.Root);     }   break;
		case 7:    t1.Root->DescScan(Print); cout << endl; break;
		case 8:    t1.Root->MixedScan(Print); cout << endl; break;
		case 9:    t1.Balance(t1.Root); break;
		case 10:  if (t1.Root)    t1.Root->ScanByLevel(Print);
				  else    cout << "Дерево пустое" << endl;	break;
		}
	}
	return 0;
}
