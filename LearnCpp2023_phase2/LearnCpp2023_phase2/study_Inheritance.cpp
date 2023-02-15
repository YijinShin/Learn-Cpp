#include "stdafx.h"

using namespace std;

class Parent {
private:
	int m_iPrivate;
protected:
	int m_iProtected;
public:
	int m_iPublic;
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
	void Draw() {
		//cout << m_iPrivate << endl;	// ERROR : 자녀에서 -> 부모의 private 접근 불가 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

int main() {
	Parent p1;

	Child_private c_private;
	Child_protected c_protected;
	Child_public c_public;

	/* 외부에서 >> 부모 객체로 부모 맴버 접근 */
		//cout << p1.m_iPrivate << endl;	// ERROR : 외부에서 -> 객체의 private 접근 불가
		//cout << p1.m_iProtected << endl;	// ERROR : 외부에서 -> 객체의 protected 접근 불가
		cout << p1.m_iPublic << endl;		// OK : 외부에서 -> 객체의 public 접근 가능. 

	/* 외부에서 >> 자녀 객체로 부모 맴버 접근 */
		//cout << c_private.m_iPrivate << endl;		// ERROR : 외부에서 -> private으로 상속받은 부모의 private 접근 불가
		//cout << c_private.m_iProtected << endl;	// ERROR : 외부에서 -> private으로 상속받은 부모의 protected 접근 불가
		//cout << c_private.m_iPublic << endl;		// ERROR : 외부에서 -> private으로 상속받은 부모의 public 접근 불가

		//cout << c_protected.m_iPrivate << endl;	// ERROR : 외부에서 -> protected로 상속받은 부모의 private 접근 불가
		//cout << c_protected.m_iProtected << endl;	// ERROR : 외부에서 -> protected로 상속받은 부모의 protected 접근 불가
		//cout << c_protected.m_iPublic << endl;	// ERROR : 외부에서 -> protected로 상속받은 부모의 public 접근 불가

		//cout << c_public.m_iPrivate << endl;		// ERROR : 외부에서 -> public로 상속받은 부모의 private 접근 불가
		//cout << c_public.m_iProtected << endl;	// ERROR : 외부에서 -> public로 상속받은 부모의 protected 접근 불가
		cout << c_public.m_iPublic << endl;			// OK : 외부에서 -> public로 상속받은 부모의 public 접근 가능!

}