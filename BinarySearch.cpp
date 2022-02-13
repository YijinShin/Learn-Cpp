#include <iostream>
using namespace std;
#define MAXSIZE 6

int BinarySearch(int list[], int target);
int BinarySearch_re(int list[], int target, int start, int end);

int main(){
    int list[] = {9,10,22,27,30,60};
    int target;
    int index;

    cout << "Ender number 0~9: ";
    cin >> target;

    //index = BinarySearch(list, target);
    index = BinarySearch_re(list, target, 0, MAXSIZE-1);
    cout << target <<" is in index " <<index << endl;
    return 0;
}
// 반복문
int BinarySearch(int list[], int target){
    int middle = (MAXSIZE)/2;
    int start = 0;
    int end = MAXSIZE - 1;

    while(start<=end){
        if(list[middle] == target) return middle;
        else if(list[middle] > target) end = middle - 1;
        else if(list[middle] < target) start = middle + 1;
        middle = (start+end)/2;
    }
    cout << start <<", "<<middle <<","<<end<<endl;
    return -1;
}

int BinarySearch_re(int list[], int target, int start, int end){
    int index;
    if(start > end) return -1;
    int middle = (start+end)/2;

    if(list[middle] == target) return middle;
    else if(list[middle] > target) index = BinarySearch_re(list, target, start, middle-1); 
    else if(list[middle] < target) index = BinarySearch_re(list, target, middle+1, end);
    return index;
}