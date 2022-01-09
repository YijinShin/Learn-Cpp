/* content
- struct (구조체)
- union(공용체)
- enum(열거체)
*/

#include <iostream>
using namespace std;

//struct
struct s1{
    string name;
    string memo;
};
/*union
공용체는 구조체와 다 같은데 메모리 공간을 어떻게 쓰는지가 다르다. 
char, short, int 변수가 union안에 있으면 이들은 기본적으로 같은 값을 갖는다.*/
union u1{
    char a;
    short b;
    int c;
};
/*enum 
열거체는 새로운 타입을 선언하면서 동시에 그 타입이 가질 수 있는 상수값도 같이 명시. 주로 어떤 변수에 값(의미)를 부여하기 위해 사용*/
enum Weather{
    SUNNY = 0,
    CLOUD = 1,
    RAIN = 2
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

    //enum
    Weather w;
    int input;
    cout<<"(SUNNY=0, CLOUD=1, RAIN=2): ";
    cin >> input;
    w = (Weather)input;
    switch (w)
    {
    case SUNNY:
        cout<<"sunny"<<endl;
        break;
    case CLOUD:
        cout<<"cloud"<<endl;
        break;
    case RAIN:
        cout<<"rain"<<endl;
        break;
    default:
        break;
    }
    return 0;
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