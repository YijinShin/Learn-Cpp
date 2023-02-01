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
			static void ShowList(const LIST* list);
	};
}

LIST SLList::SingleLinkedList::CreateList() {
	LIST list{nullptr, nullptr};	// create list, setting list
	return list;
}

void SLList::SingleLinkedList::Insert(PLIST list, int iData) {
	//NODE newNode{ iData, nullptr };	// 이걸 동적할당으로 하지 않고 이렇게 변수로 해버리면 이 함수 끝나면 node가 사라짐. 그래서 insert가 안된걸로 처리됨. 그리고 밑에서 list->head나 list->last에는 댕글링포인터만남게됨
	PNODE newNode = new NODE{ iData, nullptr };	
	// if newNode is first node
	if (list->head == nullptr) {
		cout << "insert first node" << endl;
		list->head = newNode;
	}
	else {
		cout << "insert middle node" << endl;
		list->last->nextNodePtr = newNode;
	}
	list->last = newNode;
}

void SLList::SingleLinkedList::Delete(PLIST list, int iData) {
	PNODE prevNode = nullptr;
	PNODE currNode = list->head;

	if (currNode == nullptr) {
		cout << "Notting in the list" << endl;
		return;
	}
	
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

		if (currNode == nullptr) {
			cout << iData<<"is not in the list" << endl;
			return;
		}
	}
}

void SLList::SingleLinkedList::ShowList(const LIST* list) {	// const PLIST 이렇게 하면 읽기전용 포인터가 아니라 상수 포인터 변수가 되어버림... PLIST이걸 LIST* 로 인식하지 않고 그냥 하나의 타입이라고 인식해버려서 그런듯 
	
	const NODE* currNode = list->head;
	
	if (currNode == nullptr) {
		cout << "Notting in the list" << endl;
		return;
	}

	while (1) {
		cout << currNode->iData << ", ";
		// if list end 
		if (currNode->nextNodePtr == nullptr) {
			cout << "<last> " << endl;
			break;
		}
		currNode = currNode->nextNodePtr;
	}
}