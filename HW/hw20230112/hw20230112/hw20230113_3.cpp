#include <iostream>

using namespace std;

int main() {

	int iRandNum(0);
	int iWinCnt(0), iLoseCnt(0);
	bool isOdd(false);
	bool isGameEnd(false);
	int iChooseMenu(0);

srand(unsigned(time(nullptr))); // 이거 넣어주는게 수업 풀이 

	while (1) {

		// clear console
		system("cls");

		for (int i = 1; i < 4; i++) {

			// make new random num (0~10)
			iRandNum = rand() % (10) + 1;
			isOdd = iRandNum % 2;


			// choose menu
			cout << "["<<i<<"ROUND]   ������ �����Ǿ����ϴ�!" << endl;
			cout << "Ȧ�ϱ�� ¦�ϱ��?  (1.Ȧ 2.¦ 3.����) : ";

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
							cout << "YOU WIN! ������ " << iRandNum << "�����ϴ�!" << endl;
						}
						else {
							iLoseCnt++;
							cout << "YOU LOSE ������ " << iRandNum << "�����ϴ�!" << endl;
						}
						break;

						// player choose even
					case 2:
						if (isOdd) {
							iLoseCnt++;
							cout << "YOU LOSE ������ " << iRandNum << "�����ϴ�!" << endl;
						}
						else {
							iWinCnt++;
							cout << "YOU WIN! ������ " << iRandNum << "�����ϴ�!" << endl;
						}
						break;

						// player end game
					case 3:
						isGameEnd = true;
						cout << "������ �����մϴ�." << endl;
						break;

						// unexpected input
					default:
						isWrongInput = true;
						cout << "�߸��� �Է��Դϴ�. ���� �޴� �� �������ּ��� (1.Ȧ 2.¦ 3.����): " << endl;
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
		cout << "������ ����Ǿ����ϴ�. (��:" << iWinCnt << ", ��:" << iLoseCnt << ")" << endl;
		if (isGameEnd) break;

		//clear LoseCnt, WinCnt
		iLoseCnt = 0;
		iWinCnt = 0;

		//pause console
		system("pause");
	}
}