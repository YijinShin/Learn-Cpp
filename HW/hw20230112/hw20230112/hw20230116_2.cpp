#include <iostream>

using namespace std;

int main() {

	int iLevel(0), iTimes(0);

	cout << "���� �Է��ϼ���:";
	cin >> iLevel;
	cin.ignore();

	cout << "���� �Է��ϼ���:";
	cin >> iTimes;
	cin.ignore();


	for (int i = 2; i <= iLevel; i++) {
		for (int j = 1; j <= iTimes; j++) {
			cout << i << " * " << j << " = " << i * j << endl;
		}

		cout << endl;
	}
}