/* 이거 stack을 array로 구현한건 맞는데 중간에 동적할당을 하지는 않아서 그냥 처음부터 입력받는 size로 stack 크기 fix하고 시작함. */

#pragma once
#include "stdafx.h"

namespace StackArray {
	typedef struct tagStack {
		int* iArr;
		int size;
		int last;	// last in의 index
	}STACK, *PSTACK;

	class Stack {
	public:
		static STACK CreateStack(int iSize);

		static void Push(PSTACK stack, int iData);
		static void Pop(PSTACK stack);
		static int Pop_re(PSTACK stack);		// pop한 값을 반환
		static bool IsFull(const STACK* stack);	// stack이 full인지 반환
		static int Peek(const STACK* stack);	// top element를 반환
		static void ShowStack(const STACK* stack);
	};


}