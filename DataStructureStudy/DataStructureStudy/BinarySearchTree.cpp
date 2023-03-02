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

NODE* BinarySearchTree::Delete(NODE& stRoot, NODE& iTargetKey)
{
	if (stRoot.iKey == iTargetKey.iKey) {
		// ã��
		// �ڳడ ���� ���
		if(stRoot.stRight == nullptr) return stRoot.stLeft;
		else if(stRoot.stLeft == nullptr) return stRoot.stRight;
		else {
			NODE* temp_min = min_key_Node(&stRoot);	// ���� ����� ����� ���� ������ subtree���� ���� ���� �ڳ� ã�� 
			NODE* temp_max = max_key_Node(&stRoot); // ���� ����� ��� ��� ���� ���� stubtree���� ���� ū �ڳ� ã�� 
			// temp_min�� itarget�� �� ������ ��� 
			if (abs(temp_min->iKey - iTargetKey.iKey) < abs(temp_max->iKey - iTargetKey.iKey)) {
				stRoot.iKey = temp_min->iKey;			// ���� ����� ����� Ű�� temp��� key�����ϱ�
				Delete(stRoot, *temp_min);				// temp��� �����ϱ� 
			}
			// temp_max�� itarget�� �� ������ ��� 
			else {
				stRoot.iKey = temp_max->iKey;			// ���� ����� ����� Ű�� temp��� key�����ϱ�
				Delete(stRoot, *temp_max);				// temp��� �����ϱ� 
			}
			
		}
	}
	else if (stRoot.stRight==nullptr&& stRoot.stLeft ==nullptr ) {
		return nullptr;
	}
	else if (iTargetKey.iKey < stRoot.iKey) {
		stRoot.stLeft = Delete(*stRoot.stRight, iTargetKey);
		
	}
	else if (iTargetKey.iKey > stRoot.iKey) {
		stRoot.stLeft = Delete(*stRoot.stLeft, iTargetKey);
	}
	return &stRoot;

}

NODE* BinarySearchTree::min_key_Node(NODE* stRoot) const {	
	NODE* stReturnNode;
	if (stRoot->stLeft == nullptr) stReturnNode = stRoot;
	else stReturnNode = min_key_Node(stRoot->stLeft);
	return stReturnNode;
}

void BinarySearchTree::Pre_order() const
{

}

bool BinarySearchTree::BinarySearch(NODE& stRoot, NODE& iTargetNode) const
{
	bool isFound(false);
	if (stRoot.iKey < iTargetNode.iKey) isFound = BinarySearch(*stRoot.stRight, iTargetNode);
	else if (stRoot.iKey > iTargetNode.iKey) isFound = BinarySearch(*stRoot.stLeft, iTargetNode);
	else {
		cout << "[BinarySearch] ã�ҽ��ϴ�.";
		isFound = true;
	}
	return isFound;
}

NODE* BinarySearchTree::max_key_Node(NODE* stRoot) const {
	NODE* stReturnNode;
	if (stRoot->stRight == nullptr) stReturnNode = stRoot;
	else stReturnNode = max_key_Node(stRoot->stRight);
	return stReturnNode;
}

NODE& BinarySearchTree::GetRootNode()const
{
	return *m_stpBinaryTree->root;
}

void BinarySearchTree::Rander() const
{
	Rander();
}
