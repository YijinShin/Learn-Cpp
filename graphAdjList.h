#pragma once 
#include <iostream>
#include <vector>
using namespace std;

// Directed, 무 가중치 
class AdjList{
    private:
        vector<int> *adjList;  
        int V; // vertex 수 
        int E; // edge 수 
        bool *visited;

    public:
        AdjList(){
            cout << "[Vertex number, Edge number ]: ";
            cin >>V>>E;
            adjList = new vector<int>[V+1];
            visited = new bool[V+1];
            for(int i=0;i<=V;i++){
                visited[i] = false;
            } 
            
            for(int i=0;i<E;i++){
                AddEdge();
            }
        }
        ~AdjList(){
            delete[] visited;
            delete[] adjList;
        }

        void AddEdge(){
            int start_v, end_v;
            cout << " Add edge [start vertex, end vertex]: ";
            cin >> start_v >> end_v;
            adjList[start_v].push_back(end_v); 
        }   
        
        void RemoveEdge(){
            int start_v, end_v;
            cout << " Add edge [start vertex, end vertex]: ";
            cin >> start_v >> end_v;
            adjList[start_v].erase(remove(adjList[start_v].begin(), adjList[start_v].end(), end_v), adjList[start_v].end());
        }   

        void ShowAdjList(){
            cout<<"<Edge List>"<<endl;
            for(int i=1;i<=V;i++){             
                for(int j=0;j<adjList[i].size();j++){
                    cout << "["<<i<<","<<adjList[i].at(j)<<"]  ";
                }
                cout << endl;
            }
        }

        /*탐색 = 모든 정점에 들리는 것. 간선은 다 들릴 필요없음*/

        void BFS(){
            
        }

        //깊이 우선 탐색 Depth first search  
        void DFS(int vertex){
            int next;

            visited[vertex] = true; // 현재 정점 visited true로 바꾸기 
            cout << vertex<<"-";

            // 해당 정점과 이어지는 모든 정점 확인하기 
            for(int i=0;i<adjList[vertex].size();i++){
                next = adjList[vertex][i]; 
                if(!visited[next]) DFS(next); // 있는데 확인 안한 정점이면 재귀 호출                 
            }
            // 혹시 확인 안된 다른 정점이 있는지 확인
            for(int i=1;i<=V;i++){
                if(!visited[i]) DFS(i);
            }            
        }

};