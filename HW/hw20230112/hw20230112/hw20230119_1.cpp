#include <iostream>

using namespace std;

int GetMenu();
void GetCurrMoney(int* iCurrMoney);
void BuyItem(int* iCurrMoney, int price, string menuName);
void CalcBalance(int* currMoney, int price);

int main() {

	int iCurrMoney(0);	// user curr money
	int iChooseMenu(0);	// menu user choose

	bool isEnd(false);

	// get input curr money
	GetCurrMoney(&iCurrMoney);

	while (1) {

		//system("cls");

		// get input menu
		iChooseMenu = GetMenu();

		// calc currMoney	
		switch (iChooseMenu) {
		case 1:
			BuyItem(&iCurrMoney, 100, "콜라");
			break;
		case 2:
			BuyItem(&iCurrMoney, 200, "사이다");
			break;
		case 3:
			BuyItem(&iCurrMoney, 300, "환타");
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

void GetCurrMoney(int* iCurrMoney) {
	cout << "잔액을 입력해주세요. : ";
	cin >> *iCurrMoney;
	cin.ignore();
	cout << endl;
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

void BuyItem(int* iCurrMoney, int price, string menuName) {
	if (*iCurrMoney < price) {
		cout << "잔액이 부족합니다.		(잔액: " << *iCurrMoney << "원)" << endl;
	}
	else {
		CalcBalance(iCurrMoney, price);
		cout << menuName << " 구매 완료.		(잔액: " << *iCurrMoney << "원)" << endl;
	}
}

void CalcBalance(int* currMoney, int price) {
	int curr = *currMoney;
	*currMoney = curr - price;
}