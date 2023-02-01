#pragma once
#include <iostream>

using namespace std;

namespace StackSLLinst {

	typedef struct tagNode {
		int iData;
		tagNode* prevNode;
	}NODE, * PNODE;

	typedef struct tagStack {
		PNODE last;
	}STACK, * PSTACK;

	class Stack {
	public:
		static STACK CreateStack();
		static void Pop(PSTACK stack);
		static void Push(PSTACK stack, int iData);
		static void ShowStack(const STACK* stack);
	};

	STACK Stack::CreateStack() {
		STACK stack{nullptr};
		return stack;
	}

	void Stack::Pop(PSTACK stack) {
		
		PNODE lastNode = stack->last;
		if (lastNode == nullptr) {
			cout << "Notting in this stack" << endl;
			return;
		}
		stack->last = lastNode->prevNode;

		delete lastNode;
		lastNode = nullptr;
	}

	void Stack::Push(PSTACK stack, int iData) {
		PNODE newNode = new NODE{ iData, nullptr };

		// if this is not a first node
		if (stack->last != nullptr) {
			newNode->prevNode = stack->last;
		}
		stack->last = newNode;
	}

	void Stack::ShowStack(const STACK* stack) {
		PNODE currNode = stack->last;

		while (1) {
			if (currNode == nullptr) {
				cout << "  End.  " << endl;
				break;
			}
			cout << currNode->iData << ", ";
			currNode = currNode->prevNode;
		}
	}
}