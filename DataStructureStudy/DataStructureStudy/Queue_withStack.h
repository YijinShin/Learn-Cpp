/* stack 2���� ���� Queue, 
stack�� linked list�� ������. */

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

		static void Inqueue(PQUEUE queue, const int* iArr, int iSize);	// ����ڰ� ���ϴ� ��ŭ int �� �Է°��� /* "1 2 3 4 6 7" �̷��� �Է½� �˾Ƽ� ������ 6�� å����*/
		static void Dequeue(PQUEUE queue);	// inqueue�ߴ� int idata���� dequeue�� ������� array�� �־� ��ȯ��. 
		static void ShowQueue(const QUEUE* queue);
	};

}