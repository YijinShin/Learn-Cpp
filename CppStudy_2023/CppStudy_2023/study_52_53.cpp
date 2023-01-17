/* [ C++ study with TCP school 52part]
topic: 연산자 오버로딩 
	

* 연산자 오버로딩 
	함수 오버로딩처럼 같은 연산자를 다른 기능으로 사용하기 위해 다시 선언하는 것. 
	물론, 오버로딩을 해서 쓸거면 class안에서 오버로딩을 해서 쓰는 경우가 대부분이다. 
	(ex_ A라는 클래스 안에서는 - 가 그냥 두 수의 -가 아니라 문자열간의 다른부분을 찾아 삭제한다거나.. 뭐 그런) 

* 연산자 오버로딩 선언 방법
	 
	 1. 선언
	 operator[연산자]([매개변수 목록])

	 2. 선언 가능한 위치
		- 클래스의 맴버함수로 선언
		- 전역함수로 선언

* 연산자 오버로딩 장점
	- 복잡하거나 긴 함수이름을 안써도됨. 
	

* 오버로딩도 할 수 있는 연산자가 있고, 
* 할 수 없는 연산자가있고,
* 맴버 함수로만 할 수 있는 연산자가있다.
* (자세한건 http://www.tcpschool.com/cpp/cpp_operatorOverloading_constraint) 여기 참고 

* 전혀 새로운 연산자를 정의할 수는 없다.

*/

#include <iostream>

using namespace std;


class Position {
private:
	float iX_private_;
	float iY_private_;

public:
	float iX_public_;
	float iY_public_;
	int iData_;
	Position(float iX =1.f, float iY=2.f, int iData = 1); //생성자

	Position operator-(const Position& pos);	// 클래스 내에서 선언한 연산자 오버로딩
	friend Position operator+(const Position& p1, const Position& p2);// 전역 함수로 선언한 연산자 오버로딩 (전역 함수로 선언했는데 friend 안붙이면 에러남 
	int operator*(int iTemp) const;

	void DisplayPos();
};


int main() {

	Position p1(10, 0), p2(0, 0);

	Position p3 = p1 - p2;
	p3.DisplayPos();

	Position p4;
	/* 오버로드 연산자 사용할 때 주의할 점
		int iResult = 5 * p4;	// 이런식으로 오버로드한 연산자의 왼쪽에, 해당 오버로드 함수를 호출하는 클래스 객체가 나와야함  */
	int iResult = p4 * 5;
	cout << "* 오버로드 연산자 결과: " << iResult << endl;

}

Position::Position(float iX, float iY, int iData) {
	iX_private_ = iX;
	iY_private_ = iY;
	iX_public_ = iX;
	iY_public_ = iY;
	iData_ = iData;
}


Position Position::operator-(const Position& pos) {
	
	//friend 안쓴 전역 선언된 연산자 오버로딩 함수가 private 변수에 접근하려고 하면 오류남. 
	return Position((iX_private_ + pos.iX_private_) / 2 , (iY_private_ + pos.iY_private_) / 2);


	return Position((iX_private_ + pos.iX_private_) / 2, (iY_private_ + pos.iY_private_) / 2);
	
}

Position operator+(const Position& p1, const Position & p2) {

	// 전역변수에 접근 가능. 
	return Position((p1.iX_public_ + p1.iX_public_) / 2, (p2.iY_public_ + p2.iY_public_) / 2);

	//friend가 있기 때문에 private 접근 가능 
	return Position((p1.iX_private_ + p1.iX_private_) / 2, (p2.iY_private_ + p2.iY_private_) / 2);
}

void Position::DisplayPos() {
	cout << "(x,y): " << iX_private_ << ", " << iX_private_ << endl;
}

int Position::operator*(int iTemp) const{
	return iTemp * iData_;
}