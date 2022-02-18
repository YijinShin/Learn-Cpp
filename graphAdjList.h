#pragma once 
#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;
using namespace Que;

// Directed, 무 가중치 
class AdjList{
    private:
        vector<int> *adjList;  
        int V; // vertex 수 
        int E; // edge 수 
        bool *visited; // DFS, BFS에서 사용 
        Queue queue; // DFS에서 사용 

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

        //너비 우선 탐색 Breadth First Search : 큐 사용 
        void BFS(int vertex){
            int v;
            //방문 확인용 bool 리스트 초기화 
            for(int i=0;i<=V;i++) visited[i] = false;  

            // 시작 정점을 visited 체크 및 큐에 넣기
            visited[vertex] = true; 
            queue.Inqueue(vertex);

            // 너비 탐색 하기 
            while(!queue.ReturnIsEmpty()){
                // 정점 dequeue 하고, 출력하기 
                v = queue.Dequeue();
                cout << v << "-";
                // 방문 처리된 정점의 인접 정점들을 큐에 넣기 
                for(int i=0;i<adjList[v].size();i++){
                    if(!visited[adjList[v][i]]){
                        visited[adjList[v][i]] = true; // 방문처리
                        queue.Inqueue(adjList[v][i]); // 큐에넣기 
                    }
                }
            }

            for(int k=1;k<=V;k++){
                if(!visited[k]) {
                    visited[k] = true; 
                    queue.Inqueue(k);
                    while(!queue.ReturnIsEmpty()){
                        // 정점 dequeue 하고, 출력하기 
                        v = queue.Dequeue();
                        cout << v << "-";
                        // 방문 처리된 정점의 인접 정점들을 큐에 넣기 
                        for(int i=0;i<adjList[v].size();i++){
                            if(!visited[adjList[v][i]]){
                                visited[adjList[v][i]] = true; // 방문처리
                                queue.Inqueue(adjList[v][i]); // 큐에넣기 
                            }
                        }
                    }
                }
            }
        }

        //깊이 우선 탐색 Depth first search : 재귀 함수 사용
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

        void InitiateVisitedList(){
            for(int i=0;i<=V;i++) visited[i] = false;  
        }


};