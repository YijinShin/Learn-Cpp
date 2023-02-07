#pragma once

namespace AM_Undirection {
	typedef struct tagAdjacencyMatrix {
		int iVcnt;
		int** iAdjacencyMatrix;
	}AMatrix, *PAMatrix;
	
	class AdjacencyMatrix {

	public:
		// �⺻ ��� 
		static AMatrix CreateAMatrix(int iSize);
		static void AddEdge(PAMatrix pAmatrix, int iNodeStart, int iNodeEnd);
		static void RemoveEdge(PAMatrix pAmatrix, int iNodeStart, int iNodeEnd);
		static void ShowGraph(const AMatrix* pAmatrix);
		static void DeleteGraph(PAMatrix pAmatrix);
		// AddNode()�� �ȵ�. ó������ size fix�̱� ����. �̰��� ��������� �����̱⵵ �ϴ�. 
		// RemoveNode()�� �ϴ� �ȵ�. ���������� size fix�ϱ�. -> iVcnt�� �ٿ��� �������� �Ҽ��� �ִ�. 

	// ��ġ ��� 
		static void SearchEdge(const AMatrix* pAmatrix, int iStartNode, int iEndNode);
		static void SearchNodeInfo(const AMatrix* pAmatrix, int iNode);
		//searchNode() �ǹ̰� ��� ��������. 
		
	// �׷��� Ÿ�� Ȯ�� ���
		static bool IsCompleteGraphh(const AMatrix* pAmatrix, int iEcnt);
		static bool IsCycleGraph(const AMatrix* pAmatrix);
		static bool IsLinkedGraph(const AMatrix* pAmatrix);
	};
}