#include <iostream>
using namespace std;

void QuickSort(int* arr, int start, int end);
void Swap(int* arr, int a, int b);

int main(){
    int arrSize;
    int* arr;

    cin >> arrSize;
    arr = new int(arrSize);

    for(int i=0;i<arrSize;i++){
        cin >> arr[i];
    }
    QuickSort(arr, 0, arrSize-1);
    cout << endl;
    for(int i=0;i<arrSize;i++){
        cout << arr[i]<<endl;
    }
    return 0;
}

void QuickSort(int* arr, int start, int end){
    if(start >= end) return;
    
    int pivot = start;
    int i = start+1;
    int j = end;

    while(i<=j){
        while(i <= end && arr[i] <= arr[pivot]) i++;
        while(j > start && arr[j] >= arr[pivot]) j--;
        if(i > j)Swap(arr, pivot, j);
        else Swap(arr, i, j);
    }
    QuickSort(arr, start, j-1);
    QuickSort(arr, j+1, end);
}   

void Swap(int* arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}