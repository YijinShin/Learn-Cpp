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
	// TargetKey < CurrNode->key : ���� �ڽ��� CurrNode�� �ϰ� ��� ȣ��
	if (stNewNode.iKey < stRoot.iKey) {
		if (stRoot.stLeft == nullptr) {
			stRoot.stLeft = &stNewNode;
			return true;
		}
		else Insert(*stRoot.stLeft, stNewNode);
	}
	// TargetKey > CurrNode->key : ������ �ڽ��� CurrNode�� �ϰ� ��� ȣ�� 
	else if (stNewNode.iKey > stRoot.iKey) {
		if (stRoot.stRight == nullptr) {
			stRoot.stRight = &stNewNode;
			return true;
		}
		else Insert(*stRoot.stLeft, stNewNode);
	}
	// TargetKey == CurrNode->key: ���� 
	else {
		cout << "[Binary Search] ���Ұ� �̹� �����մϴ�." << endl;
		return false;
	}
}

NODE& BinarySearchTree::GetRootNode()const
{
	return *m_stpBinaryTree->root;
}
