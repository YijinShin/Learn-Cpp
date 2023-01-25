#include <iostream>

using namespace std;

void Swap(int* iData, int* iSrc);


int main() {
	int iArray[9];
	int iInputArray[3];
	int iAnswerArray[3];
	int iStrikeCnt(0), iBallCnt(0);
	bool isWin = false;

	srand(unsigned(time(nullptr)));

	// mix number
	for (int i = 0; i < 100; i++) {
		int iIndex = rand() % 9 + 1;
		Swap(&iArray[iIndex], &iArray[iIndex]);
	}

	// create answer
	for (int j = 0; j < 3; j++) {
		iAnswerArray[j] = rand() % 9 + 1;
	}
	cout << "정답: " << iAnswerArray[0] << "," << iAnswerArray[1] << "," << iAnswerArray[2] << endl;

	for (int i = 0; i < 9; i++) {
		
		// init
		iStrikeCnt = 0;
		iBallCnt = 0;

		// get input 
		cout << "[" << i << "회] 숫자 1~9 중 3개를 입력해주세요: ";
		for (int j = 0; j < 3; j++) {
			cin >> iInputArray[j];
			cin.ignore();
		}

		// check result
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (iAnswerArray[j] == iInputArray[k] && j==k) iStrikeCnt++;
				else if (iAnswerArray[j] == iInputArray[k] && j!=k) iBallCnt++;
			}
		}

		// display result
		cout << "결과 : " << iStrikeCnt << "스트라이크 " << iBallCnt << "볼" << endl << endl;

		if (iStrikeCnt == 3) {
			isWin = true;
			break;
		} 
		
	}

	if (isWin) cout << "~~ YOU WIN ~~" << endl;
	else cout << "~~ YOU LOSE ~~" << endl;
}


void Swap(int* iData, int* iSrc) {
	int iTemp;

	iTemp = *iData;
	*iData = *iSrc;
	*iSrc = iTemp;
}

