/*content  : friend, const,전방선언 

friend :Learn_Cpp10에서 잠깐 나왔음. 
    private 맴버는 public 맴버 함수를 통해서만 접근 가능한데, 매번 private에 접근할 수 있는 public 함수를 만드는 것은 아주 비효율적이다. 
    friend는 public 함수 없이 private 맴버에 접근할 수 있는 권한을 제공함. 
전역함수 / 클래스 / 맴버 함수 세가지 형태로 사용가능. 
1. 프렌드 함수 
선언 : friend className func (parameter);
friend는 함수 원형에 써야함

2. 프렌드 클래스
선언: friend class Display();
friend 키워드는 클래스 정의 부분에만 쓰면됨. 

+ 이항연산자 = 두개의 피 연산자와 하나의 연산자를 필요로 하는 연산을 말한다. ex +,1,/,... 그냥 대부분의 연산자를 말함 

const
1. const 변수 : 변수의 값을 바꿀 수 없게 한다.
    const int age; 
2. const 맴버 함수: class내의 맴버 함수를 const로 선언할 수 있다. 
    void func() const; // 키워드는 함수 원형에도, 선언에도 적어야함
    해당 함수가 호출되는 개체를 수정하지 않는 "읽기 전용" 함수임을 지정한다. 
    즉, 맴버 함수가 클래스 내의 맴버변수들을 읽어와서 쓰긴해도 수정하지 않는다. 
+ const를 함수 뒤에 붙이는 것은 맴버 함수에서만 사용가능하고, 전역에서 각 매개 변수들을 const로 하고싶으면 매개변수 앞에 붙여야한다. 
*/



#include <iostream>
#include <cmath>
using namespace std;



class Rect; // Display에서 Rect를 참조하기 때문에 전방선언을 해두는것. 
//지금 rect와 display가 서로 참조한다. 이걸 순환참조라고 한다. 여기서 Rect는 display내 맴버를 콕 찍어 참조하기 때문에 Display{}가 Rect{}보다 먼저 선언되어야한다. 
//따라서 Rect는 전방선언으로 일단! 이런 클래스가 있다 라고만 해두고 Display{}를 먼저 선언, 그 뒤에 Rect{}를 선언하는 것. 

class Display{
    public:
        void ShowSize(const Rect& rect);
        void ShowDiagonal(const Rect& rect);
};

class Rect{
    private:
        double height_;
        double width_;
    public:
        Rect(double height , double width); // 생성자  
        Rect operator*(double mul) const; // 맴버 연산자 함수 (오른쪽 피연산자)
        //기본적으로 맴버 함수는 왼쪽피연산자'가' '호출'하는 형태이기 때문에 피연산자의 위치가 고정되어야한다. 
        // rect*3 가능, 3*rect 불가능,  
        friend Rect operator*(const double mul,const Rect& rect); // 전역 연산자 함수 
        friend class Display; //Display는 Rect의 Private 변수에 접근할 수 있게 된다. 
        friend void Display::ShowDiagonal(const Rect& rect); // 특정클래스 안에서도 특정 맴버함수만 프랜즈 선언 가능. 
        /*문제는 이렇게 ShowDiagonal()함수를 콕 집어서 friend로 선언하려면 해당 함수가 먼저 선언되어있어야한다.
        따라서 
        1. class Rect; //  Display{}에서 Rect를 참조하기 때문에 Rect 클래스가 Display 클래스보다 앞에 선언되어야한다. 그래서 전방선언을 해두는 것
        2. class Display {}; // ShowDiagonal 함수 컴파일하고
        3. class Rect {}; // rect 컴파일. 
        이 순서대로 선언이 되어야한다. */
};



int main(){
    Rect rect1 = Rect(3.0,4.0);
    Rect rec3 =  rect1 * 3;
    Rect rec2 =  3 * rect1; //전역함수덕에 가능 

    Display rect_display;
    rect_display.ShowDiagonal(rec2);
    rect_display.ShowSize(rec2);
}

void Display::ShowSize(const Rect& rect){
    cout<< rect.width_ * rect.height_<<endl;
}

void Display::ShowDiagonal(const Rect& rect){
    cout<< sqrt(pow(rect.height_,2) + pow(rect.width_,2))<<endl;
}

Rect::Rect(double height, double width){
    height_ = height;
    width_ = width;
}
//맴버 함수로서의 연산자 함수 
Rect Rect::operator*(double mul) const{ // (오즌쪽 피연산자)
    //mul = 5; //이거 가능
    //height_ = 4;  // 이거 불가능. 그니까 const는 클래스 내 변수를 수정하는걸 막는거지 아무 변수 수정을 막는건 아니다. 
    return Rect(height_ * mul, width_ * mul);
}   

// 전역함수로서의 연산자 함수 
Rect operator*(const double mul, const Rect& rect){
    return Rect(mul*rect.height_, mul*rect.width_);
}