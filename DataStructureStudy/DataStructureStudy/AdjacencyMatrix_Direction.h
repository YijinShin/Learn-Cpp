#pragma once

/* 그래프 : 방향 
*  구현방법	: 연결행렬 

*/

namespace AM_Direction {
	typedef struct tagAdjacencyMatrix {
		int iVcnt;
		int **iAdjacencyMatrix;
	}AMatrix, *PAMatrix;

	class AdjacencyMatrix {

	public: 
		// 기본 기능 
		static AMatrix CreateAMatrix(int iSize);
		static void AddEdge(PAMatrix pAmatrix, int iNodeStart, int iNodeEnd);
		static void RemoveEdge(PAMatrix pAmatrix, int iNodeStart, int iNodeEnd);
		static void ShowGraph(const AMatrix* pAmatrix);
			// AddNode()는 안됨. 처음부터 size fix이기 때문. 이것이 인접행렬의 단점이기도 하다. 
			// RemoveNode()도 일단 안됨. 마찬가지로 size fix니까. -> iVcnt를 줄여서 눈속임을 할수는 있다. 

		// 서치 기능 
		static void SearchEdge(const AMatrix* pAmatrix, int iStartNode, int iEndNode);
		static void SearchNodeInfo(const AMatrix* pAmatrix, int iNode);
			//searchNode() 의미가 없어서 구현안함. 
		// 그래프 타입 확인 기능
		static bool IsCompleteGraphh(const AMatrix* pAmatrix, int iEcnt);
		static bool IsCycleGraphh(const AMatrix* pAmatrix);
			//static bool IsLinkedGraph();	// 이거는 기본적으로 무방향 그래프라 연결, 비연결은 따지지 않는다. 

	};
}