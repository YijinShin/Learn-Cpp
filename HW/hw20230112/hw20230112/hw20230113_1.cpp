#include <iostream>

using namespace std;

int main() {

	int iLevel(2), iNum(1);
	

	while (iLevel < 10) {

		cout << " < " << iLevel << "´Ü>" << endl;

		while (iNum < 10) {
			cout << iLevel << " X " << iNum << " = " << iLevel * iNum << endl;
			iNum++;
		}

		iNum = 1;	//initialize iNum to 1
		iLevel++;	// go to next level 

		cout << endl;
	}


}