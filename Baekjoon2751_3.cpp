#include <iostream>
using namespace std;
#define MAXSIZE 1000000

void MergeSort(int* arr, int start, int end);
void Merge(int* arr, int start, int mid, int end);
int sorted[MAXSIZE];
  

int main(void){
    ios_base::sync_with_stdio(false); 
    //cin.tie(null); 

    int arrSize;
    int* arr;

    std::cin >> arrSize;
    arr = new int[arrSize];

    for(int i=0;i<arrSize;i++){
        std::cin >> arr[i];
    }

    MergeSort(arr, 0, arrSize-1);

    for(int i=0;i<arrSize;i++){
        cout << arr[i]<<"\n"; // endl 보다 '\n'이 빠르다. 
    }

    delete[] arr;
    return 0;
}


void Merge(int* arr, int start, int mid, int end){
    int l = start;
    int r = mid+1;
    int index = start;

    while(l<=mid && r<=end){
        sorted[index++] = (arr[l] <= arr[r])? arr[l++]:arr[r++];
    }

    if(r<=end){
        for(int i=r; i<=end; i++) sorted[index++] = arr[i];
    }else if(l<=mid){
        for(int i=l; i<=mid; i++) sorted[index++] = arr[i];
    }

    for(int i=start;i<=end;i++) arr[i] = sorted[i];    
}

void MergeSort(int* arr, int start, int end){
    if(start >= end) return;
    
    int mid = (start+end)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, start, mid, end);
} 

