#include <iostream>
using namespace std;
#define MAXSIZE 10

//void MergeSort(int* arr, int* sortedArr, int left, int right);
//void Merge(int* arr, int* sortedArr, int left, int mid, int right);
void MergeSort(int* arr,  int left, int right);
void Merge(int* arr, int left, int mid, int right);

int sortedArr[MAXSIZE];

int main(){
    int* arr = new int(MAXSIZE);
    int* sortedArr = new int(MAXSIZE);
    cout << "Enter 10 number: ";
    for(int i=0;i<MAXSIZE;i++){
        cin >> arr[i];
    }  
    
    //MergeSort(arr, sortedArr, 0, MAXSIZE-1);
    MergeSort(arr, 0, MAXSIZE-1);

    for(int i=0;i<MAXSIZE;i++){
        cout << arr[i] << " . ";
    }
    cout << endl;
    return 0;
}

//void MergeSort(int* arr, int* sortedArr, int left, int right){
void MergeSort(int* arr, int left, int right){
    cout << "[left, right] : "<<left<<","<<right<<endl;
    int mid;
    if(left < right){
        mid = (right+left)/2;
        //MergeSort(arr, sortedArr, left, mid); // 좌
        //MergeSort(arr, sortedArr, mid+1, right); // 우 
        //Merge(arr, sortedArr, left, mid, right);
        MergeSort(arr, left, mid); // 좌
        MergeSort(arr, mid+1, right); // 우 
        Merge(arr,left, mid, right);
    }
    cout<<endl<<endl;
}   

//void Merge(int* arr, int* sortedArr, int left, int mid, int right){
void Merge(int* arr, int left, int mid, int right){
    int l = left;
    int r = mid+1;
    int index = left;

    // 좌, 우 대소비교 해서 넣기 
    while(l <= mid && r <= right){
        sortedArr[index++] = (arr[l] <= arr[r]) ? arr[l++] : arr[r++];
    }

    //남은 data 마저 넣기 
    if(l>mid){
        for(int i=r;i<=right;i++) sortedArr[index++] = arr[i];    
    }
    else{
        for(int i=l;i<=mid;i++) sortedArr[index++] = arr[i];
    }
    cout<<"b arr:";
    for(int i=0;i<=9;i++) cout << arr[i]<<",";
    cout<<endl;

    // 정렬한 부분 리스트를 원래 배열에 복사하기 
    for(int i=left;i<=right;i++) arr[i] = sortedArr[i];

    cout<<"a arr:";
    for(int i=0;i<=9;i++) cout << arr[i]<<",";
    cout << endl;
}
