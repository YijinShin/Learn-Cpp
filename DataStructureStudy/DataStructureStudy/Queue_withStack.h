/* stack 2개로 만든 Queue, 
stack은 linked list로 구현함. */

#pragma once
#include "stdafx.h"
#include "Stack_withSingleLinkedList.h"
#define MAXSIZE 5

using namespace std;
using namespace StackSLList;

namespace QueueWithStack {

	typedef struct tagQueue {
		STACK pushStack;
		STACK popStack;
	}QUEUE, *PQUEUE;

	class Queue {
	public:
		static QUEUE CreateQueue();

		static void Inqueue(PQUEUE queue, const int* iArr, int iSize);	// 사용자가 원하는 만큼 int 를 입력가능 /* "1 2 3 4 6 7" 이렇게 입력시 알아서 사이즈 6개 책정함*/
		static void Dequeue(PQUEUE queue);	// inqueue했던 int idata들을 dequeue한 순서대로 array에 넣어 반환함. 
		static void ShowQueue(const QUEUE* queue);
	};

}