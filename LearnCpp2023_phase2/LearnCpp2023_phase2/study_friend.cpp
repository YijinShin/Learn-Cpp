#include "stdafx.h"

using namespace std;




/* 상속 관계인 두 클래스 */
class CParent {
private:
	int m_iPrivate_Parent;
protected:
	int m_iProtected_Parent;
public:
	int m_iPublic_Parent;
	void Draw() { cout << "CFriendA" << endl; }
};

class CChild: public CParent {
private:
	int m_iPrivate_child;
protected:
	int m_iProtected_child;
public:
	int m_iPublic_child;
	void Access() {
		//m_iPrivate_Parent = 10;	// 부모의 private은 접근 불가능	(<< friend와의 차이)
		m_iProtected_Parent = 10;	// 부모의 protected는 접근 가능
		m_iPublic_Parent = 10;		// 부모의 public은 접근 가능
		CParent::Draw();			// 부모와 이름이 똑같은 함수가 자녀에도 있어서 클래스 명을 통해 접근함. 그렇지 않으면 클래스 명 안써도됨.
	}
	void Draw() { 
		cout << "CFriendB" << endl; 
	}
};


/* 친구 관계인 두 클래스 */
class CFriendA {
private:
	int m_iPrivateA;
protected:
	int m_iProtectedA;
public:
	int m_iPublicA;
	void Draw() { cout << "CFriendA" << endl; }

	friend class CFriendB;
};

class CFriendB {
private:
	int m_iPrivateB;
protected:
	int m_iProtectedB;
public:
	int m_iPublicB;
	void Access(CFriendA fa) {	/* friend는 실제 생성된 두 class간의 접근을 허용하는 것이기 때문에 friend클래스의 맴버를 쓰려고 한다면 실제 friend클래스로 생성된 객체가 존재해야한다.
								   상속은 자녀 객체를 만들면 알아서 부모 객체까지 만들어져서 객체에 메모리를 할당하는거지만 friend는 생성된 두 객체가 필요함. */
		fa.m_iPrivateA = 10;	// 객체 이름을 통해 friend클래스의 private맴버 접근 가능
		fa.m_iProtectedA = 10;  // 객체 이름을 통해 friend클래스의 protected맴버 접근 가능
		fa.m_iPublicA = 10;		// 객체 이름을 통해 friend클래스의 public맴버 접근 가능
		fa.Draw();				// 객체 이름을 통해 friend클래스의 public맴버 접근 가능
	}
	void Draw() {
		cout << "CFriendB" << endl; 
	}
};



int main() {
	/* 클래스 크기 테스트 */
	{
		/* 상속관계 클래스 */
		CParent p1;
		CChild c1;
		cout << sizeof(p1) << endl;		// 12 :(3*4)
		cout << sizeof(c1) << endl;		// 24 :자녀의(3*4) + 부모의(3*4)

		/* 친구관계 클래스 */
		CFriendA fa;
		CFriendB fb;
		cout << sizeof(fa) << endl;		// 12 :(3*4)
		cout << sizeof(fb) << endl;		// 12 :(3*4)
		/* friend는 접근을 허용하는 것 뿐 실제 메모리상 친구class를 포함하지 않는다. */
	}

	/* 맴버 접근 테스트 */
	{
		/* 상속관계 클래스 */
		CChild c1;	// (public으로 상속받음)
		
		c1.m_iPublic_Parent = 10;	//부모의 public 맴버 변수 사용가능 
		c1.CParent::Draw();			//부모의 public 맴버 함수 사용가능
		

		/* 친구관계 클래스 */
		CFriendA fa;
		CFriendB fb;
		// fb.m_iPublicA = 10;	// ERROR 친구관계에서는 서로의 맴버 함수나 맴버 변수를 fa.m_iPublicA = 10 이렇게 외부에서 접근할 수 없다. 
	}

}