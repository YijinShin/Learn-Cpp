/* class�� public, protected, private ����
	


*/

#include <iostream>

using namespace std;


class P {
private:
	int P_private_mem;
protected:
	int P_protected_mem;
public:
	int P_public_mem;
};

class C : public P{
private:
	int C_a;
public:
	void C_func() {
		//cout << P_private_mem;	//private �Ұ���
		cout << P_protected_mem;	// protected ����
		cout << P_public_mem;		// public ����
	};

};

int main() {
	
}