/*start10:14*/
#include <iostream>
using namespace std;

int sorted[10000000];

void MergeSort(int list[], int start, int end);
void Merge(int list[], int start, int mid, int end);
int main(){
    ios_base::sync_with_stdio(false);
    int numCnt;
    cin >> numCnt;
    int list[numCnt];

    for(int i=0;i<numCnt;i++){
        cin >> list[i];
    }
    cout<<endl;
    
    MergeSort(list, 0, numCnt-1);

    for(int i=0;i<numCnt;i++){
        cout << list[i]<<"\n";
    }
    return 0;
}

void MergeSort(int list[], int start, int end){
    if(start>=end) return;

    int mid = (start+end)/2;
    MergeSort(list, start, mid);
    MergeSort(list, mid+1, end);
    Merge(list, start, mid, end);
}

void Merge(int list[], int start, int mid, int end){
    int l = start;
    int r = mid+1;
    int index = start;

    while(l<=mid && r<=end){
        if(list[l]<list[r]){
            sorted[index++] = list[l++];
        }else{
            sorted[index++] = list[r++];
        }
    }

    if(l>mid){
        for(int i=r;i<=end;i++) sorted[index++] = list[i];
    }else{
        for(int i=l;i<=mid;i++) sorted[index++] = list[i];
    }

    for(int i =start;i<=end;i++) list[i] = sorted[i];
}