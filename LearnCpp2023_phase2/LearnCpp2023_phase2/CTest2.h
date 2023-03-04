#pragma once
#include "stdafx.h"
using namespace std;

#include "CTest1.h"

class CTest2 {
public: 
	CTest2() { cout << "CTest2 »ý¼ºÀÚ" << endl; }
	void Test(CTest1* ct1) { cout << "..." << endl; }
private:
	//CTest1 m_ct1;
};