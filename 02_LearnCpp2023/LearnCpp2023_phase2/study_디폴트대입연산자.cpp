#include "stdafx.h"

using namespace std;


class CTest {
private:
	int m_iData;
public:
	//CTest() {}
	CTest(int _iData) { cout << "생성자 오버로딩" << endl; };

	
	CTest& operator= (int _iData) {
		cout << "대입 연산자 오버로딩2" << endl;
		return *this;
	}

	CTest& operator= (CTest& refCTest) {
		cout << "대입 연산자 오버로딩1" << endl;
		return *this;
	}
	
	CTest(const CTest& _refCTest) {
		cout << "복사 생성자 오버로딩" << endl;
	}
	
};


class CTest_defult {
public:
	CTest_defult(int _iData) {};
};

class CTest_2 {
private:
	int m_iData;
public:
	CTest_2(int _iData):m_iData(_iData) {};

	void Rander() { cout << m_iData << endl; }

	CTest_2(const CTest_2& _ct) {
		cout << "복사 생성자 오버로딩" << endl;
	}

	CTest_2& operator= (int iData) { cout << "대입 오버로딩" << endl; }
	CTest_2& operator= (const CTest_2& iData) { cout << "대입 오버로딩" << endl; return *this; }
	
	void Set(int _iData) { m_iData = _iData; }
};

class CTest_3 {
public:
	explicit CTest_3(int i) { cout << "explicit 생성자 " << endl; }

	//CTest_3& operator= (int a) { cout << "디폴트 연산자 오버로딩 " << endl; }
};

class CTest_4 {
public:
	CTest_4(int i) { cout << "생성자 " << endl; }

	//CTest_4& operator = (const CTest_4& _t) { cout << "대입연산자" << endl; return *this; }

	CTest_4(const CTest_4& _t) { cout << "복사 생성자" << endl; }
};

int main(){

	{
		cout << " [1]" << endl;
		CTest a = { 200 };
		CTest t(a);
		//CTest c = 100;
		t = 200;
		
	}

	
	/* 디폴트 복사 생성자와 디폴트 대입연산자 */
	{
		cout << " [2]" << endl;
		// 복사생성자, 대입연산자 모두 오버로딩함 
		CTest x1 = 100;		// 대입연산자
		CTest x2 = { 100 };	// 대입연산자
		CTest x3 = x2;		// 복사 생성자
		CTest x4(x3);		// 복사 생성자
			
		x1 = x2;			// 대입연산자
	}


	/* 디폴트 복사 생성자와 디폴트 대입연산자 */
	{
		cout << " [3]" << endl;
		// 복사생성자, 대입연산자 모두 디폴트만 쓰는 객체에서 
		CTest_defult x1 = 100;	// 디폴트 대입연산자
		CTest_defult x2 = { 100 };	//디폴트 대입연산자
		CTest_defult x3 = x2;	//디폴트 복사 생성자
		CTest_defult x4(x3);	// 디폴트 복사 생성자

		x1 = x2;				// 디폴트 대입 연산자 
	}

	/* 오버로딩 복사 생성자와 디폴트 대입연산자 */
	{
		cout << " [4]" << endl;
		// 복사생성자, 대입연산자 모두 디폴트만 쓰는 객체에서 
		CTest_2 x1 = 100;		// 디폴트 대입연산자
		CTest_2 x2 = { 100 };	//디폴트 대입연산자
		CTest_2 x3 = x2;		//디폴트 복사 생성자
		CTest_2 x4(x3);			// 디폴트 복사 생성자
		
		//- -----------------------------------------------------

		x1 = x2;	// 디폴트 대입 연산자	(객체가 우항에 있지만 이건 대입 연산자가 불림!)
		
		// x1, x2가 모두 객체 포인터가 아닌 그냥 객체니까 얕은 복사가 일어나도 괜찮다. 
		x1.Rander();
		x2.Rander();
		x1.Set(200);
		x1.Rander();
		x2.Rander();
		cout << endl;
		//- -----------------------------------------------------
		
		CTest_2* xp1 = new CTest_2(100);
		CTest_2* xp2 = new CTest_2(100);
		
		xp1 = xp2; // 디폴트 대입 연산자	(객체가 우항에 있지만 이건 대입 연산자가 불림!)

		// xp1, xp2는 객체 포인터이므로 디폴트 대입 연산자의 얕은복사로 인해 원치 않는결과가 나온다. 
		xp1->Rander();
		xp2->Rander();
		xp1->Set(200);
		xp1->Rander();
		xp2->Rander();
	}

	/* explicit */
	{
		cout << "[7]" << endl;
		//CTest_3 a = 100;	// explicit있으면 디폴트 대입연산자 못씀 
		CTest_3 a(100);
		//a = 100;
	}

	// 디폴트 복사 생성자, const CTest_4& 를 인자로 받는 대입 연산자 오버로딩 ㄴ
	{
		cout << "[6]" << endl;
		CTest_4 a = 100;
		CTest_4 b = 200;

		a = b;

	}
	
}