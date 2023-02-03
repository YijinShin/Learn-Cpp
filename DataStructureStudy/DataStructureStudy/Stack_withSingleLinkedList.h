#pragma once
#include "stdafx.h"
#include "Stack_withSingleLinkedList.h"
using namespace std;

namespace StackSLList {
	typedef struct tagNode {
		int iData;
		tagNode* prevNode;
	}NODE, *PNODE;

	typedef struct tagStack {
		NODE* last;
	}STACK, *PSTACK;

	class Stack {
	public:
		static STACK CreateStack();
		static void Pop(PSTACK stack);
		static int Pop_re(PSTACK stack);
		static void Push(PSTACK stack, int iData);
		static void ShowStack(const STACK* stack);
		static bool IsEmpty(const STACK* stack);
	};
}