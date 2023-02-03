//#include <iostream>			// ������ �ؿ��� �Ⱦ��� iostream�� �ᵵ ������. 
#include "stdafx.h"			//�̰� ���⿡�� �����ؾ��� ���� ������ �ȳ�. 
#include "Queue_withStack.h"	// �갡 �̹� #include "stdafx.h"�� �ϰ��־ �������Ŷ�� �����ߴµ� 

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