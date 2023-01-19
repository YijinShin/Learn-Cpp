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
			BuyItem(&iCurrMoney, 100, "�ݶ�");
			break;
		case 2:
			BuyItem(&iCurrMoney, 200, "���̴�");
			break;
		case 3:
			BuyItem(&iCurrMoney, 300, "ȯŸ");
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

void GetCurrMoney(int* iCurrMoney) {
	cout << "�ܾ��� �Է����ּ���. : ";
	cin >> *iCurrMoney;
	cin.ignore();
	cout << endl;
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

void BuyItem(int* iCurrMoney, int price, string menuName) {
	if (*iCurrMoney < price) {
		cout << "�ܾ��� �����մϴ�.		(�ܾ�: " << *iCurrMoney << "��)" << endl;
	}
	else {
		CalcBalance(iCurrMoney, price);
		cout << menuName << " ���� �Ϸ�.		(�ܾ�: " << *iCurrMoney << "��)" << endl;
	}
}

void CalcBalance(int* currMoney, int price) {
	int curr = *currMoney;
	*currMoney = curr - price;
}