#include "stdafx.h"
#include "Stack_withArray.h"

using namespace std;
using namespace StackArray;

enum Menu { PUSH = 1, POP, SHOW, CLEAN, QUIT };

int main() {

	int iSeletedMenu(0);
	int iValue(0);
	int iSize(0);
	bool isEnd(false);

	cout << "Enter the size of stack: ";
	cin >> iSize;
	STACK stack = Stack::CreateStack(iSize);

	cout << " [Stack is created]" << endl << endl;

	while (1) {

		// show menu
		cout << endl << " Choose menu (1.Push, 2.Pop, 3.show stack, 4.clean, 5.quit) : ";
		cin >> iSeletedMenu;

		switch (iSeletedMenu)
		{
		case PUSH:
			cout << "Enter a value to insert :";
			cin >> iValue;
			Stack::Push(&stack, iValue);
			break;
		case POP:
			cout << "Pop last input value" << endl;
			Stack::Pop(&stack);
			break;
		case SHOW:
			cout << "[ Display your list ]" << endl;
			Stack::ShowStack(&stack);
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