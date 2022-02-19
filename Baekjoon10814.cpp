/*start 17:15 ~ end:17:50*/

#include <iostream>
using namespace std;
#define MAXSIZE 100000

struct User{
    int age;
    string name;
};

string toLower(string name);
char CompareName(string l_name , string r_name);
void MergeSort(User userList[] ,int start, int end);
void Merge(User userList[] ,int start, int mid, int end);

User sorted[MAXSIZE];

int main(){
    ios_base::sync_with_stdio(false);

    int userNum;
    cin >> userNum;

    User userList[userNum];
    for(int i;i<userNum;i++){
        cin >> userList[i].age >> userList[i].name;
    }

    MergeSort(userList, 0, userNum-1);

    for(int i=0;i<userNum;i++){
        cout << userList[i].age <<" "<<userList[i].name<<"\n";
    }

    return 0;
}


void MergeSort(User userList[] ,int start, int end){
    if(start >= end) return ;
    
    int mid = (start+end)/2;
    MergeSort(userList, start, mid);
    MergeSort(userList, mid+1, end);
    Merge(userList, start, mid, end);
}

void Merge(User userList[] ,int start, int mid, int end){
    int l = start;
    int r = mid+1;
    int index = start;
    while(l<=mid && r<=end){
        if(userList[l].age < userList[r].age){// l이 나이가 어리다. 
            sorted[index++] = userList[l++];
        }else if(userList[l].age == userList[r].age){//나이가 같다.
            //if(CompareName(userList[l].name, userList[r].name) == 'l'){
            if(l<r){ // l이 먼저  가입했다. 
                sorted[index++] = userList[l++];
            }else{ // r이 먼저 가입했다.
                sorted[index++] = userList[r++];
            }
        }else{// r이 나이가 어리다
            sorted[index++] = userList[r++];
        }
    }

    if(l>mid) for(int i=r;i<=end;i++) sorted[index++] = userList[i];
    else for(int i=l;i<=mid;i++) sorted[index++] = userList[i];

    for(int i=start;i<=end;i++) userList[i] = sorted[i];
}

char CompareName(string l_name , string r_name){
    int i = 0;
    while(1){
        if(tolower(l_name[i]) < tolower(r_name[i])) return 'l';
        else if (tolower(l_name[i]) > tolower(r_name[i])) return 'r';
        else i++;

        if(i >= l_name.length() && i < r_name.length()) return 'l';
        else if(i < l_name.length() && i >= r_name.length()) return 'r';
    }
}