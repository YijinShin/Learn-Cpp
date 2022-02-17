#include <iostream>
#include <vector>
#include "graphAdjList.h"
using namespace std;

// Adjacency list를 이용한 graph 구현 

int ShowMenu();
void AddEdge(vector<int> adjList[]);
void RemoveEdge(vector<int> adjList[]);
void ShowAdjList(vector<int> adjList[], int V);

int main(){
    AdjList adjList;

    int menu;
    int V,E;
    /*
    cout << "[Vertex number, Edge number ]: ";
    cin >>V>>E;
    vector<int> adjList[V+1];
    for(int i=0;i<E;i++){
       AddEdge(adjList);
    }
    */
   cout << endl;
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

void AddEdge(vector<int> adjList[]){
    int start_v, end_v;
    cout << " Add edge [start vertex, end vertex]: ";
    cin >> start_v >> end_v;
    adjList[start_v].push_back(end_v); 
    // adjList[start_v].push_back(end_v); //undirected graph의 경우 쌍방에 모두 추가해야한다. 
}   

void RemoveEdge(vector<int> adjList[]){
    int start_v, end_v;
    cout << " Add edge [start vertex, end vertex]: ";
    cin >> start_v >> end_v;
    adjList[start_v].erase(remove(adjList[start_v].begin(), adjList[start_v].end(), end_v), adjList[start_v].end());
    //adjList[vertex_end].erase(remove(adjList[vertex_end].begin(), adjList[vertex_end].end(), vertex_start), adjList[vertex_end].end()); //undirected graph의 경우 쌍방에 모두 제거해야한다. 
} 

void ShowAdjList(vector<int> adjList[], int V){
    cout<<"<Edge List>"<<endl;
    for(int i=1;i<=V;i++){             
        for(int j=0;j<adjList[i].size();j++){
            cout << "["<<i<<","<<adjList[i].at(j)<<"]  ";
        }
        cout << endl;
    }
}