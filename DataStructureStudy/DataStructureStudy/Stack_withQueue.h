#pragma once
#include "stdafx.h"
#include "Queue_withSingleLinkedList.h"

using namespace QueueSLList;

namespace StackWithQueue {
	typedef struct tagStack {
		QUEUE queue;
		PNODE last;
	}STACK, *PSTACK;

	class Stack {
	public:
		static STACK CreateStack();
		static void Push(PSTACK stack, int iData);
		static void Pop(PSTACK stack);
		static bool IsEmpty(const STACK* stack);
		static void ShowStack(const STACK* stack);
	};
}