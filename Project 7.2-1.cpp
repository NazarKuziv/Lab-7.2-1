// Lab_7_2-1.cpp
// < Кузів Назар >
// Лабораторна робота № 7.2-1
// Опрацювання багатовимірних масивів ітераційним способом
// Варіант 6

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			R[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** R, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << R[i][j];
		cout << endl;
	}
	cout << endl;
}

void SearchMax(int** R, const int rowCount, const int colCount, int* arr)
{
	int max, x = 0;

	for (int i = 0; i < rowCount; i++)
	{
		max = R[i][0];
		for (int j = 1; j < colCount; j++)
		{
			if (R[i][j] > max)
				max = R[i][j];
		}
		arr[x] = max;
		x++;
	}
	
}
int SearchMin(int *arr, const int rowCount)
{
	int min = arr[0];

	for (int i = 1; i < rowCount; i++)
		if (arr[i] < min)
			min = arr[i];
	
	return min;
}

int main()
{
	srand((unsigned)time(NULL));

	//Діапазон значень елементів матриці
	int Low = -15;
	int	High = 15;

	int	rowCount = 5; // Кількість рядків
	int	colCount = 5; // Кількість стовпців


	int** R = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];

	Create(R, rowCount, colCount, Low, High);
	Print(R, rowCount, colCount);
	cout << endl;

	int* arr = new int[rowCount];
	
	SearchMax(R, rowCount, colCount,arr);
	int Min = SearchMin(arr, rowCount);

	cout  << "  Min of Max = " << Min << endl;
 
	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;

	return 0;
}