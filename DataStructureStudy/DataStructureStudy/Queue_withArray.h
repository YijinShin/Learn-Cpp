#pragma once

#include <iostream>
#define MAXSIZE 100

using namespace std;

namespace QueueArray {

	typedef struct tagQueue {
		int iArr[MAXSIZE];
		int iSize;
	}QUEUE, * PQUEUE;

	class Queue {
	public:
		static QUEUE CreateQueue();
		static void Inqueue(PQUEUE queue, int iData);
		static void Dequeue(PQUEUE queue);
		static void ShowQueue(const QUEUE* queue);
	};

	QUEUE QueueArray::Queue::CreateQueue() {
		QUEUE queue;
		queue.iSize = 0;
		return queue;
	}

	void QueueArray::Queue::Inqueue(PQUEUE queue, int iData) {
		queue->iSize++;
		queue->iArr[(queue->iSize - 1)] = iData;
	}

	void QueueArray::Queue::Dequeue(PQUEUE queue) {
		if (queue->iSize == 0) {
			cout << "Nottint in the queue" << endl;
			return;
		}

		// 한칸씩 앞으로 당겨오기 
		memmove(queue->iArr, &(queue->iArr[1]), (queue->iSize - 1) * sizeof(int));
		queue->iArr[(queue->iSize) - 1] = 0;
		queue->iSize = (queue->iSize) - 1;
	}

	void QueueArray::Queue::ShowQueue(const QUEUE* queue) {
		int currIndex(0);
		
		while (1) {
			if (currIndex == queue->iSize) {
				cout << " <END>." << endl;
				return;
			}

			cout << queue->iArr[currIndex] << ", ";
			currIndex++;
		}
	}


}
