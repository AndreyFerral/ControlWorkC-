#include <valarray>
#include <iostream>
#include <random>
#include <ctime>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	mt19937 my_gen(time(0));
	uniform_int_distribution<> int_distr(-2, 2);

	cout << "Исходный массив: " << endl;
	const size_t N = 10;
	valarray<double> valarr(N);

	generate(begin(valarr), end(valarr), [&int_distr, &my_gen]() { 
		return int_distr(my_gen); 
	});

	for (auto el : valarr) { cout << el << " "; } cout << endl;

	int CountPositive = count_if(begin(valarr), end(valarr), [](int numb) {return numb >= 0;  });
	cout << "\nПоложительных элементов (0 тоже): " << CountPositive << endl;
	
	int count = count_if(begin(valarr), end(valarr), [](double el) { return el == 0; });
	if (count > 0) {
		auto rFirstZero = find_if(begin(valarr), end(valarr), [&count](double el) {
			if (el == 0) count--;
			return !count;
		});
		auto result = accumulate(rFirstZero, end(valarr), 0);
		cout << "\nСумма элементов после посл нуля: " << result << endl;
	}
	else cout << "\nСумма элементов после посл нуля: Нулей не найдено. "<< endl;

	sort(begin(valarr), end(valarr), [](int a, int b) { return a < b; });

	cout << "\nМассив, в которым сначала элементы <2, далее остальные:\n";
	for (auto el : valarr) { cout << el << " "; } cout << endl;

	system("pause");
}