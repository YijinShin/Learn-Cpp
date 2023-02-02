#include <iostream>
#include "Queue_withSingleLinkedList.h"

using namespace std;
using namespace QueueSLList;

enum Menu { INQUEUE = 1, DEQUEUE, SHOW, CLEAN, QUIT };

int main() {

	int iSeletedMenu(0);
	int iValue(0);
	bool isEnd(false);

	QUEUE queue = Queue::CreateQueue();

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
			Queue::Inqueue(&queue, iValue);
			break;
		case DEQUEUE:
			cout << "Dequeue last input value" << endl;
			Queue::Dequeue(&queue);
			break;
		case SHOW:
			cout << "[ Display your list ]" << endl;
			Queue::ShowQueue(&queue);
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