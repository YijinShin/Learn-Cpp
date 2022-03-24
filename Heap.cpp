#include <iostream>
using namespace std;
#define MAXSIZE 100

// Max heap

int ShowMenu();
void swap(int* heap,int current, int other);
int Pop(int* heap, int heapsize);
int Push(int* heap, int data,  int heapsize);
void Heapify(int* heap, int heapsize);
void ShowHeap(int * heap, int heapsize);


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
            heapSize = Pop(heap, heapSize);
            
        }
        else if(menu == 3){
            ShowHeap(heap, heapSize);
        }
        else if(menu == 4) {
            Heapify(heap, heapSize);
            ShowHeap(heap, heapSize);
        }
        else if(menu == 5) break;
    }
    return 0;  
}

int Push(int* heap, int data,  int heapsize){
    // 마지막 노드에 데이터 넣기 
    int size = heapsize + 1; 
    heap[size] = data;

    int current = size;
    int parent = current/2;
    
    while(parent >= 1){
        if(heap[current] > heap[parent]){
            swap(heap, current, parent);
            current = parent;
            parent = current/2;
        }
        else break;   
    }

    ShowHeap(heap, size);
    cout << endl;

    return size;
}

int Pop(int* heap, int heapsize){
    // root data pop
    int rootData = heap[1];
    cout << "Pop: " << rootData << endl;
    swap(heap, 1, heapsize);
    int size = heapsize - 1; 
    
    int current = 1;
    int child =  current*2;
    // 주의: pop 할때는 heapify처럼 양쪽 child 중 큰쪽과 바꿔야함.
    if(child+1 <=size) child = (heap[child+1] > heap[child])? child+1:child;
    while(child <= size){
        if(heap[current] < heap[child]){
            swap(heap, current, child);
            current = child;
            child = current *2;
            if(child+1 <=size) child = (heap[child+1] > heap[child])? child+1:child;
        }
        else break;
    }
    ShowHeap(heap, size);
    cout << endl;

    return size;
}

void Heapify(int* heap, int heapsize){
    int current = 1;
    int child = current*2;
    int last = heapsize;

    //last == root일때까지 반복
    while(last > 1){
        //swap(root, last)
        current = 1;
        child = current*2;
        swap(heap, 1, last);
        last --;
        //sort
        while(child <= last){
            //더 큰 child 정하기 
            if(child+1 <= last) child = (heap[child+1] > heap[child])? child+1:child;
            // 비교하기
            if(heap[child] > heap[current]){
                // swap
                swap(heap, current, child);
                // current, chilld 갱신
                current = child;
                child = current*2;
            }
            else break;
        }
        ShowHeap(heap, heapsize);
    }

}

int ShowMenu(){
    int menu;
    cout << "1. Insert" << endl << "2. Delete" << endl << "3. Show List" << endl << "4. Heapify" << endl << "5. Quit" << endl << "menu: ";
    cin >> menu;
    cout << endl;
    return menu;
}

void swap(int* heap,int current, int other){
    int t = heap[current];
    heap[current] = heap[other];
    heap[other] = t;
}

void ShowHeap(int * heap, int heapsize){
    cout << "Heap: ";
    for(int i=1;i<=heapsize;i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}