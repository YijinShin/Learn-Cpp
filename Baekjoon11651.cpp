#include <iostream>
using namespace std;
#define MAXSIZE 100000

struct Point{
    int x;
    int y;
};

void MergeSorting(Point* list, int start, int end);
void Merge(Point* list, int start, int mid, int end);

Point sorted[MAXSIZE];

int main(){
    ios_base::sync_with_stdio(false);
    
    int pointCnt;
    cin >> pointCnt;
    Point* list = new Point[pointCnt];

    // 좌표 입력
    for(int i=0;i<pointCnt;i++){
        cin >> list[i].x >> list[i].y;
    }

    // 정렬
    MergeSorting(list, 0, pointCnt-1);

    // 결과 출력
    for(int i=0;i<pointCnt;i++){
        cout << list[i].x << " "<< list[i].y<<"\n";
    }

    delete[] list;
    return 0;
}

void MergeSorting(Point* list, int start, int end){
    if(start >= end) return;

    int mid = (start+end)/2;
    MergeSorting(list, start, mid);
    MergeSorting(list, mid+1, end);
    Merge(list, start, mid, end);
}   

void Merge(Point* list, int start, int mid, int end){
    int l = start;
    int r = mid+1;
    int index = start;

    while(l<=mid && r<=end){
        if(list[l].y < list[r].y){
            sorted[index++] = list[l++];
        }else if(list[l].y == list[r].y){
            if(list[l].x < list[r].x) sorted[index++] = list[l++];
            else sorted[index++] = list[r++];
        }else sorted[index++] = list[r++];
    }
    if(l>mid){
        for(int i=r;i<=end;i++) sorted[index++] = list[i];
    }else{
        for(int i=l;i<=mid;i++) sorted[index++] = list[i];
    }

    for(int i=start;i<=end;i++) list[i] = sorted[i];
}
