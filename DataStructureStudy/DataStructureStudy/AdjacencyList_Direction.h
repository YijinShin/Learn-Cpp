#pragma once
#include <vector>
#include "stdafx.h"
using namespace std;
/* Direction graph */

namespace AL_Direction {
	typedef struct AdjacencyList {
		vector<vector<int>*> vAdList;
		int iVcnt;
		int iEcnt;
		AdjacencyList():iVcnt(0), iEcnt(0) {
			vAdList.push_back(new vector<int>);	// 하나 넣어놓고 시작하는 이유는 iVnt와 맞추기 위해
		}//ADLIST 객체가 생성되는 순간 불림
	}ADLIST;

	class AdjacencyList_Direction {
	private:
		ADLIST* m_stAdList;
	public:
		AdjacencyList_Direction();
		~AdjacencyList_Direction();

		void Release();

		void AddVertex();
		void RemoveVertex(int _iVidx);

		void AddEdge(int _iStartV, int _iEndV);
		void RemoveEdge(int _iStartV, int _iEndV);

		void Display() const;
	};
}
