#pragma once
#include <vector>

typedef struct tagAdjList {
	vector<vector<int>> adjList;	// adjacency list	( vertex, edge��� �߰��� �� �ֵ��� �ϱ� ���ؼ�)
	int iVcnt;				// num of vertex
	int iEcnt;				// num of edge
}ADJLIST, *PADJLIST;


class AdjacencyList {
private:
	ADJLIST m_AdjList;
public:
	AdjacencyList();
	AdjacencyList(int _iVcnt);
	~AdjacencyList();

	void Initialize();
	void AddVertex();
	void RemoveVertex(int _iVertex);
	void AddEdge(int iStartV, int iEndV);
	void RemoveEdge(int iStartV, int iEndV);
	void PrintGraph();
};