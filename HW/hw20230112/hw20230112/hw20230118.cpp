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
				iCurrMoney = BuyItem(iCurrMoney, 100, "�ݶ�");
				break;
			case 2:
				iCurrMoney = BuyItem(iCurrMoney, 200, "���̴�");
				break;
			case 3:
				iCurrMoney = BuyItem(iCurrMoney, 300, "ȯŸ");
				break;
			case 4:
				isEnd = true;
				cout << "�Ž��� ���� " << iCurrMoney << "�� �Դϴ�." << endl;
				cout << "���Ǳ⸦ �����մϴ�. " << endl;
				break;

			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
		}

		if (isEnd) break;

		// pause console
		//system("pause");

	}

}

int GetCurrMoney() {
	int iCurrMoney(0);
	cout << "�ܾ��� �Է����ּ���. : ";
	cin >> iCurrMoney;
	cin.ignore();
	cout << endl;

	return iCurrMoney;
}

int GetMenu() {
	int iChooseMenu(0);
	cout << "---------------------<�������.>-----------------------------" << endl;
	cout << " �޴��� �������ּ���. (1. �ݶ�:100��  2.���̴�:200��  3.ȯŸ:300��  4.����): ";
	cin >> iChooseMenu;
	cin.ignore();
	cout << endl;

	return iChooseMenu;
}

int BuyItem(int iCurrMoney, int price, string menuName) {
	int balance = CalcBalance(iCurrMoney, price);

	if (balance < 0) {
		cout << "�ܾ��� �����մϴ�.		(�ܾ�: " << iCurrMoney << "��)" << endl;
		return iCurrMoney;
	}
	else {
		cout << menuName<<" ���� �Ϸ�.		(�ܾ�: " << balance << "��)" << endl;
		return balance;
	}
}

int CalcBalance(int currMoney, int price) {
	return currMoney - price;
}