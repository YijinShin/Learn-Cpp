/*
클래스 생성자에 관하여. (블로그 class 초기화 방법들에 첨부한 코드)

*/


#include <iostream>

using namespace std;


// 그 어떠한 생성자도 선언하지 않은 경우
class Test1 {
public:
	int iData;
};

// 디폴트 생성자를 정의한 경우
class Test2 {
public:
	int iData;
	Test2() { iData = 10; };
};

// 디폴트 생성자 외의 생성자를 정의한 경우
class Test3 {
public:
	int iData;
	Test3(int iSrc) { iData = iSrc; };
};

// 디폴트 생성자와 오버로딩 생성자를 모두 정의한 경우
class Test4 {
public:
	int iData;
	Test4() { iData = 10; };
	Test4(int iSrc) { iData = iSrc; };
};

// 복사 생성자를 정의하지 않은 경우
class Test5 {
private:
	int private_mem;
public:
	int public_mem;	
	int* public_ptr_mem;
	Test5(int iData, int iSrc, int* iPtr) {
		public_ptr_mem = iPtr;
		private_mem = iData;
		public_mem = iSrc;
	}
	void Display() {
		cout << private_mem << "," << public_mem <<"," <<*public_ptr_mem<< endl;
	}
};
// 복사 생성자를 오버로딩한 경우
class Test6 {
private:
	int private_mem;
public:
	int public_mem;
	int* public_ptr_mem;
	Test6(int iData, int iSrc, int* iPtr) {
		public_ptr_mem = iPtr;
		private_mem = iData;
		public_mem = iSrc;
	}
	Test6(const Test6& t) {
		
		//public_ptr_mem 맴버 변수는 동적 할당을 받는 맴버 변수이다. 따라서 그냥 디폴트 복사 생성자 내부에서 깊은 복사가 일어나도록 해줘야한다.
		public_ptr_mem = new int;				
		*public_ptr_mem = *t.public_ptr_mem;
		// 	public_ptr_mem = t.public_ptr_mem;	// 이렇게 하면 얕은복사임. 걍 디폴트 복사 생성자 쓰는거랑 다를게 x
		
		private_mem = t.private_mem;
		public_mem = t.public_mem;
	}
	void Display() {
		cout << private_mem << "," << public_mem << "," << *public_ptr_mem << endl;
	}
};


// reference 맴버를 가지고있는 경우 
class Test7 {
public:
	int mem;
	int& ref_mem;
	Test7(int iData, int& iValue):ref_mem(iValue), mem(0){
		cout << "member1: " << mem << ", "
			<< "member2: " << ref_mem << endl;

		mem = iData;
		ref_mem = iValue;

		cout << "member1: " << mem << ", "
			<< "member2: " << ref_mem << endl;
	}

};

// 초기화 리스트 없이 생성자에서 "대입" 을 통해 초기화 하는 경우
class Test8 {
private:
public:
	int member1;
	int member2;
	Test8(int iData, int iSrc) :member1(10), member2(10) {
		cout << "member1: " << member1 << ", "
			<< "member2: " << member2 << endl;

		member1 = iData;
		member2 = iSrc;

		cout << "member1: " << member1 <<  ", "
			<< "member2: " << member2 << endl;
	}

};




int main() {

	// 그 어떠한 생성자도 선언하지 않은 경우
	{
		Test1 t1;
		Test1 t2 = Test1();

		//cout << t1.iData << endl;	//ERROR
		cout << t2.iData << endl;
	}

	// 디폴트 생성자를 정의한 경우
	{
		Test2 t1;
		Test2 t2 = Test2();

		cout << t1.iData << endl;	//ERROR
		cout << t2.iData << endl;
	}

	// 디폴트 생성자 외의 생성자를 정의한 경우
	{
		//Test3 t1;					//ERROR
		//Test3 t2 = Test3();		//ERROR
		Test3 t3 = Test3(4);

		cout << t3.iData << endl;
	}

	// 디폴트 생성자와 오버라이딩 생성자를 모두 정의한 경우
	{

		Test4 t1;				
		Test4 t2 = Test4();		
		Test4 t3 = Test4(4);

		cout << t1.iData << endl;
		cout << t2.iData << endl;
		cout << t3.iData << endl;

	}
	cout << endl;

	//복사생성자
	{
		int iA = 100;
		Test5 t1(10, 20, &iA);
		Test5 t2(t1);	// 디폴트 복사생성자 사용
		t1.Display();
		t2.Display();

		// 그냥 public 값 수정
		t1.public_mem = 22;
		t2.public_mem = 25;
		t1.Display();
		t2.Display();

		//디폴트 복사생성자를 사용했기 떄문에(얕은 복사를 했기때문에) t1의 값을 변경해도 t2가 같이 변경된다.
		*t1.public_ptr_mem = 200;	
		t1.Display();
		t2.Display();
	}
	cout << endl;

	{
		int iA = 100;
		Test6 t1(10, 20, &iA);
		Test6 t2(t1);	// 디폴트 복사생성자 사용
		t1.Display();
		t2.Display();

		// 그냥 public 값 수정
		t1.public_mem = 22;
		t2.public_mem = 25;
		t1.Display();
		t2.Display();

		//직접 생성한 복사 생성자를 사용했고, 그 복사 생성자 안에서 깊은 복사가 일어나도록 설정했기 떄문에 t1과 t2의 public_ptr_mem은 가지고 있는 주소가 다르다.
		*t1.public_ptr_mem = 200;
		t1.Display();
		t2.Display();

	}
	cout << endl;
	
	// 초기화 리스트 사용한 생성자 
	{
		Test8 t1(100,100);

		int ia = 5;
		int& k = ia;

		Test7 t(100, k);

	}
}