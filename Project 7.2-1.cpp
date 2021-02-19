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
int Sum(int** R, const int rowCount, const int colCount, int S)
{
	S = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (R[i][j] % 7 == 0 || i % 2 != 0 || j % 2 != 0)
			{
				S += R[i][j];
			}
	return S;
}

void SearchMin(int** R, const int rowCount, const int colCount, int* arr)
{
	int min, x = 0;

	for (int i = 0; i < rowCount; i++)
	{
		min = R[i][0];
		for (int j = 1; j < colCount; j++)
		{
			if (R[i][j] < min)
				min = R[i][j];
		}
		arr[x] = min;
		x++;
	}
	
}
void PrintMin(int *arr, const int rowCount)
{
	int x = 1;

	for (int i = 0; i < rowCount; i++)
	{
		cout << "  Min Row "<< x <<" = " << arr[i] << endl;
		cout << endl;
		x++;
	}
	
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
	SearchMin(R, rowCount, colCount,arr);
	PrintMin (arr, rowCount);

	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;

	return 0;
}