#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 100

struct List{
    int nextIndex;
    int* arr;
};

class Stack{
    public:
        List* CreateList(){
            List* list;
            list->nextIndex = 0;
            list->arr = new int[MAXSIZE];
            return list;
        }

        void Push(List* list, int data){ 
            list->arr[list->nextIndex] = data;
            cout << "Push "<< list->arr[list->nextIndex] << endl << endl;       
            list->nextIndex ++;
        }

        void Pop(List* list){
            if(list->nextIndex == 0) cout << "No data in list" << endl << endl;
            else{
                cout << "Pop "<< list->arr[list->nextIndex - 1]<<endl<<endl;
                list->nextIndex --;
            }
        }

        void ShowList(List* list){
            cout << "[Show List] "  << list->nextIndex << endl;
            for(int i=0;i<list->nextIndex;i++){
                cout << list->arr[i] << " / ";
            }
            cout << endl << endl;
        }
};

