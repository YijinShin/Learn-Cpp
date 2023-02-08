#include "stdafx.h"
#include "hw20230207_2.h"

using namespace std;
using namespace hw20230207_2;

LIST Linkedlist::CreateLinkedList() {
	LIST list{ nullptr };
	return list;
}
void Linkedlist::AddNode(PLIST pList, int _iKra, int _iEng, int _iMath, char _szName[]) {
	// 이렇게 node로해서 주소값을 리스트에 달면, 이 함수가 끝나면 stack에 할당된node가 사라지면서 댕글링포인터가 됨. 
	//그래서 동적할당으로 해야하는거임. 
	/*
	NODE node;
	node.nextNode = nullptr;
	node.m_iMath = _iMath;
	node.m_iKra = _iKra;
	node.m_iEng = _iEng;
	strcpy_s(node.m_szName, _szName);
	CalcAvg(&node);
	CalcScore(&node);

	// if first node
	if (pList->head == nullptr) {
		pList->head = &node;
	}
	// else
	else {
		pList->last->nextNode = &node;
		pList->last = &node;
	}
	*/
	
	NODE* node = new NODE;
	node->nextNode = nullptr;
	node->m_iMath = _iMath;
	node->m_iKra = _iKra;
	node->m_iEng = _iEng;
	strcpy_s(node->m_szName, _szName);
	CalcAvg(node);
	CalcScore(node);

	// if first node
	if (pList->head == nullptr) {
		pList->head = node;
	}
	// else
	else {
		pList->last->nextNode = node;
	}
	pList->last = node;
	
}
void Linkedlist::RemoveNode(PLIST pList, char _szName[]) {
	NODE* prevNode = nullptr;
	NODE* currNode = pList->head;
	bool isFound(false);
	while (1) {
		if (currNode == nullptr) {
			cout << endl;
			break;
		}
		if (!strcmp(currNode->m_szName, _szName)) {
			isFound = true;
			break;
		}
		prevNode = currNode;
		currNode = currNode->nextNode;
	}
	if (!isFound) {
		cout << "학생의 정보가 존재하지 않습니다." << endl;
	}
	else {
		// head node인 경우
		if (pList->head == currNode) {
			// only node
			if (pList->last == currNode) {
				pList->head = nullptr;
				pList->last = nullptr;
			}
			else {
				pList->head = currNode->nextNode;
			}
		}
		// last node인 경우
		else if (currNode->nextNode == nullptr) {
			prevNode->nextNode = nullptr;
			pList->last = prevNode;
		}
		// middle node인 경우
		else {
			prevNode->nextNode = currNode->nextNode;
		}
		delete currNode;
		currNode = nullptr;
	}
	
}
void Linkedlist::ShowSearchInfo(const LIST* pList, char _szName[]) {
	NODE* targetNode = Search(pList, _szName);
	if (targetNode == nullptr) {
		cout << "학생의 정보가 존재하지 않습니다." << endl;
	}
	else {
		ShowNode(targetNode);
		cout << endl;
	}
}

void Linkedlist::ShowNode(const NODE* node) {
	cout << endl;
	cout << "이름: " << node->m_szName << endl;
	cout << "국어: " << node->m_iKra << " /영어: " << node->m_iEng << " /수학: " << node->m_iMath << endl;
	cout << "평균: " << node->m_fAvg << " /학점: " << node->m_cScore << endl;
}
NODE* Linkedlist::Search(const LIST* pList, char _szName[]) {
	NODE* currNode = pList->head;
	bool isFound(false);
	while (1) {
		if (currNode == nullptr) {
			cout << endl;
			break;
		}
		if (!strcmp(currNode->m_szName, _szName)) {
			isFound = true;
			break;
		}
		currNode = currNode->nextNode;
	}
	if (isFound)return currNode;
	else return nullptr;
}

void Linkedlist::ShowList(const LIST* pList) {
	NODE* currNode = pList->head;
	
	while (1) {
		if (currNode == nullptr) {
			cout << endl;
			break;
		}
		ShowNode(currNode);
		currNode = currNode->nextNode;
	}
}
void Linkedlist::DeleteList(PLIST pList) {
	NODE* currNode = pList->head;
	NODE * nextNode = currNode->nextNode;
	while (1) {
		if (currNode == nullptr) break;

		delete currNode;
		currNode = nextNode;
		nextNode = currNode->nextNode;
	}
}

void Linkedlist::SortList(PLIST pList) {
	/* 평균을 기준으로 sort */
}
void Linkedlist::CalcAvg(NODE* node) {
	node->m_fAvg = (node->m_iKra + node->m_iEng + node->m_iMath) / 3.f;
}
void Linkedlist::CalcScore(NODE* node) {
	if (node->m_fAvg >= 90) node->m_cScore = 'A';
	else if (node->m_fAvg >= 80) node->m_cScore = 'B';
	else if (node->m_fAvg >= 70) node->m_cScore = 'C';
	else if (node->m_fAvg >= 60) node->m_cScore = 'D';
	else if (node->m_fAvg >= 50) node->m_cScore = 'E';
	else node->m_cScore = 'F';
}
