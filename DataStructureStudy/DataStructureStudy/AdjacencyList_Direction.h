#pragma once
#include <vector>
#include "SingleLinkedList.h"

/* Direction graph */

namespace AL_Direction {
	typedef struct tagAdjacencyList {
		vector<int>* adjList; // "vector<int>"�� �迭�� �����Ҵ� �Ұ���. ��ġ int�� �迭�� �����Ҵ��Ҷ� int* iArr�� �����ϴ� �� ó��
		int iEcnt;
		int iVcnt;
	}AList, *PAList;

	class AdjacencyList {
	private:
		bool IsCycleGraph();
		bool IsCompleteGraph(const AList* pAlist);

	public:
		static AList CreateAList(int iVcnt);

		static void AddVertex(PAList pAlist);
		static void RemoveVertex(PAList pAlist);

		static void AddEdge(PAList pAlist);
		static void RemoveEdge(PAList pAlist);

		static void SearchEdge(const AList* pAlist);
		static void SearchNodeInfo(const AList* pAlist);

		static void ShowGraph(const AList* pAlist);

	};
}
