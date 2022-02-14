#include <iostream>
using namespace std;
#define MAXSIZE 10

int* InsertionSort(int* arr);
void Swap(int* arr, int big, int small);

int main(){
    int* arr = new int(MAXSIZE);

    cout << "Enter 10 number: ";
    for(int i=0;i<MAXSIZE;i++){
        cin >> arr[i];
    }  

    arr = InsertionSort(arr);

    for(int i=0;i<MAXSIZE;i++){
        cout << arr[i] << " . ";
    }
    cout << endl;
    return 0;
}

int* InsertionSort(int* arr){
    for(int i=1;i<MAXSIZE;i++){
        for(int j=i;j>=1;j--){
            if(arr[j] < arr[j-1]) Swap(arr, j, j-1);
        }
    }
    return arr;
}   

void Swap(int* arr, int big, int small){
    int temp = arr[big];
    arr[big] = arr[small];
    arr[small] = temp;
}