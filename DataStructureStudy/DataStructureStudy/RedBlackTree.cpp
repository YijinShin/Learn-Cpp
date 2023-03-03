#include "RedBlackTree.h"
#include "stdafx.h"
using namespace std;


template <typename T>
void RedBlackTree<T>::Menu_Insert()
{
	// create new node
	T tKey;
	cout << "[Insert] key: ";
	cin >> tKey;
	stNode<T>* newNode = new stNode(key);

	// find �ڸ� 
	Insert(m_root, newNode);
}

template<typename T>
void RedBlackTree<T>::Insert(stNode<T>* _root, stNode<T>& _newNode)
{
	if(_root == nullptr) {
		_root = _newNode;
		cout << "[Insert] ������ �ڸ��� ã�ҽ��ϴ�." << endl;
	}
	else if (&_root->key == _newNode.key) {
		cout << "[Insert] �̹� �ִ� �����Դϴ�." << endl;
		return;
	}
	else if (&_root->key > _newNode.key) {
		Insert(_root->stLeft, _newNode);
	}
	else if (&_root->key < _newNode.key) {
		Insert(_root->stRight, _newNode);
	}
}
