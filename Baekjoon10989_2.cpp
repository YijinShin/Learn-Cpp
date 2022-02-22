#include <iostream>
using namespace std;
#define MAXNUM 10000

int sorted[MAXNUM];


int main(){
    ios_base::sync_with_stdio(false);
    int numCnt,input;
    cin >> numCnt;

    for(int i=0;i<numCnt;i++){
        cin >> input;
        sorted[input-1]++;
    }

    for(int i=0;i<MAXNUM;i++){
        for(int j=0;j<sorted[i];j++){
            cout << i+1<<"\n";
        }
        
    }
  
    return 0;
}
