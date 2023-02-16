#include "stdafx.h"

using namespace std;




/* ��� ������ �� Ŭ���� */
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
		//m_iPrivate_Parent = 10;	// �θ��� private�� ���� �Ұ���	(<< friend���� ����)
		m_iProtected_Parent = 10;	// �θ��� protected�� ���� ����
		m_iPublic_Parent = 10;		// �θ��� public�� ���� ����
		CParent::Draw();			// �θ�� �̸��� �Ȱ��� �Լ��� �ڳ࿡�� �־ Ŭ���� ���� ���� ������. �׷��� ������ Ŭ���� �� �Ƚᵵ��.
	}
	void Draw() { 
		cout << "CFriendB" << endl; 
	}
};


/* ģ�� ������ �� Ŭ���� */
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
	void Access(CFriendA fa) {	/* friend�� ���� ������ �� class���� ������ ����ϴ� ���̱� ������ friendŬ������ �ɹ��� ������ �Ѵٸ� ���� friendŬ������ ������ ��ü�� �����ؾ��Ѵ�.
								   ����� �ڳ� ��ü�� ����� �˾Ƽ� �θ� ��ü���� ��������� ��ü�� �޸𸮸� �Ҵ��ϴ°����� friend�� ������ �� ��ü�� �ʿ���. */
		fa.m_iPrivateA = 10;	// ��ü �̸��� ���� friendŬ������ private�ɹ� ���� ����
		fa.m_iProtectedA = 10;  // ��ü �̸��� ���� friendŬ������ protected�ɹ� ���� ����
		fa.m_iPublicA = 10;		// ��ü �̸��� ���� friendŬ������ public�ɹ� ���� ����
		fa.Draw();				// ��ü �̸��� ���� friendŬ������ public�ɹ� ���� ����
	}
	void Draw() {
		cout << "CFriendB" << endl; 
	}
};



int main() {
	/* Ŭ���� ũ�� �׽�Ʈ */
	{
		/* ��Ӱ��� Ŭ���� */
		CParent p1;
		CChild c1;
		cout << sizeof(p1) << endl;		// 12 :(3*4)
		cout << sizeof(c1) << endl;		// 24 :�ڳ���(3*4) + �θ���(3*4)

		/* ģ������ Ŭ���� */
		CFriendA fa;
		CFriendB fb;
		cout << sizeof(fa) << endl;		// 12 :(3*4)
		cout << sizeof(fb) << endl;		// 12 :(3*4)
		/* friend�� ������ ����ϴ� �� �� ���� �޸𸮻� ģ��class�� �������� �ʴ´�. */
	}

	/* �ɹ� ���� �׽�Ʈ */
	{
		/* ��Ӱ��� Ŭ���� */
		CChild c1;	// (public���� ��ӹ���)
		
		c1.m_iPublic_Parent = 10;	//�θ��� public �ɹ� ���� ��밡�� 
		c1.CParent::Draw();			//�θ��� public �ɹ� �Լ� ��밡��
		

		/* ģ������ Ŭ���� */
		CFriendA fa;
		CFriendB fb;
		// fb.m_iPublicA = 10;	// ERROR ģ�����迡���� ������ �ɹ� �Լ��� �ɹ� ������ fa.m_iPublicA = 10 �̷��� �ܺο��� ������ �� ����. 
	}

}