#pragma once
#include <vector>
#include "SingleLinkedList.h"

/* Direction graph */

namespace AL_Direction {
	typedef struct tagAdjacencyList {
		vector<int>* adjList; // "vector<int>"의 배열을 동적할당 할거임. 마치 int의 배열을 동적할당할때 int* iArr를 선언하는 것 처럼
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
