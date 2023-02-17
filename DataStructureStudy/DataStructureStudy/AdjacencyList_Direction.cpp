#include "stdafx.h"
#include <vector>
#include "AdjacencyList_Direction.h"

using namespace std;
using namespace AL_Direction;

AdjacencyList_Direction::AdjacencyList_Direction() 
{
	m_stAdList = new ADLIST;
}

AL_Direction::AdjacencyList_Direction::~AdjacencyList_Direction()
{
	Release();
}

void AL_Direction::AdjacencyList_Direction::Release()
{
	delete m_stAdList;
}

void AL_Direction::AdjacencyList_Direction::AddVertex()
{
	m_stAdList->vAdList.push_back(new vector<int>);
	m_stAdList->iVcnt++;
}

void AL_Direction::AdjacencyList_Direction::RemoveVertex(int _iVidx)
{
	vector<int>* removeVertex = m_stAdList->vAdList[_iVidx];
	m_stAdList->vAdList.erase(m_stAdList->vAdList.begin()+_iVidx, m_stAdList->vAdList.begin() + _iVidx+1);
	m_stAdList->iVcnt--;
	delete removeVertex;
}

void AL_Direction::AdjacencyList_Direction::AddEdge(int _iStartV, int _iEndV)
{
	m_stAdList->vAdList[_iStartV]->push_back(_iEndV);
	m_stAdList->iEcnt++;
}

void AL_Direction::AdjacencyList_Direction::RemoveEdge(int _iStartV, int _iEndV)
{
	// remove 구현해야함
//	int targetIndex = find(m_stAdList->vAdList[_iStartV].begin(), m_stAdList->vAdList[_iStartV].end(), _iEndV) - m_stAdList->vAdList[_iStartV].begin();
//	m_stAdList->vAdList[_iStartV].erase(targetIndex, targetIndex + 1);
	m_stAdList->iEcnt--;
}

void AL_Direction::AdjacencyList_Direction::Display() const
{
}
