#pragma once
#include "stdafx.h"
#include "friend2.h"
using namespace std;

//class Friend2; => ���⼭�� ������ ��ȣ ���� ���ϴϱ� �׳� ������� #include ������� 

class Friend1 {
private:
	int i_friend1;
public:

	//void Draw(Friend2& f2);
	void Draw(Friend2& f2) {
		cout << "F2: " << f2.i_friend2 << "\tF1: " << i_friend1 << endl;
	}
};