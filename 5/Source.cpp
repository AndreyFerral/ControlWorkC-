#define nrow n 
#define ncol m 
#include <fstream> 
#include <iostream> 
#include <iomanip> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int i, j, iteration;
	int max_i, max_j;
	double max;
	const int m = 3, n = 3;

	int a[m][n] = {
		{-2, -2, -3 },
		{-1, -2, -2 },
		{-3, 3, -3 }
	};

	cout << "Исходный массив:";
	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << "\t";
		}
	}
	cout << "\n\n";

	for (iteration = 0; iteration < n; iteration++) {
		/*find maximum element in the matix*/
		max_i = 0;
		max_j = 1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (!(i == j && i < iteration)) {
					if (a[i][j] > a[max_i][max_j]) {
						max_i = i;
						max_j = j;
					}
				}
			}
		}
		/*swapping maximum and diagonal elements*/
		max = a[max_i][max_j];
		a[max_i][max_j] = a[iteration][iteration];
		a[iteration][iteration] = max;
	}
	cout << endl;

	cout << "Отсортированный массив (Макс. элемент находится в (1,1), следующий по величине — в позиции(2, 2) и т.д.):";
	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << "\t";
		}
	}
	cout << "\n\n";

	for (i = 0; i < n; ++i)
	{
		int count = 0;
		for (j = 0; j < n; ++j)
			if (a[i][j] < 0)
				++count;
		if (count == n)
		{
			cout << "Строка №" << i + 1 << " не имеет положительных чисел\n";
			system("pause");
			return 0;
		}
	}
	cout << "Все строки имеют положительные числа\n";
	system("pause");
	return 0;
}