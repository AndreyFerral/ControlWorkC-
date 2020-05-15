#include <fstream>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int len = 150;
	char line[len];
	string word;
	int count = 0;
	cout << "Введите слово для поиска: "; cin >> word;
	ifstream fin("text.txt");
	if (!fin) { cout << "Ошибка открытия файла." << endl; return 1; }
	regex WordRegular(word);

	while (fin.getline(line, len)) {
		cout << "\n" << line << "\n";
		string LineRegular = line;
		regex_iterator<string::iterator> rit(LineRegular.begin(), LineRegular.end(), WordRegular);
		regex_iterator<string::iterator> rend;
		while (rit != rend) {
			for (int i = 0; i < rit->size(); ++i) {
				++count;
			}
			++rit;
		}
		cout << "В предложении введенное слово встретилось: " << count << " раз(а).\n";
		count = 0;
	}
	system("pause");
}