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
        if(menu==1){
            //AddEdge(adjList);
            adjList.AddEdge();
        }
        else if(menu==2){
            //RemoveEdge(adjList);
            adjList.RemoveEdge();
        }
        else if(menu==3){
            //ShowAdjList(adjList, V);
            adjList.ShowAdjList();
        }else break;
    }
    return 0;
}

int ShowMenu(){
    int menu;
    cout << "1. Add Edge" << endl << "2. Remove Edge" << endl << "3. Show List" << endl << "4. Quit" << endl << "menu: ";
    cin >> menu;
    cout << endl;
    return menu;
}
