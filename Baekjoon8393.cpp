#include <iostream>
using namespace std;

int main(){
    int a; 
    int total = 0;

    cin >> a;
    for(int i=1;i<=a;i++){
        total += i;
    }
    cout << total <<endl;
    return 0;
}