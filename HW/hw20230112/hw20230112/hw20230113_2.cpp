#include <iostream>

using namespace std;

int main() {

	int iCurrMoney(0);	// user curr money
	int iChooseMenu(0);	// menu user choose

	bool isEnd(false);
	
	// get input curr money
	cout << "잔액을 입력해주세요. : ";
	cin >> iCurrMoney;
	cin.ignore();
	cout << endl;

	while (1) {

		// clear console
		//system("cls");


		// get input menu
		cout << "---------------------<어서오세요.>-----------------------------" << endl;
		cout << " 메뉴를 선택해주세요. (1. 콜라:100원  2.사이다:200원  3.환타:300원  4.종료): ";
		cin >> iChooseMenu;
		cin.ignore();
		cout << endl;

		// calc currMoney	
		switch (iChooseMenu) {
			case 1:
				if (iCurrMoney < 100) {
					cout << "잔액이 부족합니다.		(잔액: " << iCurrMoney << "원)" << endl;
				}
				else {
					iCurrMoney = iCurrMoney - 100;
					cout << " 콜라 구매 완료.		(잔액: " << iCurrMoney << "원)" << endl;
				}
				break;

			case 2:
				if (iCurrMoney < 200) {
					cout << "잔액이 부족합니다.		(잔액: " << iCurrMoney << "원)" << endl;
				}
				else {
					iCurrMoney = iCurrMoney - 200;
					cout << " 사이다 구매 완료.		(잔액: " << iCurrMoney << "원)" << endl;
				}
				break;

			case 3:
				if (iCurrMoney < 300) {
					cout << "잔액이 부족합니다.		(잔액: " << iCurrMoney << "원)" << endl;
				}
				else {
					iCurrMoney = iCurrMoney - 300;
					cout << " 환타 구매 완료.		(잔액: " << iCurrMoney << "원)" << endl;
				}
				break;

			case 4:
				isEnd = true;
				cout << "거스름 돈은 " << iCurrMoney <<	"원 입니다." << endl;
				cout << "자판기를 종료합니다. " << endl;
				break;

			default:
				cout << "잘못된 입력입니다." << endl;
				break;
		}

		if (isEnd) break;

		// pause console
		system("pause");

	}

}