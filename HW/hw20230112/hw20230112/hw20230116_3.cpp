#include <iostream>

using namespace std;

int main() {

	cout << " [ ����� 1 ] " << endl;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;


	cout << " [ ����� 2 ] " << endl;
	for (int i = 5; i >=1; i--) {

		int j = i;

		//print ' '
		for (; j > 0; j--) {
			cout << "*";
		}
		
		j = (5-i);

		// print *
		for (; j > 0; j--) {
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << " [ ����� 3 ] " << endl;
	for (int i = 1; i <= 5; i++) {

		int j = (5 - i);

		// print ' '
		for (; j > 0; j--) {
			cout << ' ';
		}

		j = i;

		//print *
		for (; j > 0; j--) {
			cout << "*";
		}

		cout << endl;

	}
	cout << endl;

	cout << " [ ����� 4 ] " << endl;
	for (int i = 5; i >= 1; i--) {
		
		int j = (5 - i);

		// print *
		for (; j > 0; j--) {
			cout << ' ';
		}
		
		j = i;

		//print ' '
		for (; j > 0; j--) {
			cout << "*";
		}

		cout << endl;
	}
	cout << endl;






}