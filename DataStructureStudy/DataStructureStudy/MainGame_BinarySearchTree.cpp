#include "stdafx.h"
#include "MainGame_BinarySearchTree.h"
#include "BinarySearchTree.h"

using namespace std;

MainGame_BinarySearchTree::MainGame_BinarySearchTree()
{
	m_cBST = new BinarySearchTree;
}

MainGame_BinarySearchTree::~MainGame_BinarySearchTree()
{
	Release();
}

void MainGame_BinarySearchTree::Update()
{
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		system("cls");

		cout << "[BST] 1.Insert 2.Delete 3.QUIT: ";
		cin >> iMenu;

		switch (iMenu)
		{
		case INSERT:
			Insert();
			break;
		case DELETE:
			Delete();
			break;
		case B_SEARCH:
			BinarySearch();
			break;
		case PRE_ORDER:
			
			break;
		case IN_ORDER:

			break;
		case POST_ORDER:
		
			break;
		case RANDER:
			m_cBST->Rander();
			break;
		case QUIT:
			isEnd = true;
			break;
		default:
			break;
		}

		if (isEnd) break;
		system("pause");
	}
}

void MainGame_BinarySearchTree::Release()
{
	Safe_Delete(m_cBST);
}

void MainGame_BinarySearchTree::BinarySearch()
{
	int iKey(0);
	NODE* stNewNode = new NODE;

	// 노드 key값 입력받기
	cout << "[Insert] 추가할 노드의 Key값을 입력해주세요: ";
	cin >> stNewNode->iKey;
	// Insert 호출
	if (!m_cBST->BinarySearch(m_cBST->GetRootNode(), *stNewNode)) {
		cout << "[BinarySearch] 찾지 못했습니다." << endl;
	}
}

void MainGame_BinarySearchTree::Insert()
{
	int iKey(0);
	NODE* stNewNode = new NODE;

	// 노드 key값 입력받기
	cout << "[Insert] 추가할 노드의 Key값을 입력해주세요: ";
	cin >> stNewNode->iKey;
	// Insert 호출
	m_cBST->Insert(m_cBST->GetRootNode(), *stNewNode);
}

void MainGame_BinarySearchTree::Delete()
{
	int iKey(0);
	NODE* stNewNode = new NODE;

	// 노드 key값 입력받기
	cout << "[Insert] 삭제할 노드의 Key값을 입력해주세요: ";
	cin >> stNewNode->iKey;
	// Delete 호출 
	m_cBST->Delete(m_cBST->GetRootNode(), *stNewNode);
}
