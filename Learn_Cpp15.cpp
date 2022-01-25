/*content
- 추상 클래스
1. 순수 가상 함수 (pure virtual function)
    가상함수는 파생 클래스에서 오버라이딩 할 것으로 기대하는 맴버 함수를 의미한다고 잎에서 배웠다.
    즉, 반드시 재정의 해야만 하는 함수가 아닌 재정의가 가능한 함수를 가리킨다.  
    
    이와 달리 순수 가상 함수는 파생 클래스에서 반드시 재정의해야만 하는 맴버 함수를 의미한다. 
    순수가상함수는 함수의 동작을 정의하는 본체를 가지고있지 않다.
    그러니까 파생 클래스에서 재정의 하지 않으면 사용이 불가능하다. 

    [선언] virtual 맴버함수원형 = 0; // 함수만 있고, 본체가 없다는 의미로  =0 을 추가해준다. 

2. 추상 클래스 
    하나 이상의 순수가상함수를 포함하는 클래스 = 추상 클래스(abstruct class)라고 한다. 
    추상클래스는 객체 지향 프로그래밍의 중요한 특징인 다형성을 가진 함수의 집합을 정의할 수 있게 해준다. 

    반드시 사용되야하는 맴버 함수를 추상 클래스 안에 넣어두면, 이 클래스를 상속하는 모든 파생 클래스들은 
    추상 클래스의 맴버 함수를 재정의 해야만 한다. 

*/  


#include <iostream>
using namespace std;

class Animal{
    public: 
        virtual ~Animal(){} 
        virtual void Cry() =0; // 순수가상함수 선언 
};

class Dog: public Animal{ // Dog가 Animal을 상속받았기 때문에 무조건 Cry를 재정의 해야한다. 
    public:
        virtual void Cry();
};

int main(){
    Dog d;
    d.Cry();
}

// 재정의한 순수가상함수 Animal
void Dog::Cry(){
    cout<< "멍멍"<<endl;
}