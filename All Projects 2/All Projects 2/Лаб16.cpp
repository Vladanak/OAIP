#include "Header.h"
using namespace std;
int NNN, PERV[1000],VTOR[1000], ioo, jj, keyy;
int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j]> brd);
		while (A[++i]< brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
void SortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		SortHoar(A, sm, hb);
		SortHoar(A, hb + 1, em);
	}
};
void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 <  n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n  &&  A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void SortPiramid(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n>0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}
void SortSli(int arr[], long l, long r) { // сортировка слиянием
	if (r == l)
		return;
	if (r - l == 1)
	{
		if (arr[r] < arr[l])
			swap(arr[r], arr[l]);
		return;
	}
	long s = (l + r) / 2;//делим исходный массив попалам
	SortSli(arr, l, s);//рекурсивно обходим левую 
	SortSli(arr, s + 1, r);// и правую части
	long p1 = l, p2 = s + 1, p = 0;
	int *tmp = new int[r - l + 1];
	while (p1 <= s && p2 <= r)
		(arr[p1] < arr[p2]) ? (tmp[p++] = arr[p1++]) : (tmp[p++] = arr[p2++]);
	//сравниваем первый и последний элементы части массива
	//	если первый элемент меньше последнего - заносим его во вр.массив, иначе заносим последний элемент
	while (p2 <= r) tmp[p++] = arr[p2++];//пока правая граница части меньше правой границы исходного массива, во вр.массив заносим	элемент	по этому индексу границы /// слияние
	while (p1 <= s) tmp[p++] = arr[p1++];//пока правая граница части меньше середины исходного массива(медианы), во вр.массив заносим элемент по этому индексу границы	///
	for (p = 0; p <= r - l; ++p)
		arr[l + p] = tmp[p];//добавление элементов в исходный массив
	delete[] tmp;
}
void SortSell(int A[], int n) //сортировка выбором
{
	int count;
	for (ioo = 0; ioo<n - 1; ioo++)
	{
		count = A[ioo]; keyy = ioo;
		for (jj = ioo + 1; jj<n; jj++)
			if (A[jj]<A[keyy]) keyy = jj;
		if (keyy != ioo)
		{
			A[ioo] = A[keyy];
			A[keyy] = count;
		}
	}
	cout << "Результирующий массив: ";
	for (ioo = 0; ioo < n; ioo++) cout << A[ioo] << " ";
	cout << endl;
}
int main20()
{
	int choises,max,index,vv=0;
	bool ttz = true;
	clock_t runtime;
	for (;;)
	{
		setlocale(LC_ALL, "Russian");
		srand((unsigned)time(NULL));
		cout << "Введите кол-во элементов:"; cin >> NNN;
		for (ioo = 0; ioo < NNN; ioo++)
		{
			cout << ioo + 1 << " элемент ";
			PERV[ioo] = rand() % 999;
			cout << PERV[ioo] << endl;
		}
		for (int z = 0; z < NNN; z++)
		{
			if(z == 0){ max = PERV[z]; index = z;}
			if(PERV[z] > max){ max = PERV[z]; index = z; }
		}
		for (ioo = index; ioo < NNN; ioo++)
		{
			if (ioo % 2 == 0) continue;
			else { VTOR[vv] = PERV[ioo]; vv++; }
		}
		for (ioo = 0; ioo < vv; ioo++)
		{
			cout << VTOR[ioo] << endl;
		}
		cout << "1 - сортировка слиянием " << endl;
		cout << "2 - сортировка выбором" << endl;
		cout << "3 - сортировка пирамидальной" << endl;
		cout << "4 - сортировка Хоара" << endl;
		cout << "5 - Выход" << endl;
		cin >> choises;
		switch (choises)
		{
		case 1:
		{
			runtime = clock();
			SortSli(VTOR, 0, vv);
			cout << "Результирующий массив: ";
			for (int i = 1; i <= vv; i++) cout << VTOR[i] << " ";
			cout << endl;
			runtime = clock() - runtime;
			cout << runtime;
			break;
		}
		case 2:
		{
			runtime = clock();
			SortSell(VTOR, vv);
			runtime = clock() - runtime;
			cout << runtime;
			break;
		}
	    case 3:
		{
			runtime = clock();
			SortPiramid(VTOR, vv); 
			cout << "Результирующий массив: ";
			for (int i = 0; i < vv; i++) cout << VTOR[i] << " ";
			cout << endl;
			runtime = clock() - runtime;
			cout << runtime;
			break;
		}
		case 4:
		{
		runtime = clock();
		SortHoar(VTOR, 0, vv);
		cout << "Результирующий массив: ";
		for (int i = 1; i <= vv; i++) cout << VTOR[i] << " ";
		cout << endl;
		runtime = clock() - runtime;
		cout << runtime;
		break;
		}
		case 5:ttz = false; break;
		}
		cout << endl;
		if (ttz == false) break;
	}
	return 0;
}