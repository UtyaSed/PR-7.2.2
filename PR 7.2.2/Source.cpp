// Lab_7_2_1.cpp
// Обухова Віктора
// Лабораторна робота No 7.2.1)
// Опрацювання багатовимірних масивів рекурсивним способом.
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int MinRow(int** R, const int rowNo, const int colCount, int colNo, int min);

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	R[i][j] = Low + rand() % (High - Low + 1);

	if (j < colCount - 1)
		Create(R, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(R, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** R, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << R[i][j];
	if (j < colCount - 1)
		Print(R, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(R, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int MaxofMin(int** R, const int rowCount, const int colCount, int rowNo, int max)
{
	int min = R[rowNo][0];
	min = MinRow(R, rowNo, colCount, 1, min);

	if (rowNo == 0)
		max = min;

	if (max < min)
		max = min;

	if (rowNo < rowCount - 1)
		MaxofMin(R, rowCount, colCount, rowNo + 1, max);
	else
		return max;
}

int MinRow(int** R, const int rowNo, const int colCount, int colNo, int min)
	{
	if (R[rowNo][colNo] < min)
		min = R[rowNo][colNo];

	if (colNo < colCount - 1)
		MinRow(R, rowNo, colCount, colNo + 1, min);

	 else
	 {
		cout << " Min = " << min << endl;
		return min;
	 }

	}

int main()
{
	srand((unsigned)time(NULL));
	
	int Low = 5;
	int High = 20;

	int rowCount = 5;
	int colCount = 5;

	int** R = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];

	Create(R, rowCount, colCount, Low, High, 0, 0);
	Print(R, rowCount, colCount, 0, 0);
	cout << endl;

	int Max;
	Max = MaxofMin(R, colCount, rowCount, 0, 0);

	cout << endl;
	cout << "Max of Min = " << Max << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;

	return 0;
}