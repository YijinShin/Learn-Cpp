#include <iostream>

using namespace std;

int main() {

	int iLevel(0), iTimes(0);

	cout << "단을 입력하세요:";
	cin >> iLevel;
	cin.ignore();

	cout << "곱을 입력하세요:";
	cin >> iTimes;
	cin.ignore();


	for (int i = 2; i <= iLevel; i++) {
		for (int j = 1; j <= iTimes; j++) {
			cout << i << " * " << j << " = " << i * j << endl;
		}

		cout << endl;
	}
}