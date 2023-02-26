#pragma once
#include "Define_BinarySearchTree.h"

class BinarySearchTree
{
private:
	BT* m_stpBinaryTree;
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Initialize();
	void Release();

	bool Insert(NODE& root, NODE& iTargetKey);

	void Pre_order()const;
	void In_order()const;
	void Post_order()const;

	NODE& GetRootNode()const ;
};

