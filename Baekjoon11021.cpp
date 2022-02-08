// start 10:52 ~ 

#include <iostream>
using namespace std;

int main(){
    int caseNum,a,b;
    cin >> caseNum;
    for(int i=0;i<caseNum;i++){
        cin >> a >> b;
        cout << "Case #"<<i+1<<": "<< a+b << endl;
    }
    return 0;
}