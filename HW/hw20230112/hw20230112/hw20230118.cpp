#include <iostream>

using namespace std;

int GetMenu(); 
int GetCurrMoney();
int BuyItem(int iCurrMoney, int price, string menuName);
int CalcBalance(int currMoney, int price);

int main() {

	int iCurrMoney(0);	// user curr money
	int iChooseMenu(0);	// menu user choose

	bool isEnd(false);

	// get input curr money
	iCurrMoney = GetCurrMoney();

	while (1) {

		//system("cls");

		// get input menu
		iChooseMenu = GetMenu();

		// calc currMoney	
		switch (iChooseMenu) {
			case 1:
				iCurrMoney = BuyItem(iCurrMoney, 100, "콜라");
				break;
			case 2:
				iCurrMoney = BuyItem(iCurrMoney, 200, "사이다");
				break;
			case 3:
				iCurrMoney = BuyItem(iCurrMoney, 300, "환타");
				break;
			case 4:
				isEnd = true;
				cout << "거스름 돈은 " << iCurrMoney << "원 입니다." << endl;
				cout << "자판기를 종료합니다. " << endl;
				break;

			default:
				cout << "잘못된 입력입니다." << endl;
				break;
		}

		if (isEnd) break;

		// pause console
		//system("pause");

	}

}

int GetCurrMoney() {
	int iCurrMoney(0);
	cout << "잔액을 입력해주세요. : ";
	cin >> iCurrMoney;
	cin.ignore();
	cout << endl;

	return iCurrMoney;
}

int GetMenu() {
	int iChooseMenu(0);
	cout << "---------------------<어서오세요.>-----------------------------" << endl;
	cout << " 메뉴를 선택해주세요. (1. 콜라:100원  2.사이다:200원  3.환타:300원  4.종료): ";
	cin >> iChooseMenu;
	cin.ignore();
	cout << endl;

	return iChooseMenu;
}

int BuyItem(int iCurrMoney, int price, string menuName) {
	int balance = CalcBalance(iCurrMoney, price);

	if (balance < 0) {
		cout << "잔액이 부족합니다.		(잔액: " << iCurrMoney << "원)" << endl;
		return iCurrMoney;
	}
	else {
		cout << menuName<<" 구매 완료.		(잔액: " << balance << "원)" << endl;
		return balance;
	}
}

int CalcBalance(int currMoney, int price) {
	return currMoney - price;
}