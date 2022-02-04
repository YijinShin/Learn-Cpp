//start 1:29 - end 1:48

#include <iostream>
using namespace std;

int main(){
    string str;
    int cnt = 0;

    getline(cin,str);
    for(int i=0;i<str.length();i++){
        if(str[i] == ' '){
            if(i != 0 && i != str.length()-1){
                cnt++;
            } 
        }
    }
    if(cnt == 0 && str.length()<2  && str[0] == ' ') cout << 0;
    else cout << cnt+1;

}
