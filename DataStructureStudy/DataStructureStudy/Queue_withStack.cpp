//#include <iostream>			// 심지어 밑에꺼 안쓰고 iostream만 써도 오류남. 
#include "stdafx.h"			//이걸 여기에도 선언해야지 빌드 오류가 안남. 
#include "Queue_withStack.h"	// 얘가 이미 #include "stdafx.h"를 하고있어서 괜찮을거라고 생각했는데 

using namespace std;
using namespace QueueWithStack;

QUEUE Queue::CreateQueue() {
	QUEUE queue;
	queue.pushStack = Stack::CreateStack();
	queue.popStack = Stack::CreateStack();
	return queue;
}

void Queue::Inqueue(PQUEUE queue, const int* iArr, int iSize) {

	//push into pushStack
	for (int i = 0; i < iSize; i++) {
		Stack::Push(&(queue->pushStack), iArr[i]);
	}

	// pop from pushStack -> push to popStack
	int iData(0);
	for (int i = 0; i < iSize; i++) {
		iData = Stack::Pop_re(&(queue->pushStack));
		Stack::Push(&(queue->popStack), iData);
	}
}
void Queue::Dequeue(PQUEUE queue) {
	int iData;
	if (Stack::IsEmpty(&(queue->popStack))) {
		cout << "Notting in the queue" << endl;
		return;
	}

	//pop from popStack
	while (1) {
		if (Stack::IsEmpty(&(queue->popStack))) {
			cout << " <End>." << endl;
			break;
		}
		iData = Stack::Pop_re(&(queue->popStack));
		cout << iData << ", ";
	}
}

void Queue::ShowQueue(const QUEUE* queue) {
	Stack::ShowStack(&(queue->popStack));
}