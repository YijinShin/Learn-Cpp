#include <iostream>
using namespace std;
#define MAXSIZE 10

int* BubbleSort(int* arr);
void Temp(int* arr, int big, int small);

int main(){
    int* arr = new int(MAXSIZE);

    cout << "Enter 10 number: ";
    for(int i=0;i<MAXSIZE;i++){
        cin >> arr[i];
    }

    arr = BubbleSort(arr);

    for(int i=0;i<MAXSIZE;i++){
        cout << arr[i] << " . ";
    }
    cout << endl;
    return 0;
}

int* BubbleSort(int* arr){
    for(int i=0;i<MAXSIZE-1;i++){
        for(int j=0;j<MAXSIZE-i-1;j++){
            if(arr[j] > arr[j+1]) Temp(arr, j, j+1);
        }
    }
    return arr;
}

void Temp(int* arr, int big, int small){
    int temp = arr[big];
    arr[big] = arr[small];
    arr[small] = temp;
}