#include <valarray>
#include <iostream>
#include <random>
#include <numeric>
#include <algorithm>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	const size_t row = 3;
	const size_t col = 3;
	int mins[row], maxs[col];
	mt19937 my_gen(time(0));
	uniform_int_distribution<> int_distr(-1, 25);
	cout << "Изначальный двумерный массив: " << endl;
	valarray<valarray <int> > valarr(valarray<int>(col), row);
	valarray<valarray <int> > transportValarr(valarray<int>(row), col);
	for (auto& subValarr : valarr) {
		generate(begin(subValarr), end(subValarr), [&int_distr, &my_gen]() {
			return int_distr(my_gen);
			});
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			transportValarr[i][j] = valarr[j][i];
		}
	}
	for (auto subValarr : valarr) {
		for (auto el : subValarr) {
			cout << setw(4) << el;
		}
		cout << endl;
	}   cout << endl;

	int i = 0, j = 0;
	valarray <int> odin(row * col);
	for (auto subValarr : valarr) {
		for (auto el : subValarr) {
			odin[i] = el;
			i++;
		}
	}
	
	int* valueMax = new int[row];
	int* MaxE = new int;
	
	for (i = 0; i < row; ++i) {
		auto MaxElem = max_element(begin(odin), end(odin));
		valueMax[i] = *MaxElem;
		*MaxElem = odin.min();
		for (j = 0; j < col; ++j) {
			MaxE = find(begin(valarr[j]), end(valarr[j]), valueMax[i]);
			if (MaxE != end(valarr[j])) break;
		}
		int dis = distance(begin(valarr[j]), MaxE);
		if (i != j || i != dis) {
			swap(valarr[i][i], valarr[j][dis]);
		}
	}
	
	for (auto subValarr : valarr) {
		for (auto el : subValarr) {
			cout << setw(4) << el;
		}
		cout << endl;
	}   cout << endl;

	for (i = 0; i < row; ++i) {
		valarray<int> temp = valarr[i][slice(0, col, 1)];
		auto fif = find_if(begin(temp), end(temp), [](int x) {
			return x >= 0;
		});
		if (fif == end(temp)) {
			cout << "В строке " << i << " все элементы отрицательны\n "<< endl;
			break;
		}
	}
	if (i == row) cout << "Нет строк, в которых все элементы отрицательны\n" << endl;

	system("pause");

}