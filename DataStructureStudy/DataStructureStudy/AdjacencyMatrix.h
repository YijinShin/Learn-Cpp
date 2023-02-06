#pragma once

namespace AM {
	typedef struct tagAdjacencyMatrix {
		int iVcnt;
		int* (iAdjacencyMatrix)[];
	}AMatrix, *PAMatrix;

	class AdjacencyMatrix {
	public: 
		static AMatrix CreateAMatrix(int iSize);
	};
}