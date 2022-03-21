#include <iostream>
#include "Heap.h"
using namespace std;

//MAX heap

int ShowMenu();
int swap(int* heap,int current, int other);
int Pop(int* heap, int heapsize);
int Push(int* heap, int data,  int heapsize);


int main(){
    int heap[MAXSIZE];
    int data;
    int menu;
    int heapSize = 0;
    
    while(true){
        menu = ShowMenu();

        if(menu == 1){
            cout << endl << "Insert data: ";
            cin >> data;
            heapSize = Push(heap, data, heapSize);
        }
        else if(menu == 2){
            cout << endl << "Delete data: ";
            cin >> data;
            heapSize = Pop(heap, heapSize);
            
        }
        else if(menu == 3){}
        else if(menu == 4) break;
    }
    return 0;  
}

int Push(int* heap, int data,  int heapsize){
    int size = heapsize + 1; 
    int current = size;
    int parent = size/2;

    heap[heapsize] = data;
    while(parent < 1){
        if(heap[current] > heap[parent]){
            swap(heap, current, parent);
            current = parent;
            parent = current/2;
        }
    }

    return size;
}

int Pop(int* heap, int heapsize){
    // root data pop
    int rootData = heap[1];
    swap(heap, 1, heapsize);
    
    int size = heapsize - 1; 
    int current = size;
    int child = current

}

int ShowMenu(){
    int menu;
    cout << "1. Insert" << endl << "2. Delete" << endl << "3. Show List" << endl << "4. Quit" << endl << "menu: ";
    cin >> menu;
    cout << endl;
    return menu;
}

int swap(int* heap,int current, int other){
    int t = current;
    heap[current] = heap[other];
    heap[other] = t;
}