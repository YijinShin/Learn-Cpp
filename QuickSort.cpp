#include <iostream>
using namespace std;
#define MAXSIZE 10

void QuickSort(int* arr, int start, int end);
void Swap(int* arr, int big, int small);

int main(){
    int* arr = new int(MAXSIZE);

    cout << "Enter 10 number: ";
    for(int i=0;i<MAXSIZE;i++){
        cin >> arr[i];
    }  
    
    QuickSort(arr,0,MAXSIZE-1);

    cout<<endl << "sortted!"<<endl;
    for(int i=0;i<MAXSIZE;i++){
        cout << arr[i] << " . ";
    }
    cout << endl;
    return 0;
}

void QuickSort(int* arr, int start, int end){
    int pivot = start;
    int i = start+1;
    int j = end;
    
    if(start >= end) return; //배열 길이가 1인경우 
    
    while(i <= j){
        while( i <= end  && arr[i] <= arr[pivot]){ i++;}
        while( j > start && arr[j] >= arr[pivot]) { j--;}
        if(i > j){
            Swap(arr,j,pivot);
            cout << "(i,j):"<<i<<","<<j<<endl;
            cout << "pivot swap:";
            for(int k=start;k<=end;k++) cout << arr[k]<<" . "; 
            cout<<endl;
        }
        else Swap(arr,i,j);
    }
    
    QuickSort(arr, start, j-1);
    QuickSort(arr, j+1, end);
}   

void Swap(int* arr, int big, int small){
    int temp = arr[big];
    arr[big] = arr[small];
    arr[small] = temp;
}