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
		//cout << m_iPrivate << endl;	// ERROR : �θ��� private ���� �Ұ� 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

class Child_protected: protected Parent {
public:
	void Draw() {
		//cout << m_iPrivate << endl;	// ERROR : �θ��� private ���� �Ұ� 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

class Child_public: public Parent {
public:	
	void Draw() {
		//cout << m_iPrivate << endl;	// ERROR : �ڳ࿡�� -> �θ��� private ���� �Ұ� 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

int main() {
	Parent p1;

	Child_private c_private;
	Child_protected c_protected;
	Child_public c_public;

	/* �ܺο��� >> �θ� ��ü�� �θ� �ɹ� ���� */
		//cout << p1.m_iPrivate << endl;	// ERROR : �ܺο��� -> ��ü�� private ���� �Ұ�
		//cout << p1.m_iProtected << endl;	// ERROR : �ܺο��� -> ��ü�� protected ���� �Ұ�
		cout << p1.m_iPublic << endl;		// OK : �ܺο��� -> ��ü�� public ���� ����. 

	/* �ܺο��� >> �ڳ� ��ü�� �θ� �ɹ� ���� */
		//cout << c_private.m_iPrivate << endl;		// ERROR : �ܺο��� -> private���� ��ӹ��� �θ��� private ���� �Ұ�
		//cout << c_private.m_iProtected << endl;	// ERROR : �ܺο��� -> private���� ��ӹ��� �θ��� protected ���� �Ұ�
		//cout << c_private.m_iPublic << endl;		// ERROR : �ܺο��� -> private���� ��ӹ��� �θ��� public ���� �Ұ�

		//cout << c_protected.m_iPrivate << endl;	// ERROR : �ܺο��� -> protected�� ��ӹ��� �θ��� private ���� �Ұ�
		//cout << c_protected.m_iProtected << endl;	// ERROR : �ܺο��� -> protected�� ��ӹ��� �θ��� protected ���� �Ұ�
		//cout << c_protected.m_iPublic << endl;	// ERROR : �ܺο��� -> protected�� ��ӹ��� �θ��� public ���� �Ұ�

		//cout << c_public.m_iPrivate << endl;		// ERROR : �ܺο��� -> public�� ��ӹ��� �θ��� private ���� �Ұ�
		//cout << c_public.m_iProtected << endl;	// ERROR : �ܺο��� -> public�� ��ӹ��� �θ��� protected ���� �Ұ�
		cout << c_public.m_iPublic << endl;			// OK : �ܺο��� -> public�� ��ӹ��� �θ��� public ���� ����!

}