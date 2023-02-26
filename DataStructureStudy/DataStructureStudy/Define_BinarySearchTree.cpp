#include "stdafx.h"

typedef struct stNode{
	PNODE stLeft;
	PNODE stRight;
	int iKey;	
}NODE, *PNODE;

typedef struct stBinaryTree {
	PNODE root;
	int iNodeCnt;
}BT, *PBT;

