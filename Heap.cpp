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
            cout << endl << "Delete data: ";
            cin >> data;
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
    int current = size;
    int parent = size/2;
    heap[size] = data;
    
    while(parent >= 1){
        if(heap[current] > heap[parent]){
            swap(heap, current, parent);
            current = parent;
            parent = current/2;
        }
        else break;   
    }
    // heapify 
    //Heapify(heap, heapsize);
    ShowHeap(heap, size);
    cout << endl;

    return size;
}

int Pop(int* heap, int heapsize){
    // root data pop
    int current = 1;
    int child =  current*2;

    int rootData = heap[1];
    cout << "Pop: " << rootData << endl;
    swap(heap, 1, heapsize);
    int size = heapsize - 1; 
    
    while(child <= heapsize){
        if(heap[current] < heap[child]){
            swap(heap, current, child);
            current = child;
            child = current *2;
        }
    }

    // heapify 
    //Heapify(heap, heapsize);
    ShowHeap(heap, size);
    cout << endl;

    return size;
}

void Heapify(int* heap, int heapsize){
    int size = heapsize;
    int current = 1;
    int l_child = current * 2;
    int r_child = current * 2 + 1;
    int swap_child = current;

    while(size != 0){ // O(n)
        // swap root and last node 
        current = 1;
        swap(heap, current, heapsize);
        size --;
        // last node 제외하고 정렬
        while(l_child <= heapsize){// O(lgn)
            // root 를 조건에 맞는 자녀와 바꾸기 
            if(heap[r_child] > heap[current]){
                swap(heap, current, r_child);
                swap_child = l_child;
            }
            if(heap[l_child] > heap[current]){
                swap(heap, current, l_child);
                swap_child = r_child;
            }
            cout << "Change : "<<current <<","<<swap_child<<endl; 

            if(swap_child == current) break;
            current = swap_child;
            l_child = current * 2;
            r_child = current * 2 + 1;
        }
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