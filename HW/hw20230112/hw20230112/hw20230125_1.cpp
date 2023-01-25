#include <iostream>

using namespace std;

void Display(int(*iArray)[3]);
void Rotation(int(*iArray)[3]);
void Swap(int* iData, int* iSrc);

int main() {
	int iArray[3][3];
	
	//initialize
	int iData = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			iArray[i][j] = iData + j;
 		}
		iData = iData + 3;
	}

	// display
	Display(iArray);
	
	for (int i = 0; i < 4; i++) {
		// rotation 
		Rotation(iArray);
		// display
		Display(iArray);

	}

}

void Rotation(int (*iArray)[3]) {
	int iRotatedArray[3][3];

	// 열과 행의 위치를 바꾸기 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			iRotatedArray[j][3-i-1] = iArray[i][j];
		}
	}

	// copy
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			iArray[i][j] = iRotatedArray[i][j];
		}
	}
}

void Swap(int* iData, int* iSrc) {
	int iTemp = *iSrc;
	*iSrc = *iData;
	*iData = iTemp;
}

void Display(int (*iArray)[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}