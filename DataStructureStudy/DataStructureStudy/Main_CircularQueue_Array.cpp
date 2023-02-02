#include <iostream>
#include "CirculatQueue_withArray.h"

using namespace std;
using namespace CQueueArray;

enum Menu { INQUEUE = 1, DEQUEUE, SHOW, CLEAN, QUIT };

int main() {

	int iSeletedMenu(0);
	int iValue(0);
	bool isEnd(false);

	CQUEUE queue = CircularQueue::CreateCircularQueue();

	cout << " [Stack is created]" << endl << endl;

	while (1) {

		// show menu
		cout << endl << " Choose menu (1.Inqueue, 2.Dequeue, 3.Show queue, 4.Clean, 5.Quit) : ";
		cin >> iSeletedMenu;

		switch (iSeletedMenu)
		{
		case INQUEUE:
			cout << "Enter a value to insert :";
			cin >> iValue;
			CircularQueue::Inqueue(&queue, iValue);
			break;
		case DEQUEUE:
			cout << "Dequeue last input value" << endl;
			CircularQueue::Dequeue(&queue);
			break;
		case SHOW:
			cout << "[ Display your list ]" << endl;
			CircularQueue::ShowCQueue(&queue);
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