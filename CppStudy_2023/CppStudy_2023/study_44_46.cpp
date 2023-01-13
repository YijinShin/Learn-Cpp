/* [ C++ study with TCP school 38part]
topic: 클래스 / OOP / 접근제어 지시자


* 클래스
	- 객체 지향 프로그래밍을 할 수 있게 해줌 
	- 구조체의 확장판
	- 구조체와 차이점
		- 맴버로 함수 포함가능
		- 접근 제어 

* 객체 지향 프로그래밍 (OOP : Object-Oriented Programming)
	- 모든 데이터를 '객체'로 취급함
	- 객체의 상태와 행동을 구체화하는 형태의 프로그래밍을 함 
	- '객체'를 만드는 틀 = class

	- OOP의 특징 5개 		 

			1. 추상화(abstraction)	 -> 클래스

			2. 캡슐화(encapsulation)

			3. 정보 은닉(data hiding)

			4. 상속성(inheritance)

			5. 다형성(polymorphism)


* 인스턴스 (instance)
	- 클래스 타입 객체를 인스턴스라고 한다. (메모리에 대입된 객체)
	- 당연히 하나의 클래스에서 여러 개의 인스턴스 생성 가능
	- 맴버 변수 -> 각 인스턴스가 독립적(독립적인 메모리 공간)으로 가짐
	- 맴버 함수 -> 모든 인스턴스가 공유함

* 맴버 함수
	- 클래스 선언부의 밖, 안 모두에서 정의 가능. 
	  물론 클래스 밖에서 함수를 정의한 경우 함수 원형은 클래스 선언부에 있어야함.

------------------------------------------------------------------------------------------------------------------------------------------
* 접근제어 ( access control )
	- 구조체는 모든 맴버를 외부에서 접근이 가능함. 그러나 클래스는 정보 은닉(data hiding)이 가능하다. 
	- 클래스를 선언하면, 그 안에 맴버들의 접근 제어를 설정해줘야한다.
	
	- [ private ] 
		
		- 같은 클래스의, private이나 public 맴버함수만이 접근가능 ( 외부에 은닉되는 정보)
		- 근데 기본적으로 모든 클래스에 맴버를 만들면 private으로 설정됨. 그래서 private 지시자를 적을 필요는 없음.

	- [ public ]
		
		- 해당 클래스 객체를 사용하는 프로그램 어디서나 직접접근 가능
		  ( 같은 패키지, 다른패키지 모두에서 접근가능)
		- 따라서 주로 private 맴버와 프로그램 사이의 인터페이스 역할을 함
		- public 함수는 public, private맴버 모두에 접근 가능

	- [ protected ]

		- 파생클래스(derived class) 와 관련된 접근제어 지시자		(자세한거는 study 57에서)
		- 파생 클래스에 대해서는 -> public맴버로 취급됨
		  그 외에 (외부에서)대해서는 -> private맴버로 취급됨
			
		  즉, 같은 패키지 안에서는 접근 가능, 다른 패키지에서는 접근 불가능 
 
------------------------------------------------------------------------------------------------------------------------------------------

* 

*/

#include <iostream>
#include <string>

using namespace std;


// 클래스 선언 
class Pokemon
{
	// 접근제어 지시자:
	private:
		//맴버 변수1
		float weight;
		//맴버 변수2
		float height;
		//맴버 함수1 _ 클래스 선언부에서 함수를 정의한 경우 
		void DisplayInfo_private() { cout << "[private] 이름: " << name << ", 키: " << height << ", 몸무게: " << weight << endl; }
		//맴버 함수2 _ 클래스 선언부에서는 함수 원형만 쓰고, 정의는 클래스 밖에 있음
		void DisplayInfo_private_2();
	
	// 접근제어 지시자:
	public:
		//맴버 변수1
		string type = "000";
		//맴버 변수3
		string name = "000";
		//맴버 함수1
		void DisplayInfo_public() { cout << "[public] 이름: " << name << ", 키: " << height << ", 몸무게: " << weight << endl;}
		void CallPrivateFunction() { DisplayInfo_private(); }
		
		//맴버 함수(get함수)
		void getWeight(float w) { weight = w; }
		void getHeight(float h) { height = h; }


};

// 클래스 밖에서 맴버 함수를 정의할 경우 
void Pokemon::DisplayInfo_private_2() { cout << "[private + outside] 이름: " << name << ", 키: " << height << ", 몸무게: " << weight << endl; }


int main() {

	// 인스턴스 선언
	Pokemon pikachu;


	// [ private 맴버에 접근 ]
	//pikachu.weight = 10.f		// weight는 private 맴버라서 이렇게는 접근이 안됨 
	pikachu.getWeight(10.f);	// private 맴버변수에 값을 넣으려면 이렇게 public 맴버로 get함수를 생성해서 해야함. 
	pikachu.getHeight(20.f);
	//pikachu.DisplayInfo_private(); // private 함수도 마찬가지로 바로 접근은 안됨
	
	// [ public 맴버에 접근]
	getline(cin, pikachu.name);
	pikachu.DisplayInfo_public();



}