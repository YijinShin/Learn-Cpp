/*content
class template
    - 하나 이상의 템플릿 인수 가질 수 있음
    - 클래스 템플릿에 디폴트 템플릿 인수 명시 가능
    - 클래스 템플릿을 기초 클래스로 해서 상속 가능 
        일반 클래스가 파생클래스가 되어 템플릿 베이스 클래스 상속받기 가능
        템플릿 베이스 클래스가 파생클래스가 되어 또 다른 템플릿 베이스 클래스 상속받기 가능 
*/

#include <iostream>
using namespace std;

// 1. 하나 이상의 템플릿 인수 가지는 클래스 템플릿 
template <typename A, typename B> 
class FirstClass{
    private:
        A a_;
        B b_;
    public:
        FirstClass(A a, B b);
        void ShowFirstData();
};

// 2. 디폴트 템플릿 인수 명시 가능
template <typename C, typename D =int> //이거 디폴트 매개변수를 쓰려면 순서를끝에 둬야하는듯..
class SecondClass{
    private:
        D d_;
        C c_;
    public:
        SecondClass(C c,D d);
        void ShowSecondData();
};

template <typename E, typename A, typename B>
class ThirdClass: public FirstClass<A,B>{
    private:
        E  e_;
    public:
        ThirdClass(E e, A a, B b);
        void ShowThirdData();
};



int main(){
    ThirdClass<string, string, int> tc("third data", "first data", 12); // 이렇게 하면 객체 생성 (FirstClass 생성자, ThridClass 생성자 )실행됨. 
    tc.ShowFirstData();
    tc.ShowThirdData();
}

//First class
template <typename A, typename B>
FirstClass<A,B>:: FirstClass(A a, B b){
    a_ = a;
    b_ = b;
}

template <typename A, typename B>
void FirstClass<A,B>::ShowFirstData(){
    cout<<"A:"<< a_<<", B:"<<b_<<endl;
}

//Second class
template <typename C, typename D> // 여기서는 디폴트 명시해줄 필요 없나봐
SecondClass<C,D>:: SecondClass(C c, D d){
    c_ = c;
    d_ = d;
}

//Third class
template <typename E, typename A, typename B>
ThirdClass<E, A, B>:: ThirdClass(E e, A a, B b): FirstClass<A,B> (a,b){
    e_ = e;
}

template <typename E, typename A, typename B>
void ThirdClass<E, A, B>:: ShowThirdData(){
    //ShowFirstData(); //여기서 부모 클래스 맴버 함수 부르는게 안되네..?? 
    cout<<"E:"<< e_<<endl;
}