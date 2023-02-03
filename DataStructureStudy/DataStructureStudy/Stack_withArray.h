/* �̰� stack�� array�� �����Ѱ� �´µ� �߰��� �����Ҵ��� ������ �ʾƼ� �׳� ó������ �Է¹޴� size�� stack ũ�� fix�ϰ� ������. */

#pragma once
#include "stdafx.h"

namespace StackArray {
	typedef struct tagStack {
		int* iArr;
		int size;
		int last;	// last in�� index
	}STACK, *PSTACK;

	class Stack {
	public:
		static STACK CreateStack(int iSize);

		static void Push(PSTACK stack, int iData);
		static void Pop(PSTACK stack);
		static int Pop_re(PSTACK stack);		// pop�� ���� ��ȯ
		static bool IsFull(const STACK* stack);	// stack�� full���� ��ȯ
		static int Peek(const STACK* stack);	// top element�� ��ȯ
		static void ShowStack(const STACK* stack);
	};


}