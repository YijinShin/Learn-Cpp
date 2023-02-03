#include "stdafx.h"
#include "Stack_withSingleLinkedList.h"

using namespace StackSLList;

STACK Stack::CreateStack() {
	STACK stack{ nullptr };
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

// 이건 pop한 data를 반환하는 함수. (stack으로 queue만들기 에서 사용하는 함수임) 
int Stack::Pop_re(PSTACK stack) {
	int popData;
	PNODE lastNode = stack->last;
	popData = lastNode->iData;
	if (lastNode == nullptr) {
		cout << "Notting in this stack" << endl;
		return NULL;
	}
	stack->last = lastNode->prevNode;

	delete lastNode;
	lastNode = nullptr;

	return popData;
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

// 이건 stack이 비었는지 아닌지 반환하는 함수. (stack으로 queue만들기 에서 사용하는 함수임) 
bool Stack::IsEmpty(const STACK* stack) {
	if (stack->last == nullptr) return true;
	else return false;
}