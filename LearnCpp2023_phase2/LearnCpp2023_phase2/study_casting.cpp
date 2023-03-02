#include "stdafx.h"
#include <vector>
using namespace std;


class Parent {
private:
	int iParent;
protected:
	
public:
	Parent() :iParent(0) {}
	Parent(int _iP) { iParent = _iP; }
	virtual ~Parent() {}
	virtual void Draw_virtual() { cout << "Draw_virtual :Parent"<< iParent << endl; }
	void Draw() { cout << "Draw: Parent " << iParent << endl; }
	virtual int Get() { return iParent; }
	void Set(int _iP) { iParent = _iP; }

};

class Child: public Parent {
private:
	int iChild;
public:
	Child():iChild(0){}
	Child(int _iC, int _iP) : Parent(_iP)
	{
		iChild = _iC;
	}
	virtual ~Child() {}

	void Draw_virtual() {cout << "Draw_virtual: child "<<iChild << endl; }
	void Draw() { cout << "Draw: child " << iChild << endl; }
	virtual int Get() { return iChild; }
	void Set(int _iC) { iChild = _iC; }
};

int main() {
	
	// 다운케스팅이 문제가 되지 않는 경우 
	{
		Parent* p = new Child;	// 이렇게 해도 p의 실체는 Parent로 되어있음
								/* 이게 전에 배웠던 정적바인딩 이야기이다.
								* 컴파일 타임에서는 Parent* p를 Parent로 인식한다.
								* 이후 런타임에 new Child를 할당해서 실제로 Child의 생성자가 불리긴한다.
								* 그러나 Parent* p 를 컴파일 타임에 Parent로 인식했기 때문에, 컴파일타임에 p의 맴버 함수는 Parent의 함수로 바인딩해버린다.
								* 따라서 자녀객체를 할당했음에도 p는 Parent의 맴버함수만 사용할 수 있게된다.
								* 단, virtual 함수를 Child에서 오버라이딩했다면, 해당 함수는 자녀의 함수가 실행된다. 이게 동적바인딩의 효과인 것이다.
								*/
		p->Set(10);			// 정적바인딩이니까 부모의 함수가 불린다. iChild의 맴버를 바꾸고싶어도 Parent의 iParent만 바꾼다.
		p->Draw_virtual();	// 동적바인딩이니까 자녀의 함수가 불린다.
		p->Draw();			// 정적바인딩이니까 부모의 함수가 불린다.

		/* 여기까지만하면 어쨌든 p는 Child의 모든 맴버에 접근할수는 없다.
		   p를 완전히 자녀객체로 바꾸려면 다운케스팅이 꼭 필요하다.*/
		dynamic_cast<Child*>(p)->Set(20);	// 이렇게 순간 다운케스팅을 해서, Child의 Set을 호출하는 것이다. 
		dynamic_cast<Child*>(p)->Draw();	// 이렇게 순간 다운케스팅을 해서, Child의 Draw을 호출하는 것이다. 
		cout << endl;

		/* 일단 이런 경우는, new Child에서 일단 Child 생성자를 호출해서 객체 생성을 한다. 즉, 자녀의 맴버 변수, 함수 등등이 저장될 메모리는 확보를 한 것이다.
			자녀 생성자가 불렸기 때문에 dynamic_cast를 통해서 Child의 맴버 함수를 호출하거나, Child맴버 함수에 접근해도 문제가 되지 않는다.*/
	}

	// 다운케스팅이 문제가 되는 경우
	{
		Parent* p = new Parent;		/* 이 경우는 애초에 Child 생성자를 부른적이없기 때문에 (Child 객체를 생성한 적이 없기 때문에) 
									이 뒤에서 dynamic_cast를 불러서 Child의 맴버 객체에 접근하려고하면 문제가 생긴다.
									참고로 Child 맴버 함수는 호출된다. */
		p->Draw();
		dynamic_cast<Child*>(p)->Draw_virtual();
		dynamic_cast<Child*>(p)->Draw();	// Child의 Draw함수가 호출된다. 그러나 함수 내에서 Child의 맴버에 접근하려고 하기 때문에 실행중에 에러가 날것이다.
	}

}


