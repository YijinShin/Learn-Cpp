#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 100

// C++ STL(표준 템플릿 라이브러리)에 Queue가 구현되어있기 때문에 내가 구현한 헤더의 Queue와 헷갈리지 않도록 네임스페이스를 넣었다. 
 // #include<queue>를 안하면 Queue는 내가 구현한 Queue.h헤더에 있는 Queue 클래스만 인식되기 때문에 사실 네임스페이스가 필요없지만 그냥 넣어봤다. 
namespace Que{
    class Queue{
        private:
            int* list;
            int front;
            int rear;
            bool isFull;
            bool isEmpty;
            
            void IsFull(){
                if(front == 0 && rear == MAXSIZE-2) isFull = true;
                else isFull = false;
            }
            void IsEmpty(){
                isEmpty = (front==rear)? true:false;
            }
        
        public:
            
            Queue(){
                list = new int[MAXSIZE];
                front = 0;
                rear = 0;
                isFull = false;
            }

            ~Queue(){
                delete[] list;
            }

            void Inqueue(int data){
                if(isFull){
                    cout << "Queue is Full!"<<endl<<endl;
                }
                else{
                    if(rear == 0 && !isEmpty){
                        list[rear] = data; 
                    }
                    else {
                        rear = (rear+1)%MAXSIZE;
                        list[rear] = data;
                    }
                    cout << "F:" << front << ", R: "<<rear<<endl;
                    cout << "Inqueue: " << list[rear] <<endl<<endl;

                }
                IsFull();
                IsEmpty();
            }

            void Dequeue(){
                if(!isEmpty){
                    cout << "F:" << front << ", R: "<<rear<<endl;
                    cout << "Dequeue: "<< list[front]<<endl<<endl;
                    front = (front+1)%MAXSIZE;
                }
                else{
                    cout << "No data! "<<endl<<endl;
                }
                IsFull();
                IsEmpty();
            }

            void ShowList(){
                int lastIndex;
                cout << "[Show List] " << endl;
                if(isEmpty){
                    cout << "No data!"<<endl<<endl;
                }
                else{
                    lastIndex = (front <= rear) ? rear: rear + MAXSIZE;
                    for(int i=front ; i<=lastIndex ; i++){
                        cout << list[i%MAXSIZE] << " / ";
                    }
                }
                cout << endl << endl;
            }            
            
    };
}