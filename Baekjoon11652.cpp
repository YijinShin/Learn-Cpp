#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 100000
long long sorted[MAXSIZE];

//void Merge(long long* cards, int start, int mid, int end);
//void MergeSort(long long* cards, int start, int end);
int FindMaxCount(long long* cards, int size);

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int size;
    cin >> size;
    long long* cards = new long long[size];

    for(int i=0;i<size;i++)
        cin >> cards[i];

    //MergeSort(cards, 0, size-1);
    sort(cards, cards+size);
    int maxNum = FindMaxCount(cards, size);

    cout << maxNum;
    return 0;
}

int FindMaxCount(long long* cards, int size){
    int maxNum = cards[0];
    int max=0;
    int cnt = 0;
    for(int i=1;i<size;i++){
        if(cards[i] == cards[i-1]){
            cnt ++;
            if(max < cnt){
                max = cnt;
                maxNum = cards[i];
            }
        }else{
            cnt = 0;
        }
    }
    return maxNum;
}
/*
void Merge(long long* cards, int start, int mid, int end){
    int l = start;
    int r = mid+1;
    int sortedlist_index = start;

    while(l<=mid && r<=end){
        if(cards[l] > cards[r]){
            sorted[sortedlist_index++] = cards[r++];
        }
        else{
            sorted[sortedlist_index++] = cards[l++];
        } 
    }

    if(l>mid){
        sorted[sortedlist_index++] = cards[r++];
    }else{
        sorted[sortedlist_index++] = cards[l++];
    }

    for(int i=start;i<=end;i++) cards[i] = sorted[i];
}

void MergeSort(long long* cards, int start, int end){
    if(start >= end) return;
    int mid = (start+end)/2;
    
    MergeSort(cards, start, mid);
    MergeSort(cards, mid+1, end);
    Merge(cards, start, mid, end);
}   
*/