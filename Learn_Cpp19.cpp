/*표준 입력 함수 
cin / cin.getlint() / getline() / cin.get()
char = 1 / int,long = 4, 
*/

#include <iostream>
using namespace std;

int main(){
   int num[5];
   fill_n(num,3,1);
   for(int i=0;i<5;i++) cout<<num[i]<<" / ";
}