#include "stdafx.h"
#include "Stack_withQueue.h"

using namespace std;
using namespace StackWithQueue;

STACK Stack::CreateStack() {
	STACK stack;
	stack.queue = Queue::CreateQueue();
	stack.last = stack.queue.last;
	return stack;
}

void Stack::Push(PSTACK stack, int iData) {
	Queue::Inqueue(&(stack->queue), iData);
	stack->last = stack->queue.last;
}

void Stack::Pop(PSTACK stack) {
	int iData(0);
	
	//rearrange
	while (1) {
		// if rearrange is done
		if (stack->queue.head == stack->last) {
			break;
		}

		// dequeue
		iData = Queue::Dequeue_re(&(stack->queue));

		// inqueue
		Queue::Inqueue(&(stack->queue), iData);
	}
	//update last node of stack
	stack->last = stack->queue.last;

	// pop
	Queue::Dequeue(&(stack->queue));
}

bool Stack::IsEmpty(const STACK* stack) {
	if (stack->last == nullptr) return true;
	else return false;
}

void Stack::ShowStack(const STACK* stack) {
	Queue::ShowQueue(&(stack->queue));
}