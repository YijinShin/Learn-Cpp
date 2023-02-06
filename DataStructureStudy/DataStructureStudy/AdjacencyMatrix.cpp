#include "stdafx.h"
#include "AdjacencyMatrix.h"

using namespace std;
using namespace AM;

AMatrix AdjacencyMatrix::CreateAMatrix(int iSize) {
	AMatrix amatrix;
	amatrix.iVcnt = iSize;
	amatrix.iAdjacencyMatrix = new int[iSize][iSize]

	return amatrix;
}