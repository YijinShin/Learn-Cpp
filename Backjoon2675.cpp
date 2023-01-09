
#include <iostream>
#include <string>
using namespace std;
/* 
struct Case{
    int R;
    char str[20];
};


int main(){
    int T;
    Case* caseList;
    int y=0;

    // test case num
    cin >> T;
    cin.ignore();
    caseList = new Case[T];

    for(int i=0;i<T;i++){
        cin >> caseList[i].R;
        cin.ignore();
        cin.getline(caseList[i].str, 22);        
    }

    for(int i=0;i<T;i++){
        while( caseList[i].str[y] != '\0'){
            for(int j=0; j<caseList[i].R; j++){
                cout << caseList[i].str[y];
            }
            y++;
        }
        cout<<endl;
        y = 0;
    }

    delete caseList;
    return 0;
}
*/

int main(){
    int T;
    int R;
    string str;

    cin >> T;
    cin.ignore();
    for(int i=0;i<T;i++){
        cin >> R;
        cin.ignore();
        getline(cin, str);

        for(int j=0;j<str.length();j++){
            for(int k=0;k<R;k++){
                cout<<str[j];
            }
        }
        cout<<endl;
    }
}