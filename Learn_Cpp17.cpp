/*content
class template
    - 하나 이상의 템플릿 인수 가질 수 있음
    - 클래스 템플릿에 디폴트 템플릿 인수 명시 가능
    - 클래스 템플릿을 기초 클래스로 해서 상속 가능 
        일반 클래스가 파생클래스가 되어 템플릿 베이스 클래스 상속받기 가능
        템플릿 베이스 클래스가 파생클래스가 되어 또 다른 템플릿 베이스 클래스 상속받기 가능 
    
    - 클래스 템플릿의 명시적 특수화
        - 모든 매개변수를 특수화 할 수 있고
        - 일부 매개변수만 특수화 할 수 있다
        - C++11부터 템플릿 특수화를 위한 새로운 이름 붙일 수 있다. 


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
//4. 클래스 함수 명시적 특수화 <double, double 한에서> // 이거는 모든 템플릿 매개변수들에 대해 특수화 한 경우 
template <> class FirstClass<double, double>{
    private:
        double a_;
        double b_;
    public:
        FirstClass(double a, double b){a_ = a; b_ = b;}
        double get_data(){ return a_+b_;}
};
// 위에서 한 명시적 특수화에 이름을 붙인것 
typedef FirstClass<double, double> DoubleFirstClass;

//5. 부분 특수화(partial specialization) A,B중에서 B에대해서 double인 경우 특수화 
template <typename A> class FirstClass<A, double>{
    public:
        FirstClass(A a, double b){cout<<"partial specialization"<<endl;}
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

    // 전부 명시적 특수화 
    FirstClass<double, double> fc(1.1,1.4);
    cout<<"double double: "<<fc.get_data()<<endl;

    // 부분 특수화
    FirstClass<string, double> fc_partial("partial", 1.3);
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