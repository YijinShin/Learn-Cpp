#pragma once

#include <iostream>

using namespace std;

typedef struct tagNode {
	int iData;
	tagNode* nextNodePtr;
}NODE, *PNODE;

typedef struct tagList {
	NODE* head;
	NODE* last;
}LIST, *PLIST;

namespace SLList {
	class SingleLinkedList {
		public:
			// ��� static�ƴϾ��.. �ٵ� ���� LinkedList ��ü�� main���� ������ �ʿ䰡 ����. �갡 �ɹ� ���� �� �������ִ°� ���. �׷��� �Լ��� �� static���� ���� 

			static LIST CreateList(); 

			static void Insert(PLIST list, int iData);
			static void Delete(PLIST list, int iData);
			static void ShowList(LIST list);
	};
}

LIST SLList::SingleLinkedList::CreateList() {
	LIST list{nullptr, nullptr};	// create list, setting list
	return list;
}

void SLList::SingleLinkedList::Insert(PLIST list, int iData) {
	NODE newNode{ iData, nullptr };	// ��� ������ ��������. 
	// if newNode is first node
	if (list->head == nullptr) {
		list->head = &newNode;
	}
	else {
		list->last->nextNodePtr = &newNode;
	}
	list->last = &newNode;
}

void SLList::SingleLinkedList::Delete(PLIST list, int iData) {
	PNODE prevNode = nullptr;
	PNODE currNode = list->head;
	
	while (1) {
		
		// find 
		if (currNode->iData == iData) {
			
			// if currNode == head node
			if (prevNode == nullptr) {
				list->head = currNode->nextNodePtr;
				delete currNode;
				currNode = nullptr;// local variable�̶� ���ص� �ɰŰ�����. 
			}
			// if currNode == last node
			else if (currNode->nextNodePtr == nullptr) {
				list->last = prevNode;
				prevNode->nextNodePtr = nullptr;
				delete currNode;
				currNode = nullptr;
			}
			// if currNode == middle node
			else {
				// make new link
				prevNode->nextNodePtr = currNode->nextNodePtr;
				// return memory
				delete currNode;
				currNode = nullptr;	
			}

			return;
		}

		// move to next node
		prevNode = currNode;
		currNode = currNode->nextNodePtr;
	}
}

void SLList::SingleLinkedList::ShowList(LIST list) {
	PNODE currNode = list.head;
	while (1) {
		cout << currNode->iData << ", ";
		// if list end 
		if (currNode->nextNodePtr == nullptr) {
			cout << "<last> "<<endl;
			break;
		}
		currNode = currNode->nextNodePtr;
	}
}