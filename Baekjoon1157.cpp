//start 1:03 - end: 1:25

#include <iostream>
using namespace std;

int main(){
    char maxCh;
    int maxCnt  = 0;
    int secondMaxCnt = 0;
    int alpaList[26] ={0};
    string str;
    int indx;

    getline(cin,str);

    for(int i=0; i<str.length(); i++){
        if(str[i] < 97) alpaList[str[i] - 'A']++;
        else alpaList[str[i] - 'a']++;
    }

    for(int i=0;i<26;i++){
        if(maxCnt <= alpaList[i]){
            secondMaxCnt = maxCnt;
            maxCnt = alpaList[i];   
            maxCh = toupper('A'+i);
        }
    }
    if(secondMaxCnt == maxCnt) cout << "?";
    else cout << maxCh;
}
