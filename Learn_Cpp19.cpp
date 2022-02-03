/*표준 입력 함수 
cin / cin.getlint() / getline() / cin.get()
char = 1 / int,long = 4, 
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    int numArr[5];
    int *numPo = new int[5];

    char ch;
    char chArr[5]; 
    char *chPo = new char[10];
    string str;

    // cin
    //getline(cin, str, 'a');
    cout <<"input a: ";
    cin >> n;
    if(cin.fail() == 1){
        printf("error\n");
        cin.clear();
        cin.ignore();
    }
    cout <<"input ch: ";
    cin >> ch;

    cout << "a: "<<n<<endl;
    cout << "ch: "<<ch<<endl;

}