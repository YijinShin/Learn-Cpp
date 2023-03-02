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

	// ��� key�� �Է¹ޱ�
	cout << "[Insert] �߰��� ����� Key���� �Է����ּ���: ";
	cin >> stNewNode->iKey;
	// Insert ȣ��
	if (!m_cBST->BinarySearch(m_cBST->GetRootNode(), *stNewNode)) {
		cout << "[BinarySearch] ã�� ���߽��ϴ�." << endl;
	}
}

void MainGame_BinarySearchTree::Insert()
{
	int iKey(0);
	NODE* stNewNode = new NODE;

	// ��� key�� �Է¹ޱ�
	cout << "[Insert] �߰��� ����� Key���� �Է����ּ���: ";
	cin >> stNewNode->iKey;
	// Insert ȣ��
	m_cBST->Insert(m_cBST->GetRootNode(), *stNewNode);
}

void MainGame_BinarySearchTree::Delete()
{
	int iKey(0);
	NODE* stNewNode = new NODE;

	// ��� key�� �Է¹ޱ�
	cout << "[Insert] ������ ����� Key���� �Է����ּ���: ";
	cin >> stNewNode->iKey;
	// Delete ȣ�� 
	m_cBST->Delete(m_cBST->GetRootNode(), *stNewNode);
}
