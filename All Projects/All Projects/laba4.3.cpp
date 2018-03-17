#include "Header.h"
using namespace std;
int main9()
{
	setlocale(LC_CTYPE, "Russian");
	int b;
	puts("Чего ты хочешь:Яблоко или Апельсин или специальное предложение?(1-яблоко,2-апельсин,3-спец.предложение)");
	cin >> b;
	switch (b)
	{case 1:
	{puts("Сколько Штук?(1-пять,2-шесть,3-семь)");
	cin >> b;
	switch (b)
	{
	case 1:puts("С тебя 5 рублей!"); break;
	case 2:puts("С тебя 7 рублей!"); break;
	case 3:puts("С тебя 9 рублей!"); 
		puts("Хм,что-то не так.(1-уйти,2-применить харизму.)");
		cin >> b;
		switch (b)
		{
		case 1:puts("А это не слишком дорого?Я лучше в другом месте поищу."); break;
		case 2:puts("А может договоримся?"); break;
		}break;
	}break;
	}
	case 2:puts("Товар кончился."); break;
	case 3:puts("А может лучше мяса?"); break;
	default:puts("Некорректный вариант."); break;
	}
	return 0;
}