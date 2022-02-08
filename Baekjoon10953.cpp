//start 10:43 ~ end 1-:49
#include <iostream>
using namespace std;

int main(){
    int caseNum;
    int a,b;
    char comma;
    
    cin >> caseNum;
    for(int i=0;i<caseNum;i++){
        cin >> a >> comma >> b;
        cout << a+b << endl;
    }
    return 0;
}