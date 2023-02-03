#include "stdafx.h"
#include "Stack_withArray.h"

using namespace std;
using namespace StackArray;


STACK Stack::CreateStack(int iSize) {
	STACK stack{nullptr, iSize, -1};
	stack.iArr = new int[iSize] {0};
	return stack;
}

void Stack::Push(PSTACK stack, int iData) {
	if (stack->last == stack->size-1) {
		cout << "Stack is full!" << endl;
		return;
	}
	stack->last++;
	stack->iArr[stack->last] = iData;
}

void Stack::Pop(PSTACK stack) {
	if (stack->last == -1) {
		cout << " <End>." << endl;
		return;
	}
	stack->last--;
}
int Stack::Pop_re(PSTACK stack) {
	int iData(0);
	
	if (stack->last == -1) {
		cout << " <End>." << endl;
		return -1;
	}

	iData = stack->iArr[stack->last];
	stack->last--;
	return iData;
}

bool Stack::IsFull(const STACK* stack) {
	if (stack->last == stack->size - 1) {
		cout << "Stack is full!" << endl;
		return true;
	}
	else return false;
}
int Stack::Peek(const STACK* stack) {
	return stack->iArr[stack->last];
}

void Stack::ShowStack(const STACK* stack) {
	for (int i = 0; i <= stack->last; i++) {
		cout << stack->iArr[i] << ", ";
	}
}