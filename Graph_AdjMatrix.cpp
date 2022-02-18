#include <iostream>
#include <vector>
#include "graphAdjMatrix.h"
using namespace std;

// Adjacency list를 이용한 graph 구현 

int ShowMenu();

int main(){
    AdjMatrix adjMatrix;
    cout << endl;

    int menu;
    while(true){
        menu = ShowMenu();
        if(menu==1){
            adjMatrix.AddEdge();
        }
        else if(menu==2){
            adjMatrix.RemoveEdge();
        }
        else if(menu==3){
            adjMatrix.ShowAdjMatrix();
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
