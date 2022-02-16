#include <iostream>
//using namespace std;
#define MAXSIZE 1000000

//void MergeSort(int* arr, int start, int end);
//void Merge(int* arr, int start, int mid, int end);
//void MergeSort(int arr[], int start, int end);
//void Merge(int arr[], int start, int mid, int end);
int sorted[1000000];

//void Merge(int* arr, int start, int mid, int end){
void Merge(int arr[], int start, int mid, int end){
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

//void MergeSort(int* arr, int start, int end){
void MergeSort(int arr[], int start, int end){
    if(start >= end) return;
    
    int mid = (start+end)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, start, mid, end);
}   

int main(void){
    std::ios_base::sync_with_stdio(false); // 알고리즘 실행속도를 높이기 위해 쓰는 구문
    cin.tie(null); // https://jaimemin.tistory.com/1521
    int arrSize;
    //int* arr;

    std::cin >> arrSize;
    //arr = new int[arrSize];
    int arr[arrSize];

    for(int i=0;i<arrSize;i++){
        std::cin >> arr[i];
    }

    MergeSort(arr, 0, arrSize-1);

    //for(int i=0;i<arrSize;i++){
    for(auto i: arr){
        std::cout << i<<'\n';
    }

    //delete[] arr;
    return 0;
}

// endl 대신 \n 사용, merge에 조건문없앰 : 720ms
// arr 동적할당 안하고 그냥 배열로 사용 : 712ms
// namespace 사용안하고 그냥 배열로 사용 : 716ms
// 함수 선언 위치 바꾸기 : 720ms
// 결과 출력에 for(auto i: arr){} 사용 : 700ms
// std::ios_base::sync_with_stdio(false); 사용 : 336ms 이거다!! 
