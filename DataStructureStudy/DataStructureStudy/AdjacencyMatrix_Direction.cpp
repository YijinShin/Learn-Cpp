#include "stdafx.h"
#include "AdjacencyMatrix_Direction.h"

using namespace std;
using namespace AM_Direction;

AMatrix AdjacencyMatrix::CreateAMatrix(int iSize) {
	AMatrix amatrix;
	amatrix.iVcnt = iSize;
	amatrix.iAdjacencyMatrix = new int* [iSize + 1] {nullptr};
	for (int i = 0; i < iSize + 1; i++) amatrix.iAdjacencyMatrix[i] = new int [iSize + 1] {0};
	return amatrix;
}

void AdjacencyMatrix::AddEdge(PAMatrix pAmatrix, int iNodeStart, int iNodeEnd) {
	//wrong range
	if (iNodeStart <=0 || iNodeStart > pAmatrix->iVcnt) {
		cout << " Wrong Input (Graph has only " << pAmatrix->iVcnt << "nodes)" << endl;
	}
	else if( iNodeEnd <=0 || iNodeEnd > pAmatrix->iVcnt) {
		cout << " Wrong Input (Graph has only " << pAmatrix->iVcnt << "nodes)" << endl;
	}
	//self
	else if (iNodeEnd == iNodeStart) {
		cout << " Wrong Input" << endl;
	}
	// already exist
	else if (pAmatrix->iAdjacencyMatrix[iNodeStart][iNodeEnd] == 1) {
		cout << " Edge already exist." << endl;
	}
	// add edge
	else pAmatrix->iAdjacencyMatrix[iNodeStart][iNodeEnd] = 1;

}
void AdjacencyMatrix::RemoveEdge(PAMatrix pAmatrix, int iNodeStart, int iNodeEnd) {
	// already exist
	if (pAmatrix->iAdjacencyMatrix[iNodeStart][iNodeEnd] == 0) {
		cout << " Edge isn't exist." << endl;
	}
	//wrong range
	else if (iNodeStart <=0 || iNodeStart > pAmatrix->iVcnt || iNodeEnd <=0 || iNodeEnd > pAmatrix->iVcnt) {
		cout << " Wrong Input (Graph has only " << pAmatrix->iVcnt << "nodes)" << endl;
	}
	else if (iNodeEnd == iNodeStart) {
		cout << " Wrong Input" << endl;
	}
	//remove edge
	else pAmatrix->iAdjacencyMatrix[iNodeStart][iNodeEnd] = 0;
}
void AdjacencyMatrix::ShowGraph(const AMatrix* pAmatrix) {
	int iEcnt(0);

	for (int i = 1; i <= pAmatrix->iVcnt; i++) {
		for (int j = 1; j <= pAmatrix->iVcnt; j++) {
			if (pAmatrix->iAdjacencyMatrix[i][j] == 1) {
				iEcnt++;
				cout << " edge " << i << "-" << j << endl;
			}
		}
	}

	// graph info (edges, nodes)
	cout << " " << pAmatrix->iVcnt << "nodes / " << iEcnt << "edges" << endl;

	// direction graph
	cout << " Direction graph / ";

	// complete graph
	if (IsCompleteGraphh(pAmatrix, iEcnt)) cout << " Complete graph / ";
	else cout << " Non-Complete graph / ";

	// cycle graph
		//if (IsCycleGraphh(pAmatrix)) cout << " Cycle graph "<< endl;
		//else cout << " Non-Cycle graph" << endl;
	
} 

void AdjacencyMatrix::SearchEdge(const AMatrix* pAmatrix, int iNodeStart, int iNodeEnd) {
	//wrong range
	if (iNodeStart <= 0 || iNodeStart > pAmatrix->iVcnt) {
		cout << " Wrong Input (Graph has only " << pAmatrix->iVcnt << "nodes)" << endl;
	}
	else if (iNodeEnd <= 0 || iNodeEnd > pAmatrix->iVcnt) {
		cout << " Wrong Input (Graph has only " << pAmatrix->iVcnt << "nodes)" << endl;
	}
	//self
	else if (iNodeEnd == iNodeStart) {
		cout << " Wrong Input" << endl;
	}
	// exist
	else if (pAmatrix->iAdjacencyMatrix[iNodeStart][iNodeEnd] == 1) {
		cout << " "<< iNodeStart << " - " << iNodeEnd << ") Edge exist." << endl;
	}
	// not exist
	else cout << " " << iNodeStart << " - " << iNodeEnd << ") Edge dose not exist." << endl;
}

void AdjacencyMatrix::SearchNodeInfo(const AMatrix* pAmatrix, int iNode) {
	int iIndegree(0);
	int iOutdegree(0);

	// wrong input
	if (iNode <= 0 || iNode > pAmatrix->iVcnt) {
		cout << "Wrong input (Graph has only " << pAmatrix->iVcnt << "nodes)" << endl;
		return;
	}
	
	// indegree 
	for (int i = 1; i <= pAmatrix->iVcnt; i++) {
		if (pAmatrix->iAdjacencyMatrix[i][iNode] == 1) {
			iIndegree++;
			cout << " In. " << i <<"->" <<iNode << " /";
		}
	}
	cout << endl << " Indegree count : " << iIndegree << endl;

	// outdegree
	for (int i = 1; i <= pAmatrix->iVcnt; i++) {
		if (pAmatrix->iAdjacencyMatrix[iNode][i] == 1) {
			iOutdegree++;
			cout << " Out. " << i <<"->" <<iNode << " /";
		}
	}
	cout << endl << " Outdegree count : " << iOutdegree << endl;
}

bool AdjacencyMatrix::IsCompleteGraphh(const AMatrix* pAmatrix, int iEcnt) {
	bool isComplete(false);
	if (iEcnt == (pAmatrix->iVcnt -1)*pAmatrix->iVcnt) isComplete = true;
	return isComplete;
}
bool AdjacencyMatrix::IsCycleGraphh(const AMatrix* pAmatrix){
	bool isCycle(false);
	// 나중에 dfs, bfs하면 추가하기 
	return isCycle;
}