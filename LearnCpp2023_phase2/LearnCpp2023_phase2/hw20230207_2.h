#pragma once

namespace hw20230207_2 {

	typedef struct tagNode {
		/* ¼ºÀûÇ¥ */
		int m_iKra;
		int m_iEng;
		int m_iMath;
		float m_fAvg;
		char m_szName[20];
		char m_cScore;

		tagNode* nextNode;
	}NODE, *PNODE;

	typedef struct tagList {
		NODE* head;
		NODE* last;
	}LIST, *PLIST;

	class Linkedlist {
	private:
		static NODE* Search(const LIST* pList, char _szName[]);
		static void ShowNode(const NODE* node);
	public:
		static LIST CreateLinkedList();
		static void AddNode(PLIST pList, int _iKra, int _iEng, int _iMath, char _szName[]);
		static void RemoveNode(PLIST pList, char _szName[]);
		static void ShowList(const LIST* pList);
		static void ShowSearchInfo(const LIST* pList, char _szName[]);
		static void DeleteList(PLIST pList);
		static void SortList(PLIST pList);
		// binary search
		// arrange

		// 
		static void CalcAvg(NODE* node);
		static void CalcScore(NODE* node);

	};
}