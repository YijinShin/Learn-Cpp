#include <iostream>

using namespace std;

int main() {

	int iCurrMoney(0);	// user curr money
	int iChooseMenu(0);	// menu user choose

	bool isEnd(false);
	
	// get input curr money
	cout << "�ܾ��� �Է����ּ���. : ";
	cin >> iCurrMoney;
	cin.ignore();
	cout << endl;

	while (1) {

		// clear console
		//system("cls");


		// get input menu
		cout << "---------------------<�������.>-----------------------------" << endl;
		cout << " �޴��� �������ּ���. (1. �ݶ�:100��  2.���̴�:200��  3.ȯŸ:300��  4.����): ";
		cin >> iChooseMenu;
		cin.ignore();
		cout << endl;

		// calc currMoney	
		switch (iChooseMenu) {
			case 1:
				if (iCurrMoney < 100) {
					cout << "�ܾ��� �����մϴ�.		(�ܾ�: " << iCurrMoney << "��)" << endl;
				}
				else {
					iCurrMoney = iCurrMoney - 100;
					cout << " �ݶ� ���� �Ϸ�.		(�ܾ�: " << iCurrMoney << "��)" << endl;
				}
				break;

			case 2:
				if (iCurrMoney < 200) {
					cout << "�ܾ��� �����մϴ�.		(�ܾ�: " << iCurrMoney << "��)" << endl;
				}
				else {
					iCurrMoney = iCurrMoney - 200;
					cout << " ���̴� ���� �Ϸ�.		(�ܾ�: " << iCurrMoney << "��)" << endl;
				}
				break;

			case 3:
				if (iCurrMoney < 300) {
					cout << "�ܾ��� �����մϴ�.		(�ܾ�: " << iCurrMoney << "��)" << endl;
				}
				else {
					iCurrMoney = iCurrMoney - 300;
					cout << " ȯŸ ���� �Ϸ�.		(�ܾ�: " << iCurrMoney << "��)" << endl;
				}
				break;

			case 4:
				isEnd = true;
				cout << "�Ž��� ���� " << iCurrMoney <<	"�� �Դϴ�." << endl;
				cout << "���Ǳ⸦ �����մϴ�. " << endl;
				break;

			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
		}

		if (isEnd) break;

		// pause console
		system("pause");

	}

}