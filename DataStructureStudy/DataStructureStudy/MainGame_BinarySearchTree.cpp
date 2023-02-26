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

	// ��� key�� �Է¹ޱ�
	cout << "[Insert] �߰��� ����� Key���� �Է����ּ���: ";
	cin >> stNewNode->iKey;

	// Insert�Լ� ȣ���ϱ�
	if (m_cBST->Insert(m_cBST->GetRootNode(), *stNewNode)) {
		cout << "[MG_Insert] ���� �����߽��ϴ�." << endl;
	}
	else cout << "[MG_Insert] ������ ����� �̷����� �ʾҽ��ϴ�." << endl; //���� ����� �ȵ�
}