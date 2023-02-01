#pragma once

#include <iostream>

using namespace std;

namespace QueueSLList {


	typedef struct tagNode {
		int iData;
		tagNode* nextNode;
	}NODE, * PNODE;

	typedef struct tagQueue {
		PNODE head;
		PNODE last;
	}QUEUE, * PQUEUE;

	class Queue {
	public:
		static QUEUE CreateQueue();
		static void Inqueue(PQUEUE queue, int iData);
		static void Dequeue(PQUEUE queue);
		static void ShowQueue(PQUEUE queue);
	};

	QUEUE QueueSLList::Queue::CreateQueue() {
		QUEUE queue{ nullptr, nullptr };
		return queue;
	}

	void QueueSLList::Queue::Inqueue(PQUEUE queue, int iData) {
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

	void QueueSLList::Queue::Dequeue(PQUEUE queue) {
		PNODE headNode = queue->head;

		if (headNode == nullptr) {
			cout << "Notting in this queue." << endl;
			return;
		}

		queue->head = headNode->nextNode;

		delete headNode;
		headNode = nullptr;
	}

	void  QueueSLList::Queue::ShowQueue(PQUEUE queue) {
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
}