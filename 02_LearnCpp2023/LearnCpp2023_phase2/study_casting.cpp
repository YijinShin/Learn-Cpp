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
	
	// �ٿ��ɽ����� ������ ���� �ʴ� ��� 
	{
		Parent* p = new Child;	// �̷��� �ص� p�� ��ü�� Parent�� �Ǿ�����
								/* �̰� ���� ����� �������ε� �̾߱��̴�.
								* ������ Ÿ�ӿ����� Parent* p�� Parent�� �ν��Ѵ�.
								* ���� ��Ÿ�ӿ� new Child�� �Ҵ��ؼ� ������ Child�� �����ڰ� �Ҹ����Ѵ�.
								* �׷��� Parent* p �� ������ Ÿ�ӿ� Parent�� �ν��߱� ������, ������Ÿ�ӿ� p�� �ɹ� �Լ��� Parent�� �Լ��� ���ε��ع�����.
								* ���� �ڳఴü�� �Ҵ��������� p�� Parent�� �ɹ��Լ��� ����� �� �ְԵȴ�.
								* ��, virtual �Լ��� Child���� �������̵��ߴٸ�, �ش� �Լ��� �ڳ��� �Լ��� ����ȴ�. �̰� �������ε��� ȿ���� ���̴�.
								*/
		p->Set(10);			// �������ε��̴ϱ� �θ��� �Լ��� �Ҹ���. iChild�� �ɹ��� �ٲٰ�; Parent�� iParent�� �ٲ۴�.
		p->Draw_virtual();	// �������ε��̴ϱ� �ڳ��� �Լ��� �Ҹ���.
		p->Draw();			// �������ε��̴ϱ� �θ��� �Լ��� �Ҹ���.

		/* ����������ϸ� ��·�� p�� Child�� ��� �ɹ��� �����Ҽ��� ����.
		   p�� ������ �ڳఴü�� �ٲٷ��� �ٿ��ɽ����� �� �ʿ��ϴ�.*/
		dynamic_cast<Child*>(p)->Set(20);	// �̷��� ���� �ٿ��ɽ����� �ؼ�, Child�� Set�� ȣ���ϴ� ���̴�. 
		dynamic_cast<Child*>(p)->Draw();	// �̷��� ���� �ٿ��ɽ����� �ؼ�, Child�� Draw�� ȣ���ϴ� ���̴�. 
		cout << endl;

		/* �ϴ� �̷� ����, new Child���� �ϴ� Child �����ڸ� ȣ���ؼ� ��ü ������ �Ѵ�. ��, �ڳ��� �ɹ� ����, �Լ� ����� ����� �޸𸮴� Ȯ���� �� ���̴�.
			�ڳ� �����ڰ� �ҷȱ� ������ dynamic_cast�� ���ؼ� Child�� �ɹ� �Լ��� ȣ���ϰų�, Child�ɹ� �Լ��� �����ص� ������ ���� �ʴ´�.*/
	}

	// �ٿ��ɽ����� ������ �Ǵ� ���
	{
		Parent* p = new Parent;		/* �� ���� ���ʿ� Child �����ڸ� �θ����̾��� ������ (Child ��ü�� ������ ���� ���� ������) 
									�� �ڿ��� dynamic_cast�� �ҷ��� Child�� �ɹ� ��ü�� �����Ϸ����ϸ� ������ �����.
									����� Child �ɹ� �Լ��� ȣ��ȴ�. */
		p->Draw();
		dynamic_cast<Child*>(p)->Draw_virtual();
		dynamic_cast<Child*>(p)->Draw();	// Child�� Draw�Լ��� ȣ��ȴ�. �׷��� �Լ� ������ Child�� �ɹ��� �����Ϸ��� �ϱ� ������ �����߿� ������ �����̴�.
	}

}


