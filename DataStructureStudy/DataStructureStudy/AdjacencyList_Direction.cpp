#include "stdafx.h"
#include "AdjacencyList_Direction.h"

using namespace std;
using namespace AL_Direction;

bool AdjacencyList::IsCycleGraph() {
	
}

bool AdjacencyList::IsCompleteGraph(const AList* pAlist) {
	bool isComplete(false);
	if (pAlist->iEcnt == ((pAlist->iVcnt - 1) * pAlist->iVcnt)) isComplete = true;
	return isComplete;
}

AList AdjacencyList::CreateAList(int iVcnt) {
	AList aList;

	aList.iEcnt = 0;
	aList.iVcnt = iVcnt;
	aList.adjList = new vector<int>[iVcnt + 1];

	return aList;
}

void AddNode(PAList pAlist) {
	
}
void RemoveNode(PAList pAlist) {

}

void AddEdge(PAList pAlist) {

}
void RemoveEdge(PAList pAlist) {

}

void SearchEdge(const AList* pAlist) {

}
void SearchNodeInfo(const AList* pAlist) {

}

void ShowGraph(const AList* pAlist) {

}