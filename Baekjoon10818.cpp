#include <iostream>
using namespace std;

int main(){
    int numCnt, max, min;
    int *num;

    cin >> numCnt;
    num = new int[numCnt];

    for(int i=0;i<numCnt;i++){
        cin >> num[i];
    }

    min = num[0];
    max = num[0];
    for(int i=0;i<numCnt;i++){
        if(max < num[i]) max = num[i];
        if(min > num[i]) min = num[i];
    }
    cout << min << " " << max << endl;

    delete[] num; // 동적할당을 array로 했으니 delete도 array 
    return 0;
}