#include "stdafx.h"
#include "Queue_withSingleLinkedList.h"

using namespace std;
using namespace QueueSLList;


QUEUE Queue::CreateQueue() {
	QUEUE queue{ nullptr, nullptr };
	return queue;
}

void Queue::Inqueue(PQUEUE queue, int iData) {
	PNODE newNode = new NODE{ iData, nullptr };

	// if this is the first node
	if (queue->head == nullptr) {
		queue->head = newNode;
	}
	// if is not
	else {
		queue->last->nextNode = newNode;
	}
	queue->last = newNode;

}

void Queue::Dequeue(PQUEUE queue) {
	PNODE headNode = queue->head;

	if (headNode == nullptr) {
		cout << "Notting in this queue." << endl;
		return;
	}

	queue->head = headNode->nextNode;

	delete headNode;
	headNode = nullptr;
}

int Queue::Dequeue_re(PQUEUE queue) {
	int iData(0);
	PNODE headNode = queue->head;
	iData = headNode->iData;
	if (headNode == nullptr) {
		cout << "Notting in this queue." << endl;
		return -1;
	}

	queue->head = headNode->nextNode;

	delete headNode;
	headNode = nullptr;

	return iData;
}

void  Queue::ShowQueue(const QUEUE* queue) {
	const NODE* currNode = queue->head;

	while (1) {
		if (currNode == nullptr) {
			cout << " <END>." << endl;
			break;
		}
		cout << currNode->iData << ", ";
		currNode = currNode->nextNode;
	}
}