#include "stdafx.h"
#include "AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList()
{
	m_AdjList.iVcnt = 0;
	m_AdjList.iEcnt = 0;
}

AdjacencyList::AdjacencyList(int _iVcnt)
{
	m_AdjList.iVcnt = _iVcnt;
	m_AdjList.iEcnt = 0;
}

AdjacencyList::~AdjacencyList()
{
	
}

void AdjacencyList::Initialize()	// 동적할당
{
	//tagAdjList.adjList = new vector<vector<int>>(_iVcnt, vector<int>(0,0));	// 5개 vertex에 대한 adjList생성
	for (int i = 0; i < m_AdjList.iVcnt; i++) {
		m_AdjList.adjList.push_back(vector<int>());
	}
}

void AdjacencyList::AddVertex()
{
	m_AdjList.adjList.push_back(vector<int>(0,0));
}

void AdjacencyList::AddEdge(int iStartV, int iEndV)
{
	m_AdjList.adjList[1].push_back(iEndV);
}
