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
	NODE* Delete(NODE& stRoot, NODE& iTargetKey);

	NODE* min_key_Node(NODE* stRoot) const;
	NODE* max_key_Node(NODE* stRoot) const;

	bool BinarySearch(NODE& stRoot, NODE& iTargetNode) const;
	void Pre_order()const;
	void In_order()const;
	void Post_order()const;
	
	void Rander() const;

	NODE& GetRootNode()const ;
};

