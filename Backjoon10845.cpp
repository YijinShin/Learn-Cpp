#include <iostream>
#include <vector>
#include<sstream>
using namespace std;
#define MAXSIZE 10000

class Queue{
    private:
        int* list;
        int size;
        int front;
        int rear;
        bool isEmpty;
    public:
        Queue(){
            list = new int[MAXSIZE];
            size = 0;
            front = 0;
            rear = 0;
            isEmpty = true;
        }    
        ~Queue(){ delete[] list;}
        void Push(int data){
            rear = (rear+1)%MAXSIZE;
            list[rear] = data;
            size++;
            if(size>0) isEmpty = true;
        }
        void Pop(){
            if(isEmpty) cout << "-1\n";
            else{
                cout << list[front]<<"\n";
                size--;
                front = (front+1)%MAXSIZE;
            } 
            if(size<=0) isEmpty = false;
        }
        void Size(){cout << size<<"\n";}
        void Empty(){
            if(isEmpty) cout <<"1\n";
            else cout <<"0\n";
        }
        void Front(){ 
            if(isEmpty) cout << "-1\n";
            else cout << list[(front+1)%MAXSIZE]<<"\n"; 
        }
        void Back(){ 
            if(isEmpty) cout << "-1\n";
            else cout << list[rear]<<"\n"; 
        }
};


struct Command{
    string command;
    int data;
};

int main(){

    Queue queue;

    int commandNum;
    string cmd;
    istringstream ss(cmd);
    vector<string> x;
    string stringbuf;

    cin >> commandNum;
    Command commandList[commandNum];
    
    for(int i=0;i<commandNum;i++){
        getline(cin, cmd);
        stringstream ss(cmd);
        ss.str(cmd);
        ss >> commandList[i].command;
        if(ss >> commandList[i].data){};

        cout << i<<":" <<commandList[i].command<<","<<commandList[i].data<<endl;
    }

    for(int i=0;i<commandNum;i++){
        if(commandList[i].command == "push") queue.Push(commandList[i].data);
        else if(commandList[i].command == "pop") queue.Pop();
        else if(commandList[i].command == "size") queue.Size();
        else if(commandList[i].command == "empty") queue.Empty();
        else if(commandList[i].command == "front") queue.Front();
        else if(commandList[i].command == "back") queue.Back();
    }

    
    return 0;
}
