/* [ C++ study with TCP school 52part]
topic: ������ �����ε� 
	

* ������ �����ε� 
	�Լ� �����ε�ó�� ���� �����ڸ� �ٸ� ������� ����ϱ� ���� �ٽ� �����ϴ� ��. 
	����, �����ε��� �ؼ� ���Ÿ� class�ȿ��� �����ε��� �ؼ� ���� ��찡 ��κ��̴�. 
	(ex_ A��� Ŭ���� �ȿ����� - �� �׳� �� ���� -�� �ƴ϶� ���ڿ����� �ٸ��κ��� ã�� �����Ѵٰų�.. �� �׷�) 

* ������ �����ε� ���� ���
	 
	 1. ����
	 operator[������]([�Ű����� ���])

	 2. ���� ������ ��ġ
		- Ŭ������ �ɹ��Լ��� ����
		- �����Լ��� ����

* ������ �����ε� ����
	- �����ϰų� �� �Լ��̸��� �Ƚᵵ��. 
	

* �����ε��� �� �� �ִ� �����ڰ� �ְ�, 
* �� �� ���� �����ڰ��ְ�,
* �ɹ� �Լ��θ� �� �� �ִ� �����ڰ��ִ�.
* (�ڼ��Ѱ� http://www.tcpschool.com/cpp/cpp_operatorOverloading_constraint) ���� ���� 

* ���� ���ο� �����ڸ� ������ ���� ����.

*/

#include <iostream>

using namespace std;


class Position {
private:
	float iX_private_;
	float iY_private_;

public:
	float iX_public_;
	float iY_public_;
	int iData_;
	Position(float iX =1.f, float iY=2.f, int iData = 1); //������

	Position operator-(const Position& pos);	// Ŭ���� ������ ������ ������ �����ε�
	friend Position operator+(const Position& p1, const Position& p2);// ���� �Լ��� ������ ������ �����ε� (���� �Լ��� �����ߴµ� friend �Ⱥ��̸� ������ 
	int operator*(int iTemp) const;

	void DisplayPos();
};


int main() {

	Position p1(10, 0), p2(0, 0);

	Position p3 = p1 - p2;
	p3.DisplayPos();

	Position p4;
	/* �����ε� ������ ����� �� ������ ��
		int iResult = 5 * p4;	// �̷������� �����ε��� �������� ���ʿ�, �ش� �����ε� �Լ��� ȣ���ϴ� Ŭ���� ��ü�� ���;���  */
	int iResult = p4 * 5;
	cout << "* �����ε� ������ ���: " << iResult << endl;

}

Position::Position(float iX, float iY, int iData) {
	iX_private_ = iX;
	iY_private_ = iY;
	iX_public_ = iX;
	iY_public_ = iY;
	iData_ = iData;
}


Position Position::operator-(const Position& pos) {
	
	//friend �Ⱦ� ���� ����� ������ �����ε� �Լ��� private ������ �����Ϸ��� �ϸ� ������. 
	return Position((iX_private_ + pos.iX_private_) / 2 , (iY_private_ + pos.iY_private_) / 2);


	return Position((iX_private_ + pos.iX_private_) / 2, (iY_private_ + pos.iY_private_) / 2);
	
}

Position operator+(const Position& p1, const Position & p2) {

	// ���������� ���� ����. 
	return Position((p1.iX_public_ + p1.iX_public_) / 2, (p2.iY_public_ + p2.iY_public_) / 2);

	//friend�� �ֱ� ������ private ���� ���� 
	return Position((p1.iX_private_ + p1.iX_private_) / 2, (p2.iY_private_ + p2.iY_private_) / 2);
}

void Position::DisplayPos() {
	cout << "(x,y): " << iX_private_ << ", " << iX_private_ << endl;
}

int Position::operator*(int iTemp) const{
	return iTemp * iData_;
}