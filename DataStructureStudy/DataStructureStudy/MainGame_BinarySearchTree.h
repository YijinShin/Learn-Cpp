#pragma once

enum MENU { INSERT = 1, DELETE, B_SEARCH, PRE_ORDER, IN_ORDER, POST_ORDER, RANDER, QUIT };

class BinarySearchTree;

class MainGame_BinarySearchTree
{
private:
	BinarySearchTree* m_cBST;
public:
	MainGame_BinarySearchTree();
	~MainGame_BinarySearchTree();

	void Update();
	void Release();

	void BinarySearch();
	void Insert();
	void Delete();
};

