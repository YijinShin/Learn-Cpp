#pragma once

class BinarySearchTree;

class MainGame_BinarySearchTree
{
private:
	BinarySearchTree* m_cBST;
public:
	MainGame_BinarySearchTree();
	~MainGame_BinarySearchTree();

	void Insert();
	void Delete();
};

