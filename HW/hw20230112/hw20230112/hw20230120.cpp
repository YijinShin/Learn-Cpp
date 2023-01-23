#include <iostream>

using namespace std;


void Swap(int* iData, int* iSrc);
void BubbleSort(int* iArr);

int main() {
	
	// hw 1
	{
		int iArr[5][5];

		//put in 
		int iData(1);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				iArr[i][j] = iData + j;
			}
			iData = iData + 5;
		}

		//display
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << iArr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	cout << endl;


	// hw2
	{
		bool isSelected[45] = { 0 };
		int iLotto[6];
		srand(unsigned(time(nullptr)));
		
		for (int i = 0; i < 5; i++) {
			cout << "[" << i + 1 << "È¸Â÷] ";

			// make sequence 
			for (int j = 0; j < 6; j++) {
				while (1) {
					int iRandNum = rand() % 45 + 1;
					if (!isSelected[iRandNum]) {
						iLotto[j] = iRandNum;
						isSelected[iRandNum] = true;
						break;
					}
				}

			}

			// bubble sort
			BubbleSort(iLotto);

			// display
			for (int j = 0; j < 6; j++) {
				cout << iLotto[j] << "\t";
			}

			// reset isSelected 
			for(int i=0;i<45;i++) isSelected[i] = {false};
			cout << endl;
		}
	}

}

void BubbleSort(int* iArr) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			if (iArr[j] > iArr[j + 1]) Swap(&iArr[j], &iArr[j + 1]);
		}
	}
}

void Swap(int* iData, int* iSrc) {
	int iTemp(0);
	iTemp = *iData;
	*iData = *iSrc;
	*iSrc = iTemp;
}