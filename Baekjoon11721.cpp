#include <iostream>
using namespace std;

int main(){
    string str;
    int j=0;

    getline(cin,str);
    for(int i=0;i<str.length();i++){
        cout << str[i];
        if((i+1)%10 == 0) cout << endl;
    }
    return 0;
}
