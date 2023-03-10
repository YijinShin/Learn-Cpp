#include "stdafx.h"

using namespace std;

class Parent {
private:
	static int iData;
	int m_iPrivate;
protected:
	int m_iProtected;
public:
	int m_iPublic;
	Parent() {}
};

class Child_private: private Parent {
public:

	void Draw(){
		//cout << m_iPrivate << endl;	// ERROR : 부모의 private 접근 불가 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

class Child_protected: protected Parent {
public:
	void Draw() {
		//cout << m_iPrivate << endl;	// ERROR : 부모의 private 접근 불가 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

class Child_public: public Parent {
public:	
	double m_d1;
	void Draw() {
		//cout << m_iPrivate << endl;	// ERROR :  부모의 private 접근 불가 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

int main() {

	// class 크기 확인 
	{
		Parent p1;
		Child_private c_private;
		Child_protected c_protected;
		Child_public c_public;

		cout << sizeof(p1) << endl;			// 12byte : int 맴버가 3개라서 3*4 = 12
		cout << sizeof(c_private) << endl;	// 12byte : 자식한테는 맴버가 없지만 부모로부터 물려받은 맴버가 int 3개라서 12
		cout << sizeof(c_protected) << endl;// 12byte : 자식한테는 맴버가 없지만 부모로부터 물려받은 맴버가 int 3개라서 12
		cout << sizeof(c_public) << endl;	// 24byte : 자식의 double +  부모로부터 물려받은 맴버가 int 3개 = 24
		cout << endl;
		
	}


	// 접근 제어 지시자 실험 
	{
		Parent p1;

		Child_private c_private;
		Child_protected c_protected;
		Child_public c_public;

		/* 외부에서 >> 자기 맴버 접근 */
			//cout << p1.m_iPrivate << endl;	// ERROR : 외부에서 -> 객체의 private 접근 불가
			//cout << p1.m_iProtected << endl;	// ERROR : 외부에서 -> 객체의 protected 접근 불가
			cout << p1.m_iPublic << endl;		// OK : 외부에서 -> 객체의 public 접근 가능. 

		/* 외부에서 >> 자녀 객체로 부모 맴버 접근 */
			/* 부모를 private으로 상속받으면, 부모 전체를 private화 시키는 것*/
			//cout << c_private.m_iPrivate << endl;		// ERROR : 외부에서 -> private으로 상속받은 부모의 private 접근 불가
			//cout << c_private.m_iProtected << endl;	// ERROR : 외부에서 -> private으로 상속받은 부모의 protected 접근 불가
			//cout << c_private.m_iPublic << endl;		// ERROR : 외부에서 -> private으로 상속받은 부모의 public 접근 불가
			
			/* 부모를 protected로 상속받으면, 부모 전체를 외부에 대해서는 private화 시키는 것*/
			//cout << c_protected.m_iPrivate << endl;	// ERROR : 외부에서 -> protected로 상속받은 부모의 private 접근 불가
			//cout << c_protected.m_iProtected << endl;	// ERROR : 외부에서 -> protected로 상속받은 부모의 protected 접근 불가
			//cout << c_protected.m_iPublic << endl;	// ERROR : 외부에서 -> protected로 상속받은 부모의 public 접근 불가

			/* 부모를 public으로 상속받으면, 외부에 대해 부모를 public으로 여는 것. */
			//cout << c_public.m_iPrivate << endl;		// ERROR : 외부에서 -> public로 상속받은 부모의 private 접근 불가
			//cout << c_public.m_iProtected << endl;	// ERROR : 외부에서 -> public로 상속받은 부모의 protected 접근 불가
			cout << c_public.m_iPublic << endl;			// OK : 외부에서 -> public로 상속받은 부모의 public 접근 가능!
	}
	

}