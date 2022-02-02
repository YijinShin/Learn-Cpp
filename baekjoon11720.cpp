// start 3:36 - end 4:14
#include <iostream>
using namespace std;

int main(){
    int cnt;
    int cs;
    int total = 0;

    cin >> cnt;
    char num[cnt];    
    cin.ignore();
    cin.getline(num, cnt+1);
    for(int i=0;i<cnt;i++){
        total += num[i] -'0';
    }
    
    cout<<total;

}
