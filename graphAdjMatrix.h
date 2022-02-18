#pragma once 
#include <iostream>
#include <vector>
using namespace std;

// Directed, 무 가중치 
class AdjMatrix{
    private:
        int **adjMatrix;  
        int V; // vertex 수 
        int E; // edge 수 

    public:
        AdjMatrix(){
            cout << "[Vertex number, Edge number ]: ";
            cin >>V>>E;
            // 2차원 배열 동적할당 
            adjMatrix = new int*[V+1];
            for(int i=0;i<=V;i++) adjMatrix[i] = new int[V+1];            
            // 초기 엣지 입력받기 
            for(int i=0;i<E;i++) AddEdge();
        }
        ~AdjMatrix(){
            delete[] adjMatrix;
        }

        void AddEdge(){
            int start_v, end_v;
            cout << " Add edge [start vertex, end vertex]: ";
            cin >> start_v >> end_v;
            adjMatrix[start_v][end_v] = 1;
            //adjMatrix[end_v][start_v] = 1; // 무방향 그래프라면 해줘야한다.
        }   
        
        void RemoveEdge(){
            int start_v, end_v;
            cout << " Add edge [start vertex, end vertex]: ";
            cin >> start_v >> end_v;
            adjMatrix[start_v][end_v] = 0;
            //adjMatrix[end_v][start_v] = 0; // 무방향 그래프라면 해줘야한다.
        }   

        void ShowAdjMatrix(){
            cout<<"<Edge List>"<<endl;
            for(int i=1;i<=V;i++){
                cout << '\n';
                for(int j=1;j<=V;j++){
                    if(adjMatrix[i][j] == 1) cout << "["<<i<<","<<j<<"]";
                }                
            }
            cout << '\n';
        }
};