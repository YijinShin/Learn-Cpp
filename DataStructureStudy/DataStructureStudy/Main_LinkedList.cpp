#include <iostream>
#include "SingleLinkedList.h"

using namespace std;
using namespace SLList;

enum Menu { INSERT = 1, DELETE, SHOW, QUIT };

int main() {

	int iSeletedMenu(0);
	int iValue(0);
	bool isEnd(false);
	LIST list = SingleLinkedList::CreateList();	// create list

	cout << " [Single linked list is created]" << endl<<endl;

	while (1) {

		// show menu
		cout << endl << " Choose menu (1.insert, 2.delete, 3.show list, 4.quit) : ";
		cin >> iSeletedMenu;

		switch (iSeletedMenu)
		{
		case INSERT:
			cout << "Enter a value to insert :";
			cin >> iValue;
			SingleLinkedList::Insert(&list, iValue);
			break;
		case DELETE:
			cout << "Enter a value to delete :";
			cin >> iValue;
			SingleLinkedList::Delete(&list, iValue);
			break;
		case SHOW:
			cout << "[ Display your list ]" << endl;
			SingleLinkedList::ShowList(&list);
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