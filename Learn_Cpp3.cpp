/* content
- struct (구조체)
- union(공용체)
*/

#include <iostream>
using namespace std;

//struct
struct s1{
    string name;
    string memo;
};
s1  ReturnUserInfo();
void PrintUserInfo(const s1* user);

int main(){
    //구조체 참조. struct에서는 . 로 element 참조, struct pointer에서는 -> 로 참조
    s1 user = {"Ban","9:00 work"};
    cout << user.name <<","<<user.memo<<endl;
    PrintUserInfo(&user);
    user = ReturnUserInfo();
    cout << user.name <<","<<user.memo<<endl;
}

//함수에서 구조체 받기 
void PrintUserInfo(const s1* user){
    cout << user->name <<","<<user->memo<<endl;
}
//함수에서 구조체 리턴
s1  ReturnUserInfo(){
    s1 user = {"Mike", "11:20 work"};
    return user;
}