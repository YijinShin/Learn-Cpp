#pragma once

#include "stdafx.h"

using namespace std;

namespace CQueueArray {

	typedef struct tagCircularQueue {
		int* iArr;
		int iFront;
		int iRear;
		int iSize;
	}CQUEUE, *PCQUEUE;

	class CircularQueue {
	public:
		static CQUEUE CreateCircularQueue();
		static void Inqueue(PCQUEUE cqueue, int iData);
		static void Dequeue(PCQUEUE cqueue);
		static void ShowCQueue(const CQUEUE* cqueue);
	};

	CQUEUE CQueueArray::CircularQueue::CreateCircularQueue() {
		CQUEUE cqueue;

		cout << "circular queue의 size: ";
		cin >> cqueue.iSize;			
		cqueue.iSize++; // 지정한 사이즈보다 한개 더 있어야 데이터를 size만큼 넣을 수 있음
		cqueue.iArr = new int[cqueue.iSize] {0};	
		cqueue.iFront = 0;
		cqueue.iRear = 0;

		return cqueue;
	}

	void CQueueArray::CircularQueue::Inqueue(PCQUEUE cqueue, int iData) {
		if (((cqueue->iRear+1) % cqueue->iSize) == cqueue->iFront) {
			cout << "cqueue is full " << endl;
			return;
		}

		cqueue->iRear = (cqueue->iRear + 1) % cqueue->iSize;
		cqueue->iArr[cqueue->iRear] = iData;
	}

	void CQueueArray::CircularQueue::Dequeue(PCQUEUE cqueue) {

		//if cqueue is empty
		if (cqueue->iRear == cqueue->iFront) {
			cout << "Notting in the list" << endl;
			return;
		}

		cqueue->iArr[cqueue->iFront + 1] = 0;
		cqueue->iFront = (cqueue->iFront + 1) % cqueue->iSize;
		
	}

	void CQueueArray::CircularQueue::ShowCQueue(const CQUEUE* cqueue) {
		
		int iIndex = (cqueue->iFront+1)%cqueue->iSize;

		while (1) {
			if (iIndex == cqueue->iRear+1) {
				cout << " <END>." << endl;
				break;
			}
			
			cout << cqueue->iArr[iIndex]<<", ";
			iIndex++;
			if (iIndex == cqueue->iSize) {
				iIndex = 0;
			}
		}
	}
}