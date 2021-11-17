// Lab_7_2(Iter).cpp
// Вольвенко Іван
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 13

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

void Create(int** mas, const int n, const int k, const int Low, const int High);
void Print(int** mas, const int n, const int k);
int SearchMin(int** mas, const int n, int j1);
int SearchMax(int** mas, const int n, const int k);

int main()
{
	srand((unsigned)time(NULL));
	
	int Low = 1;
	int High = 28;

	int n, k;

	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];

	Create(a, n, k, Low, High);
	Print(a, n, k);

	cout << "Max = " << SearchMax(a, n, k) << endl;

	return 0;
}

void Create(int** mas, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			mas[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** mas, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << mas[i][j];
		cout << endl;
	}
	cout << endl;
}

int SearchMin(int** mas, const int n, int j)
{
	int min = mas[0][j];
	for (int i = 0; i < n; i++)
	{
		if (mas[i][j] < min)
		{
			min = mas[i][j];
		}
	}
	return min;
}

int SearchMax(int** mas, const int n, const int k)
{
	int max;
	max = SearchMin(mas, n, 0);
	for (int g = 0; g < n; g++)
	{
		if (g % 2 == 0 && SearchMin(mas, n, g) > max)
		{
			max = SearchMin(mas, n, g);
		}
	}
	return max;
}