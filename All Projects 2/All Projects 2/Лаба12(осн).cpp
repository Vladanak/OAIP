#include "Header.h"
#include "К12лабе.h"
using namespace std;
heap::CMP cmpAAA(void*  a1, void* a2)  //Функция сравнения
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
bool BuildHeap(char *FileName, heap::Heap& h)      // Построение кучи из файла
{
	bool rc = true;   int n;
	ifstream inFile;
	inFile.open(FileName, std::ios::out);
	if (!inFile)
	{
		cout << "Невозможно открыть файл" << endl;  exit(1);
	}
	while (inFile >> n)
	{
		int *a = new int;
		*a = n;    h.Insertt((void*)a);
	}
	inFile.close(); return rc;
}
void SaveHeap(heap::Heap &h, char *FileName) // Функция записи в файл
{
	ofstream  outFile(FileName, ios_base::out | ios_base::trunc);
	if (!outFile)
	{
		cout << "Ошибка открытия выходного файла" << std::endl;
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
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - очистить кучу" << endl;
		cout << "5 - сохранить в файл" << endl;
		cout << "6 - загрузить из файла" << endl;
		cout << "7 - удаление n-го элемента " << endl;
		cout << "8 - удаление минимального элемента" << endl;
		cout << "9 - добавление во 2-ую кучу" << endl;
		cout << "10 - просмотр 2 кучи" << endl;
		cout << "11 - объединение 2 куч" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choise;
		AAA *a = new AAA;
		switch (choise)
		{
		case 0:  exit(0);
		case 1: system("cls"); h1.Scan(0);   break;
		case 2: system("cls");  cout << "введите ключ" << endl;    cin >> k; a->x = k;	 h1.Insertt(a);   break;
		case 3: system("cls"); h1.ExtractMax();   break;
		case 4: system("cls");  h1.DeleteHeap();    break;
		case 5: system("cls");  SaveHeap(h1, "G.txt");    break;
		case 6: system("cls");  h1.DeleteHeap(); BuildHeap("G.txt", h1); break;
		case 7:  system("cls"); h1.ExtractIT(); break;
		case 8: system("cls");  h1.ExtractMin(); break;
		case 9: system("cls");  cout << "введите ключ" << endl;    cin >> k; a->x = k;	 h2.Insertt(a);   break;
		case 10:system("cls");  h2.Scan(0);   break;
		case 11: system("cls");  while (h2.Size != 0) { h1.Insertt(h2.ExtractMax()); } break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} 
	return 0;
}
