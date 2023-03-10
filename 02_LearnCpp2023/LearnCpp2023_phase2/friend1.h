#pragma once
#include "stdafx.h"
#include "friend2.h"
using namespace std;

//class Friend2; => 여기서는 어차피 상호 참조 안하니까 그냥 헤더에서 #include 해줘버림 

class Friend1 {
private:
	int i_friend1;
public:

	//void Draw(Friend2& f2);
	void Draw(Friend2& f2) {
		cout << "F2: " << f2.i_friend2 << "\tF1: " << i_friend1 << endl;
	}
};