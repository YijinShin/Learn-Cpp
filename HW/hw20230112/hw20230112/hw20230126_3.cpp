/* 1번과제의 심화*/
#include <iostream>

using namespace std;

void Swap(int* iData, int* iSrc);
void Display(const int iArray[]);
int CheckBingoCnt(const int iArray[]);

int main() {
	int iArray[25];
	int iInput(0);
	int iBingoCnt(0);
	bool isGameEnd(false);

	srand(unsigned(time(nullptr)));


	//init iArray
	for (int i = 0; i < 25; i++) {
		iArray[i] = i + 1;
	}

	/*
	// mix iArray
	for (int i = 0; i < 100; i++) {
		int iIndex = rand()%24;
		Swap(&iArray[iIndex], &iArray[iIndex+1]);
	}
	*/

	// Display
	cout << "-----------------[당신의 빙고판]-------------------" << endl;
	Display(iArray);

	// game start
	while (1) {

		// get input
		while (1) {
			cout << "[1~25 중 하나의 숫자를 입력하세요.] : ";
			cin >> iInput;
			if (iInput > 25 || iInput < 1) {
				cout << "(잘못된 입력입니다)";
			}
			else break;
		}

		// check bingo
		iArray[iInput - 1] = 0;

		// check bingo cnt
		iBingoCnt = CheckBingoCnt(iArray);
		Display(iArray);
		cout << "현재 빙고 개수: " << iBingoCnt << " 빙고!" << endl;

		// check is game end
		if (iBingoCnt >= 5) {
			isGameEnd = true;
			break;
		}
	}

	if (isGameEnd) {
		cout << " ~~ YOU WIN ~~" << endl;
	}

}

void Swap(int* iData, int* iSrc) {
	int iTemp;
	iTemp = *iData;
	*iData = *iSrc;
	*iSrc = iTemp;
}

void Display(const int iArray[]) {
	for (int i = 0; i < 25; i++) {
		if (iArray[i] == 0)cout << "*\t";
		else cout << iArray[i] << "\t";
		if (((i + 1) % 5) == 0) cout << endl;
	}
	cout << endl;
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
