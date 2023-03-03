#include "stdafx.h"
#include "RedBlackTree.h"
using namespace std;

enum MENU {INSERT = 1, DELETE, SEARCH, QUIT};

int main() {
	int iMenu(0);
	bool isEnd(false);

	RedBlackTree<int> RBT;

	while (1) {
		system("cls");

		cout << "1.Insert, 2.Delete, 3.Search, 4.Quit: " << endl;
		cin >> iMenu;

		switch (iMenu)
		{
		case INSERT:
			RBT.Menu_Insert();
			break;
		case DELETE:
			break;
		case SEARCH:
			break;
		case QUIT:
			break;
		default:
			break;
		}
	}

}
