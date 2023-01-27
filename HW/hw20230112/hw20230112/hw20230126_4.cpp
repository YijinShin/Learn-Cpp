/* 1번과제의 심화 ver2 컴퓨터 vs 사람*/
#include <iostream>

using namespace std;

void Swap(int* iData, int* iSrc);
void Display(const int iArray_1p[], const int iArray_2p[]);
int CheckBingoCnt(const int iArray[]);
void MixArray(int* iArray);
void InitializeArray(int* iArray);
void CheckNumber(int* iArray, int iSelectedNum);

int main() {
	int iArray_1p[25];		
	int iArray_2p[25];	// 컴퓨터 
	bool iArray_selectedNum[25] = { false };

	int iInput(0);
	int iBingoCnt[2] = { 0,0 };
	int iTurn(1);	// input 차례
	int iWinner(0);	//1:1p, 2:2p, 0:무승부 
	bool isGameEnd = false;
	srand(unsigned(time(nullptr)));


	//init iArray
	InitializeArray(iArray_1p);
	InitializeArray(iArray_2p);

	// mix iArray
	MixArray(iArray_1p);
	MixArray(iArray_2p);

	// Display
	cout << "-----------[1p 빙고판]-----------\t\t\t\t-----------[2p 빙고판]-----------" << endl;
	Display(iArray_1p, iArray_2p);
	cout << endl;

	// game start
	while (1) {

		// get Input
		if (iTurn == 1) { //  사람 차례
			while (1) {
				cout << "[" << iTurn << "p) 1~25 중 하나의 숫자를 입력하세요.] : ";
				cin >> iInput;

				if (iInput > 25 || iInput < 1) {
					cout << "(잘못된 입력입니다)";
				}
				else if (iArray_selectedNum[iInput - 1]) {
					cout << "(이미 제시된 숫자입니다!)";
				}
				else break;
			}
		}
		else if (iTurn == 2) {	// 컴퓨터 차례

			while (1) {
				int iInput = rand() % 25 + 1;
				if (iArray_selectedNum[iInput - 1]) {
					iInput = rand() % 25 + 1;
				}
				else break;

			}
			cout << "[" << iTurn << "p) 컴퓨터가 숫자를 제시합니다.] : " << iInput << endl;
		}

		// check the number is selected
		iArray_selectedNum[iInput - 1] = true;

		// change turn 
		if (iTurn == 1) iTurn = 2;
		else if (iTurn == 2) iTurn = 1;

		// check number on the bingoboard
		CheckNumber(iArray_1p, iInput);
		CheckNumber(iArray_2p, iInput);

		// check bingo count 
		iBingoCnt[0] = CheckBingoCnt(iArray_1p);
		iBingoCnt[1] = CheckBingoCnt(iArray_2p);

		// Display result
		cout << "-----------[1p 빙고판]-----------\t\t\t\t-----------[2p 빙고판]-----------" << endl;
		cout << "\t     " << iBingoCnt[0] << "빙고 \t\t\t\t\t\t\t\t" << iBingoCnt[1] << "빙고" << endl;
		Display(iArray_1p, iArray_2p);
		cout << endl;

		// check winner 
		if (iBingoCnt[0] >= 5 && iBingoCnt[1] >= 5) {	// 동시에 5점 이상 난경우
			if (iBingoCnt[0] > iBingoCnt[1]) {
				iWinner = 1;
			}
			else if (iBingoCnt[0] == iBingoCnt[1]) {
				iWinner = 0;
			}
			else if (iBingoCnt[0] < iBingoCnt[1]) {
				iWinner = 2;
			}
			isGameEnd = true;
		}
		else if (iBingoCnt[0] >= 5) {
			iWinner = 1;
			isGameEnd = true;
		}
		else if (iBingoCnt[1] >= 5) {
			iWinner = 2;
			isGameEnd = true;
		}

		//check game end
		if (isGameEnd) break;
	}

	cout << "~~ " << iWinner << "p 승리! 축하합니다! ~~" << endl;
}

void Swap(int* iData, int* iSrc) {
	int iTemp;
	iTemp = *iData;
	*iData = *iSrc;
	*iSrc = iTemp;
}

void Display(const int iArray_1p[], const int iArray_2p[]) {
	for (int i = 0; i < 5; i++) {
		int iIndex = i * 5;
		for (int j = 0; j < 5; j++) {
			if (iArray_1p[iIndex + j] == 0) cout << "*\t";
			else cout << iArray_1p[iIndex + j] << "\t";
		}
		cout << "\t\t\t";
		for (int j = 0; j < 5; j++) {
			if (iArray_2p[iIndex + j] == 0) cout << "*\t";
			else cout << iArray_2p[iIndex + j] << "\t";
		}
		cout << endl;
	}
}

void InitializeArray(int* iArray) {
	for (int i = 0; i < 25; i++) {
		iArray[i] = i + 1;
	}
}

void MixArray(int* iArray) {
	for (int i = 0; i < 100; i++) {
		int iIndex = rand() % 24;
		Swap(&iArray[iIndex], &iArray[iIndex + 1]);
	}
}

void CheckNumber(int* iArray, int iSelectedNum) {
	for (int i = 0; i < 25; i++) {
		if (iArray[i] == iSelectedNum) {
			iArray[i] = 0;
		}
	}
}

int CheckBingoCnt(const int iArray[]) {
	int iBingoCnt(0);

	// check 세로 bingo
	for (int i = 0; i < 5; i++) {

		int iIndex = i;
		bool isBingoLine(true);

		for (int j = 0; j < 5; j++) {
			if (iArray[iIndex] != 0) {
				isBingoLine = false;
				break;
			}
			iIndex = iIndex + 5;
		}

		if (isBingoLine) iBingoCnt++;
	}

	//check 가로 bingo
	for (int i = 0; i < 5; i++) {

		int iIndex = i * 5;
		bool isBingoLine(true);

		for (int j = 0; j < 5; j++) {
			if (iArray[iIndex] != 0) {
				isBingoLine = false;
				break;
			}
			iIndex = iIndex + 1;
		}

		if (isBingoLine) iBingoCnt++;
	}


	//check 대각선 bingo
	bool isBingoLine(true);

	for (int i = 0; i < 5; i++) {
		int iIndex = i * 6;
		if (iArray[iIndex] != 0) {
			isBingoLine = false;
			break;
		}
	}
	if (isBingoLine) iBingoCnt++;
	isBingoLine = true;
	for (int i = 1; i <= 5; i++) {
		int iIndex = i * 4;
		if (iArray[iIndex] != 0) {
			isBingoLine = false;
			break;
		}
	}
	if (isBingoLine) iBingoCnt++;


	return iBingoCnt;
}