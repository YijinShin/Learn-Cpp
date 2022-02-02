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
    char *chPo = new char[5];
    string str;

    //sizeof는 바이트 단위 
    cout <<  "chArr size: "<<sizeof(chArr)<<endl; 
    cout <<  "numArr size: "<<sizeof(numArr)<<endl;

    // cin
    cin >> n; cout << "n: " << n << endl;
    // cin >> numArr; cout << numArr << endl; int 배열은 cin>>으로 입력받을 수 없다. 
    cin >> ch; cout << "ch: " << ch << endl;
    cin >> chArr; cout <<"chArr: " <<  chArr << endl;
    for(int i=0;i<10;i++) cout<<  "chArr" <<"["<<i<<"] : "<< chArr[i]<<endl;


    cin >> chPo; cout << "chPo: " << chPo << endl;
    cin >> str; cout << "str: " << str << endl;

}