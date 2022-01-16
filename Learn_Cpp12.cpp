/*content: static member variable*/

/*static member는 클래스에는 속하지만, 객체별로 할당되지 않고, 같은 클래스객체가 모두 공유하는 맴버이다. 
접근은 private, public에 따라 결정됨

 - static: 같은 클래스 객체들이 공유함. 변경 가능. 
 - const : 값(데이터) 변경이 불가능함

*/


#include <iostream>
using namespace std;

class User{
    private:
        static int userCount; // 정적 맴버 변수 선언
        string Name;
    public:     
        User(const string& name); // 생성자 
        ~User(){userCount--;} // 소멸자
        void Display();
        static int returnUserCount(); // 정적 맴버 함수 선언
};
int User::userCount = 0; //정적 맴버 변수 초기화

int User::returnUserCount(){ // 정적 맴버 함수 정의
    return userCount;
}

int main(){
    User u1 = User("A");
    u1.Display();
    User u2 = User("B");
    u2.Display();
    // u1의 userCount와 u2의 userCount는 공유된다. 

    int currUser = User::returnUserCount(); // 정적 맴버 함수의 경우 클래스명.함수이름()으로 호출한다. 

}


User::User(const  string& name){
    Name = name;
    userCount++;
}

void User::Display(){
    cout<<Name<<"님이 들어왔습니다. 현재 "<<userCount<<"명이 접속중입니다."<<endl;
}