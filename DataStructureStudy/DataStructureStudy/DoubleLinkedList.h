#pragma once

#include <iostream>

using namespace std;

/* queue를 single linked list로 구현함. 
array와는 다르게 처음에 size를 fix할 필요가 없음 */

typedef struct tagNode {
	int iData;
	tagNode* prevNode;
	tagNode* nextNode;
}NODE, *PNODE;

typedef struct tagList {
	PNODE head;
	PNODE last;
}LIST, *PLIST;

namespace DLList {
	class DoubleLinkedList {
	public:
		static LIST CreateList();
		static void Insert(PLIST list, int iData);
		static void Delete(PLIST list, int iData);
		static void ShowList(const LIST* list);
	};
}

LIST DLList::DoubleLinkedList::CreateList() {
	LIST list{ nullptr, nullptr };
	return list;
}

void DLList::DoubleLinkedList::Insert(PLIST list, int iData) {
	PNODE newNode = new NODE{ iData, nullptr, nullptr };
	
	// is first node
	if (list->head == nullptr)
		list->head = newNode;
	// is last node
	else {
		list->last->nextNode = newNode;
		newNode->prevNode = list->last;
	}
	//update list last 
	list->last = newNode;
}

void DLList::DoubleLinkedList::Delete(PLIST list, int iData) {
	PNODE prevNode = nullptr;
	PNODE currNode = list->head;

	//if list is empty
	if (currNode == nullptr) {
		cout << "Notting in the list" << endl;
		return;
	}

	while (1) {
		// found
		if (currNode->iData == iData) {

			// if this is the head node
			if (currNode->prevNode == nullptr) {
				// if this is only node
				if (currNode->nextNode == nullptr) {
					list->head = nullptr;
					list->last = nullptr;
				}
				// if this has next node
				else {
					list->head = currNode->nextNode;
					currNode->nextNode->prevNode = nullptr;
				}
			
			}
			// if this is the last node
			else if (currNode->nextNode == nullptr) {
				list->last = currNode->prevNode;

				currNode->prevNode->nextNode = nullptr;
			}
			// if this is middle node
			else {
				currNode->prevNode->nextNode = currNode->nextNode;
				currNode->nextNode->prevNode = currNode->prevNode;
			}

			
			// delete currNode
			delete currNode;
			currNode = nullptr;

			return;
		}

		prevNode = currNode;
		currNode = currNode->nextNode;

		if (currNode == nullptr) {
			cout << iData << "is not in the list" << endl;
			return;
		}
	}

}

void DLList::DoubleLinkedList::ShowList(const LIST* list) {
	const NODE* currNode = list->head;
	if (currNode == nullptr) {
		cout << "Notting in the list" << endl;
		return;
	}

	while (1) {
		cout << currNode->iData << ", ";
		if (currNode->nextNode == nullptr) {
			cout << "<END>" << endl;
			break;
		}
		currNode = currNode->nextNode;
	}
}

