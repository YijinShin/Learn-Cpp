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
			// 사실 static아니어도됨.. 근데 딱히 LinkedList 객체를 main에서 선언할 필요가 없다. 얘가 맴버 변수 뭐 가지고있는게 없어서. 그래서 함수는 다 static으로 해줌 

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
	NODE newNode{ iData, nullptr };	// 얘는 꼬리에 붙을거임. 
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
				currNode = nullptr;// local variable이라 안해도 될거같긴함. 
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