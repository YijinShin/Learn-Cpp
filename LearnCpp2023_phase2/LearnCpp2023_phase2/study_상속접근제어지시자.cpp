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
	double m_d1;
	void Draw() {
		//cout << m_iPrivate << endl;	// ERROR :  �θ��� private ���� �Ұ� 
		cout << m_iProtected << endl;
		cout << m_iPublic << endl;
	}
};

int main() {

	// class ũ�� Ȯ�� 
	{
		Parent p1;
		Child_private c_private;
		Child_protected c_protected;
		Child_public c_public;

		cout << sizeof(p1) << endl;			// 12byte : int �ɹ��� 3���� 3*4 = 12
		cout << sizeof(c_private) << endl;	// 12byte : �ڽ����״� �ɹ��� ������ �θ�κ��� �������� �ɹ��� int 3���� 12
		cout << sizeof(c_protected) << endl;// 12byte : �ڽ����״� �ɹ��� ������ �θ�κ��� �������� �ɹ��� int 3���� 12
		cout << sizeof(c_public) << endl;	// 24byte : �ڽ��� double +  �θ�κ��� �������� �ɹ��� int 3�� = 24
		cout << endl;
		
	}


	// ���� ���� ������ ���� 
	{
		Parent p1;

		Child_private c_private;
		Child_protected c_protected;
		Child_public c_public;

		/* �ܺο��� >> �ڱ� �ɹ� ���� */
			//cout << p1.m_iPrivate << endl;	// ERROR : �ܺο��� -> ��ü�� private ���� �Ұ�
			//cout << p1.m_iProtected << endl;	// ERROR : �ܺο��� -> ��ü�� protected ���� �Ұ�
			cout << p1.m_iPublic << endl;		// OK : �ܺο��� -> ��ü�� public ���� ����. 

		/* �ܺο��� >> �ڳ� ��ü�� �θ� �ɹ� ���� */
			/* �θ� private���� ��ӹ�����, �θ� ��ü�� privateȭ ��Ű�� ��*/
			//cout << c_private.m_iPrivate << endl;		// ERROR : �ܺο��� -> private���� ��ӹ��� �θ��� private ���� �Ұ�
			//cout << c_private.m_iProtected << endl;	// ERROR : �ܺο��� -> private���� ��ӹ��� �θ��� protected ���� �Ұ�
			//cout << c_private.m_iPublic << endl;		// ERROR : �ܺο��� -> private���� ��ӹ��� �θ��� public ���� �Ұ�
			
			/* �θ� protected�� ��ӹ�����, �θ� ��ü�� �ܺο� ���ؼ��� privateȭ ��Ű�� ��*/
			//cout << c_protected.m_iPrivate << endl;	// ERROR : �ܺο��� -> protected�� ��ӹ��� �θ��� private ���� �Ұ�
			//cout << c_protected.m_iProtected << endl;	// ERROR : �ܺο��� -> protected�� ��ӹ��� �θ��� protected ���� �Ұ�
			//cout << c_protected.m_iPublic << endl;	// ERROR : �ܺο��� -> protected�� ��ӹ��� �θ��� public ���� �Ұ�

			/* �θ� public���� ��ӹ�����, �ܺο� ���� �θ� public���� ���� ��. */
			//cout << c_public.m_iPrivate << endl;		// ERROR : �ܺο��� -> public�� ��ӹ��� �θ��� private ���� �Ұ�
			//cout << c_public.m_iProtected << endl;	// ERROR : �ܺο��� -> public�� ��ӹ��� �θ��� protected ���� �Ұ�
			cout << c_public.m_iPublic << endl;			// OK : �ܺο��� -> public�� ��ӹ��� �θ��� public ���� ����!
	}
	

}