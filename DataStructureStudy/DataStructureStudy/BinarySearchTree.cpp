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

NODE* BinarySearchTree::Delete(NODE& stRoot, NODE& iTargetKey)
{
	if (stRoot.iKey == iTargetKey.iKey) {
		// 찾음
		// 자녀가 없는 경우
		if(stRoot.stRight == nullptr) return stRoot.stLeft;
		else if(stRoot.stLeft == nullptr) return stRoot.stRight;
		else {
			NODE* temp_min = min_key_Node(&stRoot);	// 삭제 대상인 노드대신 들어올 오른쪽 subtree에서 가장 작은 자녀 찾기 
			NODE* temp_max = max_key_Node(&stRoot); // 삭제 대상인 노드 대신 들어올 왼쪽 stubtree에서 가장 큰 자녀 찾기 
			// temp_min이 itarget와 더 근접한 경우 
			if (abs(temp_min->iKey - iTargetKey.iKey) < abs(temp_max->iKey - iTargetKey.iKey)) {
				stRoot.iKey = temp_min->iKey;			// 삭제 대상인 노드의 키에 temp노드 key복사하기
				Delete(stRoot, *temp_min);				// temp노드 삭제하기 
			}
			// temp_max가 itarget과 더 근접한 경우 
			else {
				stRoot.iKey = temp_max->iKey;			// 삭제 대상인 노드의 키에 temp노드 key복사하기
				Delete(stRoot, *temp_max);				// temp노드 삭제하기 
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
		cout << "[BinarySearch] 찾았습니다.";
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
