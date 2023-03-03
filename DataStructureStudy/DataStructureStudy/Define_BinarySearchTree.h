#pragma once

typedef struct stNode {
	stNode* stLeft;
	stNode* stRight;
	int iKey;

	stNode():stLeft(nullptr), stRight(nullptr), iKey(0) {}
}NODE;

typedef struct stBinaryTree {
	NODE* root;
	int iNodeCnt;

	stBinaryTree() :root(nullptr), iNodeCnt(0) {};
}BT;

template<typename T>
void Safe_Delete(T& Temp) {
	delete Temp;
	Temp = nullptr;
}

