#include "Header.h"
#include "К14лабе(1).h"
using namespace std;
struct AAA
{
	int key;
	char *mas;
	AAA(int k, char*z)
	{
		key = k;   mas = z;
	}
	AAA()
	{
		key = 0;   mas = "";
	}
};
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
void AAA_print(listx::Element* e)
{
	cout << ((AAA*)e->Data)->key << '-' << ((AAA*)e->Data)->mas << " / ";
}
int _tmain111(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Ведите размер хэш-таблицы" << endl;   cin >> current_size;
	hashTC::Object H = hashTC::Create(current_size, hf);
	int choise;  int k;
	for (;;)
	{
		cout << "1 - вывод хэш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choise;
		switch (choise)
		{
		case 0:  exit(0);
		case 2: {  AAA *a = new AAA; char *str = new char[20];
			cout << "введите номер школы " << endl;  cin >> k;
			a->key = k;   cout << "введите фамилию директора" << endl;
			cin >> str;   a->mas = str;   H.Insert(a);    break; }
		case 1:  H.Scan(); break;
		case 3: {  AAA *b = new AAA; cout << "введите номер школы" << endl;
			cin >> k;  b->key = k;   H.Delete(b);   break; }
		case 4: {	 AAA *c = new AAA; cout << "введите номер школы" << endl;
			cin >> k; c->key = k; unsigned int kk = clock();
			if (H.Search(c) == NULL) cout << "Элемент не найден" << endl;
			else {
				cout << "Первый элемент с данным номером школы" << endl;
				AAA_print(H.Search(c)); cout << endl;
			}unsigned int kkk = clock();
			unsigned int kkkk = kkk - kk;			cout << "Время выполнения: " << kkkk << endl;
			break;
		}
		}
	}
	return 0;
}
