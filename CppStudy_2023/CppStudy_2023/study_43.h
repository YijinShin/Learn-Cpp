#pragma once		// 헤더파일에는 이게 꼭 있어야함

#include <iostream>	
using namespace std;

namespace Test
{
	string name;
	
	void Display() {
		cout << "Test1) 당신의 이름은 " << name << "입니다." << endl;
	}

}

namespace Test2	// 한 헤더파일안에 당연히 여러 namespace존재해도 괜춘. 
{
	string name;
	
	void Display() {
		cout << "Test2) 당신의 이름은 " << name << "입니다." << endl;
	}
}

