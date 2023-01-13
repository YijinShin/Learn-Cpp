#include <iostream>

using namespace std;

int main() {

	int iRandNum(0);
	int iWinCnt(0), iLoseCnt(0);
	bool isOdd(false);
	bool isGameEnd(false);
	int iChooseMenu(0);

	while (1) {

		// clear console
		system("cls");

		for (int i = 1; i < 4; i++) {

			// make new random num (0~10)
			iRandNum = rand() % (10) + 1;
			isOdd = iRandNum % 2;


			// choose menu
			cout << "["<<i<<"ROUND]   난수가 생성되었습니다!" << endl;
			cout << "홀일까요 짝일까요?  (1.홀 2.짝 3.종료) : ";

			while (1) {

				bool isWrongInput = false;

				// get input
				cin >> iChooseMenu;
				cin.ignore();

				// calc result
				switch (iChooseMenu) {
					// player choose odd
					case 1:
						if (isOdd) {
							iWinCnt++;
							cout << "YOU WIN! 난수는 " << iRandNum << "였습니다!" << endl;
						}
						else {
							iLoseCnt++;
							cout << "YOU LOSE 난수는 " << iRandNum << "였습니다!" << endl;
						}
						break;

						// player choose even
					case 2:
						if (isOdd) {
							iLoseCnt++;
							cout << "YOU LOSE 난수는 " << iRandNum << "였습니다!" << endl;
						}
						else {
							iWinCnt++;
							cout << "YOU WIN! 난수는 " << iRandNum << "였습니다!" << endl;
						}
						break;

						// player end game
					case 3:
						isGameEnd = true;
						cout << "게임을 종료합니다." << endl;
						break;

						// unexpected input
					default:
						isWrongInput = true;
						cout << "잘못된 입력입니다. 다음 메뉴 중 선택해주세요 (1.홀 2.짝 3.종료): " << endl;
						break;
				}

				if (!isWrongInput) break;
				if (isGameEnd) break;
			}
			cout << endl;
			if (isGameEnd) break;
		}
		cout << endl;

		// if Game end
		cout << "게임이 종료되었습니다. (승:" << iWinCnt << ", 패:" << iLoseCnt << ")" << endl;
		if (isGameEnd) break;

		//clear LoseCnt, WinCnt
		iLoseCnt = 0;
		iWinCnt = 0;

		//pause console
		system("pause");
	}
}