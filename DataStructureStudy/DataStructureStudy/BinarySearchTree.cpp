#include "stdafx.h";
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : m_stpBinaryTree(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
	Release();
}

void BinarySearchTree::Initialize()
{
	m_stpBinaryTree = new BT;
}

void BinarySearchTree::Release()
{
}

bool BinarySearchTree::Insert(NODE& stRoot, NODE& stNewNode)
{	
	// TargetKey < CurrNode->key : 왼쪽 자식을 CurrNode로 하고 재귀 호출
	if (stNewNode.iKey < stRoot.iKey) {
		if (stRoot.stLeft == nullptr) {
			stRoot.stLeft = &stNewNode;
			return true;
		}
		else Insert(*stRoot.stLeft, stNewNode);
	}
	// TargetKey > CurrNode->key : 오른쪽 자식을 CurrNode로 하고 재귀 호출 
	else if (stNewNode.iKey > stRoot.iKey) {
		if (stRoot.stRight == nullptr) {
			stRoot.stRight = &stNewNode;
			return true;
		}
		else Insert(*stRoot.stLeft, stNewNode);
	}
	// TargetKey == CurrNode->key: 성공 
	else {
		cout << "[Binary Search] 원소가 이미 존재합니다." << endl;
		return false;
	}
}

NODE& BinarySearchTree::GetRootNode()const
{
	return *m_stpBinaryTree->root;
}
