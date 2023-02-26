#include "stdafx.h"
#include "MainGame_BinarySearchTree.h"
#include "BinarySearchTree.h"

using namespace std;

MainGame_BinarySearchTree::MainGame_BinarySearchTree()
{
	m_cBST = new BinarySearchTree;
}

void MainGame_BinarySearchTree::Insert()
{
	int iKey(0);
	NODE* stNewNode = new NODE;

	// 노드 key값 입력받기
	cout << "[Insert] 추가할 노드의 Key값을 입력해주세요: ";
	cin >> stNewNode->iKey;

	// Insert함수 호출하기
	if (m_cBST->Insert(m_cBST->GetRootNode(), *stNewNode)) {
		cout << "[MG_Insert] 삽입 성공했습니다." << endl;
	}
	else cout << "[MG_Insert] 삽입이 제대로 이뤄지지 않았습니다." << endl; //삭제 제대로 안됨
}