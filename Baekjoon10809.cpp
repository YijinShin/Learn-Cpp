//start 8:21 - end: 8:53
/*소문자로만 이루어진 단어 s가 주어진다. 
각 알파벳에대해서 단어에포함되어있는 경우에는 처음 등장하는 위치, 포함되어있지 않으면 -1 출력 */
#include <iostream>
using namespace std;

void Calc(char *str);

int main(){
    char str[100];
    cin.getline(str, 101);

    Calc(str);
}

void Calc(char *str){
    int alpa[26]; // false 초기값  
    for(int i=0;i<26;i++) alpa[i] = -1; 
    int j=0;

    for(int i=0;i<26;i++){
        while(str[j] != '\0'){            
            // 문자가 같으면 
            if((int)str[j] == 'a'+i){ 
                if(alpa[i] == -1){
                    alpa[i] = j; 
                } 
            }
            j++;
        }
        j = 0;   
        cout << alpa[i]<<" ";
    }

}   