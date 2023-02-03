/* 이거 stack_withSingleLinkedList 써서 만든 스택 2개로 -> queue구현한것. */

#include "stdafx.h"
#include "Queue_withStack.h"

using namespace std;
using namespace QueueWithStack;

enum Menu { INQUEUE = 1, DEQUEUE, SHOW, CLEAN, QUIT };

int main() {

	int iSeletedMenu(0);
	int* iValue;
	int iSize(0);
	bool isEnd(false);

	QUEUE queue = Queue::CreateQueue();

	cout << " [Queue is created]" << endl << endl;

	while (1) {

		// show menu
		cout << endl << " Choose menu (1.Inqueue, 2.Dequeue, 3.Show queue, 4.Clean, 5.Quit) : ";
		cin >> iSeletedMenu;

		switch (iSeletedMenu)
		{
		case INQUEUE:
			cout << "Enter size of data to insert: ";
			cin >> iSize;
			iValue = new int[iSize] {0};
			cout << "Enter a value to insert :";
			for(int i=0;i<iSize;i++) cin >> iValue[i];
			Queue::Inqueue(&queue, iValue, iSize);
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