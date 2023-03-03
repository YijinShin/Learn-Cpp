#pragma once

template <typename T>
struct stNode {
	stNode* stLeft;
	stNode* stRight;
	T key;

	stNode() : stLeft(nullptr), stRight(nullptr), key(0) {}
	stNode(T _key):stLeft(nullptr), stRight(nullptr){key = _key;}
};

template <typename T>
class RedBlackTree {
private:
	stNode* m_root;

public:
	RedBlackTree() :m_root(nullptr) {};
	~RedBlackTree() { Release();};

	void Release();

	void Menu_Insert();
	void Insert(stNode* _root, stNode& _newNode);
	void Delete();
	
	void BinarySearch();

	void PreOrder();
	void InOrder();
	void PostOrder();
};