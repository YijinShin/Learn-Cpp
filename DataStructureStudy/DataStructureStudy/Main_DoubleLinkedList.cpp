#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;
using namespace DLList;

enum Menu { INSERT = 1, DELETE, SHOW, CLEAN, QUIT };

int main() {

	int iSeletedMenu(0);
	int iValue(0);
	bool isEnd(false);
	LIST list = DoubleLinkedList::CreateList();
	
	cout << " [Double linked list is created]" << endl << endl;

	while (1) {

		// show menu
		cout << endl << " Choose menu (1.insert, 2.delete, 3.show list, 4.clean, 5.quit) : ";
		cin >> iSeletedMenu;

		switch (iSeletedMenu)
		{
		case INSERT:
			cout << "Enter a value to insert :";
			cin >> iValue;
			DoubleLinkedList::Insert(&list, iValue);
			break;
		case DELETE:
			cout << "Enter a value to delete :";
			cin >> iValue;
			DoubleLinkedList::Delete(&list, iValue);
			break;
		case SHOW:
			cout << "[ Display your list ]" << endl;
			DoubleLinkedList::ShowList(&list);
			break;
		case CLEAN:
			system("cls");
			break;
		case QUIT:
			isEnd = true;
			break;

		default:
			cout << "Wrong input" << endl;
			break;
		}

		if (isEnd) break;
	}

}