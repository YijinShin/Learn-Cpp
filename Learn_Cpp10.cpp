/*operator overloading(연산자 오버로딩)
 함수를 매개변수의 형식을 조금씩 달리해서, 하나의 이름으로 작성할 수 있게 해주는 것 
 
 연산자 함수 문법
 operator[오버로딩 할 연산자] (매개변수) //operator에 오버로딩할 연산자를 붙이는데 띄어쓰기 없이 붙여야한다. 
 오버로딩할 연산자는 c++에 존재하는 연산자여야한다. 

 연사자 함수 정의 하는 방법 두가지
    1. 클래스의 맴버 함수로 정의하기 
    2. 전역함수로 정의하기 
    둘의 차이는 > 전역함수는 private에 접근 불가능. 

 오버로딩 가능한 연산자가 있고, 불가능한 연산자가 있다. 
*/
#include <iostream>
using namespace std;

class Position{
    private:
        double x_;
        double y_;
        

    public:
        Position(double x, double y); // 함수가 아니라 생성자. 함수는 앞에 리턴 값이 붙는다. 생성자 다시 공부하기 
        void Display(); //함수 원형 
        Position operator-(const Position& other); // - 연산자 함수 원형. 
        // 맴버함수는 왼쪽 피연산자가 '호출'하기 때문에 기본적으로 매개변수로 들어오는건 연산자의 오른쪽에 있는 피연산자
        // Position 클래스의 '-' 를 쓰면 오버로딩된 '-'를 쓰는 것이다. 
        friend Position operator+(const Position& pos1,const Position& pos2); // 전역함수로 선언할거임
        // friend : operator+라는 함수에게 Position class의 private 맴버에 접근할 수 있는 권한을 받음. 
        
};     


int main(){
    Position p1 = Position(2.0, 3.0);
    Position p2 = Position(2.0, 0.0);
    Position midel = p1 - p2; // Position class 끼리  - 를 쓰면 오버로딩된 -를 쓰는 듯 
    midel.Display();
    Position midel2 = p1 + p2; // 전역으로 선언한 오버로딩 연산자
    midel2.Display();

    cout << 5-2<<endl; // 이건 우리가 아는 - 
    
}

// class Position 의 생성자
Position::Position(double x, double y){
    x_ = x;
    y_ = y;
}

void Position::Display(){
    cout<< "( X: "<< x_<< " , Y: "<< y_<<" )"<<endl;
}

// (클래스의 맴버 함수로서) -를 오버로딩한 연산자 함수 본체 
Position Position::operator-(const Position&other){
    // 현재 -를 부른 클래스의 x_, y_와 그 뒤에 나오는 다른 Position class의 x_, y_
    cout<< x_ <<","<<y_<<endl; // 2,3
    cout<< other.x_ <<","<< other.y_<<endl; // 2,0
    return Position((x_ + other.x_)/2, (y_+other.y_)/2);
}

// (전역함수로서) +를 오버로딩한 연산자 함수 본체 : x_, y_가 접근 불가능하다. 
// 전역함수니까 return 값 뒤에 className:: 붙일 필요가 없다. 
Position operator+(const Position&pos1, const Position&pos2){ //(왼쪽 피연산자, 오른쪽 피연산자 )
    /*operator+가 fiend로 선언되었기 때문에 Position의 private에 접근이 가능하다. 그래서 other.x_나 other.y_에는 접근이 가능하다.
    그러나 그냥 x_, y_로 쓸 순 없다. 따라서  */
    cout<< pos1.x_ <<","<< pos1.y_<<endl; // 2,0
    cout<< pos2.x_ <<","<< pos2.y_<<endl; // 2,0
    return Position((pos1.x_ + pos2.x_)/2, (pos1.y_+ pos2.y_)/2);
} 