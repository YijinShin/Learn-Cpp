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

    public:
        AdjList(){
            cout << "[Vertex number, Edge number ]: ";
            cin >>V>>E;
            for(int i=0;i<=V;i++) adjList = new vector<int>[V];
            for(int i=0;i<E;i++){
                AddEdge();
            }
        }
        ~AdjList(){
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
            //adjList[vertex_end].erase(remove(adjList[vertex_end].begin(), adjList[vertex_end].end(), vertex_start), adjList[vertex_end].end()); //undirected graph의 경우 쌍방에 모두 제거해야한다. 
        }   

        void AddVertex(int vertex){
            
        }

        void RemoveVertex(int vertex){

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

};