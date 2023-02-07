#include "stdafx.h"
#include "AdjacencyMatrix_Direction.h"

using namespace std;
using namespace AM_Direction;

enum Menu { ADDEDGE=1, REMOVEEDGE, SHOW, SEARCHEDGE, SEARCHNODEINFO, CLEAN, QUIT};

int main() {
	int iMenu(0);
	int iSize(0);
	int iStartNode(0), iEndNode(0);
	bool isEnd(false);
	AMatrix amatrix;

	// create graph with adjacency list
	cout << " Enter the number of nodes : ";
	cin >> iSize;
	amatrix = AdjacencyMatrix::CreateAMatrix(iSize);
	cout << " [ Created adjacency matrix. ]" << endl;
	

	while (1) {

		cout <<endl<< " Selet menu (1.Add edge, 2.Remove edge, 3.Show graph, 4.Search edge, 5.Search node info, 6.Clear, 7.Quit)";
		cin >> iMenu;
		cin.ignore();

			switch (iMenu)
			{
			case ADDEDGE:
				cout << "[ADD EDGE] Enter start node and end node: ";
				cin >> iStartNode;
				cin >> iEndNode;
				cin.ignore();
				AdjacencyMatrix::AddEdge(&amatrix, iStartNode, iEndNode);
				break;
			case REMOVEEDGE:
				cout << "[REMOVE EDGE] Enter start node and end node: ";
				cin >> iStartNode;
				cin >> iEndNode;
				cin.ignore();
				AdjacencyMatrix::RemoveEdge(&amatrix, iStartNode, iEndNode);
				break;
			case SHOW:
				cout << "[SHOW]  Show all edges";
				AdjacencyMatrix::ShowGraph(&amatrix);
				break;
			case SEARCHEDGE:
				cout << "[SEARCH EDGE] Enter start node and end node: ";
				cin >> iStartNode;
				cin >> iEndNode;
				cin.ignore();
				AdjacencyMatrix::SearchEdge(&amatrix, iStartNode, iEndNode);
				break;
			case SEARCHNODEINFO:
				cout << " [SEARCH NODE INFO] Enter node: ";
				cin >> iStartNode;
				cin.ignore();
				AdjacencyMatrix::SearchNodeInfo(&amatrix, iStartNode);
				break;
			case CLEAN:
				system("cls");
				break;
			case QUIT:
				cout << " [QUIT]" << endl;
				isEnd = true;
				break;
			default:
				cout << "WORING INPUT / ";
				break;
			}

			if (isEnd) break;
	}
}
