#pragma once

#include "stdafx.h"

using namespace std;

namespace QueueSLList {


	typedef struct tagNode {
		int iData;
		tagNode* nextNode;
	}NODE, *PNODE;

	typedef struct tagQueue {
		PNODE head;
		PNODE last;
	}QUEUE, *PQUEUE;

	class Queue {
	public:
		static QUEUE CreateQueue();
		static void Inqueue(PQUEUE queue, int iData);
		static void Dequeue(PQUEUE queue);
		static int Dequeue_re(PQUEUE queue);
		static void ShowQueue(const QUEUE* queue);
	};

	
}