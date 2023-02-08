#include "stdafx.h"
#include <vector>

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

void AddVertex(PAList pAlist) {
	vector<int> *vertex = new vector<int>;
	//pAlist->adjList.push_back(vertex);
}
void RemoveVertex(PAList pAlist) {

}

void AddEdge(PAList pAlist, int iStartNode, int iEndNode) {
	//wrong range
	if (iStartNode <= 0 || iStartNode > pAlist->iVcnt) {
		cout << "Wrong start node" << endl;
		return;
	}
	else if (iEndNode <= 0 || iEndNode > pAlist->iVcnt) {
		cout << "Wrong end node" << endl;
		return;
	}
	//edge already exist 
		// 酒流 眉农 给窃 
	//add edge
	pAlist->adjList[iStartNode].push_back(iEndNode);
}
void RemoveEdge(PAList pAlist, int iStartNode, int iEndNode) {
	//wrong range
	if (iStartNode <= 0 || iStartNode > pAlist->iVcnt) {
		cout << "Wrong start node" << endl;
		return;
	}
	else if (iEndNode <= 0 || iEndNode > pAlist->iVcnt) {
		cout << "Wrong end node" << endl;
		return;
	}
	//edge already exist 
		// 酒流 眉农 给窃 
	//add edge
	pAlist->adjList[iStartNode].erase(remove(pAlist->adjList[iStartNode].begin(), pAlist->adjList[iStartNode].end(), iEndNode), pAlist->adjList[iStartNode].end());
}

void SearchEdge(const AList* pAlist) {

}
void SearchNodeInfo(const AList* pAlist) {

}

void ShowGraph(const AList* pAlist) {

}