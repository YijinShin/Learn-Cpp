#pragma once
#include "stdafx.h"
using namespace std;

#include "CTest2.h"

class CTest1 {
public:
	CTest1() { cout << "CTest1 »ý¼ºÀÚ" << endl; }
	void Test(CTest2* ct2) { cout << "..." << endl; }
private:
	//CTest2 m_ct2;
};