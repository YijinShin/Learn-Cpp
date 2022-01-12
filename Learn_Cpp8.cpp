/*OOP 특징
1. 추상화(abstraction)
2. 캡슐화(encapsulation)
3. 정보 은닉(data hiding) > 접근제어지시자(private, public)을 통해 가능
    - public : 같은 패키지, 다른 패키지 모두 접근 가능 
    - private : 다른 패키지 접근 불가, 같은 패키지라도 해당 변수가 속한 클래스 외에서는 접근 불가 
    - protected : 다른 패키지 접근 불가, 같은 패키지면 가능. 
4. 상속성(inheritance)
5. 다형성(polymorphism)*/

#include <iostream>
using namespace std;

//class 정의 
class Cat{
    //접근제어지시자
    private:
        //맴버변수 타입, 이름
        int kg;
        //맴버함수 원형
    public:
        string name;
        int age;
        void Display(){cout<<"this is cat"<<endl;}
        Cat& ReturnIns(){return *this;} // 자신을 호출한 인스턴스를 반환함. 
};


int main(){
    Cat cat1;
    cat1.age = 2;
    cat1.Display(); 
    Cat result = cat1.ReturnIns();
    cout<< result.age << endl;
    
    return  0;
}