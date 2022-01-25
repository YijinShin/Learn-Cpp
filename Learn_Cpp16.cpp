/*content
- generic programming (일반화 프로그래밍)
    c++의 특징이다. 일반화 프로그래밍을 지원하는 기능이 바로 template이다. 
    객체 지향 프로그래밍은 데이터를 중시함
    일반화 프로그래밍은 알고리즘에 그 중점을 둔다 
- template
    탬플릿은 매개변수 타입에 따라 함수나 클래스를 생성하는 메커니즘을 의미한다. 
    탬플릿은 타입이 매개변수에 의해 표현됨 -> 매개변수화 타임(parameterized type)이라고 불림
    탬플릿을 사용하면 타입마다 별도의 함수나 클래스를 만들지 않고, 
    여러 타입에서 동작할 수 있는 단 하나의 함수나 클래스를 작성하는 것이 가능
        - 함수 탬플릿
        - 클래스 탬플릿
    
    함수 탬플릿
        명시적 특수화(explicit specialization)
        함수 탬플릿은 특정 타입에 대한 명시적 특수화를 제공하여, 해당 타입에 대해 특별한 동작을
        정의할 수 있게 해준다. 
        컴파일러는 호출된 함수에 대응하는 특수화된 정의를 발경하면, 더이상 탬플릿을 찾지 않고, 해당 정의를 사용한다.

        그러니까.. 예시로 작성한 Swap()은 지금 input을 어떤 타입을 넣어도 둘이 swap하는 동작을 한다. 
        여기서 내가 double타입에 한해서 값을 서로 바꾸지 않도록 명시적으로 정의하면 double 타입일때는 해당 
        특수한 정의를 실행한다. 
    
    클래스 탬플릿
        탬플릿의 일반화된 선언
        중첩 클래스 템플릿(nested class template) : 
        클래스나 템플릿내에 또 다른 템플릿을 중첩하여 정의할 수 있다. 이러한 템플릿을 멤버 템플릿(member template)이라고 한다. 
        맴버 템플릿중에서도 클래스 템플릿을 중첩 클래스 템플릿(nested class template)이라고 한다.
            선언은 상위 클래스의 범위 내에서 선언되고, 정의는 상위 클래스 밤위내 또는 그 밖에서도 가능하다.
*/


#include <iostream>
using namespace std;

//함수 탬플릿 선언(이렇게 두개가 한묶음인듯 )
template <typename T> // T = 타입이름
void Swap(T& a, T& b);//함수의 원형

template <> void Swap<double>(double&, double&); // 명시적 특수화 원형

//클래스 탬플릿 선언 
template  <typename C>
class Data{
    template  <typename D>
    class Inner{
        private:
            D idata_;
        public:
            Inner(D at);
            D get_data();
            void InnerFunc(){cout<<"Inner class"<<endl;}
    };
    private:
        C data_;
    public:
        Data(C dt);
        C get_data();
        void OuterFunc(){cout<<"Outer class"<<endl;}
};

int main(){
    //함수 탬플릿
    int c = 2, d =3;
    cout<<c<<","<<d<<endl;
    Swap(c,d);
    cout<<c<<","<<d<<endl;

    string str1 = "hi", str2 ="bye";
    cout<<str1<<","<<str2<<endl;
    Swap(str1,str2);
    cout<<str1<<","<<str2<<endl;

    double d1 = 0.5f, d2 =0.8f;
    cout<<d1<<","<<d2<<endl;
    Swap(d1,d2);
    cout<<d1<<","<<d2<<endl;

    //클래스 탬플릿
    Data<string> str_data("C++");
    Data<int> int_data(12);
    cout<<"str_data: "<< str_data.get_data()<<endl; 
    cout<<"int_data: "<< int_data.get_data()<<endl; 

    //nested class template
    Data<string> dt("this is outer");
    Data<int>::Inner<string> idt("this is inner");
    dt.OuterFunc();
    idt.InnerFunc();
    cout<<"Outer_data: "<< dt.get_data()<<endl; 
    cout<<"Inner_data: "<< idt.get_data()<<endl; 

    
    
}

//클래스 탬플릿
template <typename C>
Data<C>::Data(C dt){
    data_ = dt;
}

template <typename C>
C Data<C>::get_data(){
    return data_;
}


//함수 탬플릿 (탬플릿, 함수 이렇게 두개가 한묶음으로 함수탬플릿이다.)
template <typename T>
void Swap(T& a, T& b){ // 매개변수가 int인지 string인지는 여가서 정해지는 것이 아니라, 함수를 호출할 때 정해진다. 
    T temp;
    temp = a;
    a = b;
    b = temp;
}

//double 형을 위한 명시적 특수화 
template <> void Swap<double>(double&, double&){
    //  double형은 서로 값을 바꾸지 않음
}

//중첩 클래스 탬플릿내의 맴버 함수
template <typename C>
template <typename D>
Data<C>::Inner<D>::Inner(D dt){
    idata_ = dt;
    cout<<"Inner class"<<endl;
}

template <typename C>
template <typename D>
D Data<C>::Inner<D>::get_data(){
    return idata_;
}