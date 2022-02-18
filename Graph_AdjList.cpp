#include <iostream>
#include <vector>
#include "graphAdjList.h"
using namespace std;

// Adjacency list를 이용한 graph 구현 

int ShowMenu();

int main(){
    AdjList adjList;
    cout << endl;

    int menu;
    while(true){
        menu = ShowMenu();
        if(menu==1) adjList.AddEdge();
        else if(menu==2) adjList.RemoveEdge();
        else if(menu==3) adjList.ShowAdjList();
        else if(menu==4) {
            adjList.BFS(1);
            adjList.InitiateVisitedList();
            cout << endl;
        }
        else if(menu==5) {
            adjList.DFS(1); 
            adjList.InitiateVisitedList();
            cout << endl;
        }
        else break;
    }
    return 0;
}

int ShowMenu(){
    int menu;
    cout << "\n1. Add Edge \n2. Remove Edge \n3. Show List \n4. BFS \n5. DFS \n6. Quit \nmenu: ";
    cin >> menu;
    cout << endl;
    return menu;
}
