/* [ C++ study with TCP school 48 ~ 51 part]
topic: 생성자 / 소멸자

------------------------------------------------------------------------------------
* 생성자 필요한이유 

	클래스 객체를 생성하면 -> 해당 객체는 메모리에 바로 생성됨
	but, 이 객체는 모든 맴버 변수를 초기화 하기 전까지는 사용이 불가능함

	이때, private 맴버를 초기화 하기 위해서는 무조건 public함수가 필요하다. 
	이렇게 초기화 하는 함수를 생성자(Contructor)라고 말함

* 클래스의 생성자 이름 = 클래스 이름과 같음

* 생성자 여러개 가질 수 있음 (오버로딩 규칙 ㅇㅈ)


* 생성자 종류
	- 생성자

	- 디폴트 생성자

	- 복사 생성자
		
			복사의 두 종류
				- 얕은 복사 : 객체의 참조값(주소값)을 복사함 => x가 y를 얕은 복사하면 => y값이 바뀌면 x값도 같이 바뀐다. 
							* 이게 x,y가 같은 주소값을 '가지는 건' 아닌거같고, 둘이 같은 주소값을 '참조한다'는 개념같음. 
							
				- 깊은 복사 : 객체의 실제 값을 복사함. => 원본 데이터가 변해도 상관없이 완전히 독립적으로 복사됨
------------------------------------------------------------------------------------

* 소멸자
	- 객체의 수명이 끝나면 호출됨 
		따로 선언을 안하면 소멸자가 알아서 실행됨.
	- 객체 소멸시 특별한 기능을 하길 바라면 따로 소멸자 선언하기 

*/

#include <iostream>
#include <string>

using namespace std;


class Book {
	private:
		int curr_Page_;

	public:
		Book(const string& title, const string& author, int total_page, int curr_page);	// 생성자 함수 원형
		string title_;
		string author_;
		int total_Page_;

};


class Cat {
	private:
		float kg_;
		float cm_;

	public:
		string name_;
		string type_;
		Cat(const string& name = "000", const string& type = "0000", float kg = 0.f, float cm = 0.f);
		Cat(const Cat& origin);
		~Cat();
};


int main() {
	//------------------------------------------------------------------------------------------------------------
	{
		// 디폴트 생성자가 없는 클래스의 경우
		Book b1("Math", "A.Jhon", 100, 10);	// 클래스 호출 
		Book b2 = Book("English", "B.Jhon", 150, 23);	// 명시적 호출
		Book* b3 = new Book("Korea","C.Jhon", 200, 1);	// 암시적 호출
		/* 디폴트 생성자가 없으면 이렇게 호출할 때 초기화 값 안넣으면 에러남
			Book b4;	
			Book b5 = Book();
			Book *b6 = new Book(); 
		*/


		// 디폴트 생성자가 있는 경우 
		Cat c1;
		Cat c2 = Cat();
		Cat* c3 = new Cat();
		//이렇게 초기화 값 안넣어줘도 디폴트값 알아서 넣음 
	}
	//------------------------------------------------------------------------------------------------------------

	{
		// 대입 연산자 복사 (변수간의 복사)
		int x(10), y(0);
		cout << "[얕은 복사 전] x 주소, 값: " << &x << ", " << x << " // " << "y 주소, 값: " << &y << ", " << y << endl;
		y = x;
		cout << "[얕은 복사 후] x 주소, 값: " << &x << ", " << x << " // " << "y 주소, 값: " << &y << ", " << y << endl;
		x = 20;
		cout << "[얕은 복사 후, 원본 데이터 변경함] x 주소, 값: " << &x << ", " << x << " // " << "y 주소, 값: " << &y << ", " << y << endl << endl;

		// 대입 연산자 복사 ( 인스턴스 간의 복사) 
		Cat c1("Jhon", "먼치킨", 15, 30);
		Cat c2 = c1;
		cout << "[얕은 복사 후] c1 주소, 값: " << &c1 << ", " << c1.name_ << " // " << "c2 주소, 값: " << &c2 << ", " << c2.name_ << endl;
		c1.name_ = "Ami";
		cout << "[얕은 복사 후, 원본 데이터 변경함] c1 주소, 값: " << &c1 << ", " << c1.name_ << " // " << "c2 주소, 값: " << &c2 << ", " << c2.name_ << endl << endl;
		//delete[] &c2.name_;
		//cout << "[얕은 복사 후, 원본 데이터 삭제함] c2 주소, 값: " << &c1 << ", " << c1.name_ << endl << endl;	// 원본데이터인 c2의 name_과 같은 주소값을 참조하고 있기 떄문에 c2의 name_을 삭제하면, c1의 name_을 출력해도 에러가남

		// 복사 생성자 복사 ( 인스턴스 간의 복사)
		Cat c3("Jhon", "먼치킨", 15, 30);
		cout << "c3 주소, 값: " << &c3.name_ << ", " << c3.name_ <<  endl;
		Cat c4(c3);
		cout <<  "c4 주소, 값: " << &c4.name_ << ", " << c4.name_ << endl << endl;
		//delete[] &c3.name_;
		//cout << "[깊은 복사 후, 원본 데이터 삭제함] c4 주소, 값: " << &c4.name_ << ", " << c4.name_ << endl << endl;

	}
	//------------------------------------------------------------------------------------------------------------
	{
		cout << "part3" << endl;
		Cat *c1 = new Cat();
		delete c1;

		Cat(*c_Arr) = new Cat[7];
		delete[] c_Arr;
	}

}

//Book 생성자 함수 정의
Book::Book(const string& title, const string& author, int total_page, int curr_page) {
	
	//private 맴버 초기화
	curr_Page_ = curr_page;

	//public 맴버 초기화
	title_ = title;
	author_ = author;
	total_Page_ = total_page;
}

//Cat의 생성자
Cat::Cat(const string& name , const string& type , float kg , float cm) {
	name_ = name;
	type_ = type;
	kg_ = kg;
	cm_ = cm;
}

// Cat의 복사생성자
Cat::Cat(const Cat& origin) { //이거는 원본 데이터를 못바꾸게하려고 const로 선언한것 
	name_ = origin.name_;
	type_ = origin.type_;
	kg_ = origin.kg_;
	cm_ = origin.cm_;
}

Cat::~Cat() {
	cout << "객체가 소멸되었습니다." << endl;
}
