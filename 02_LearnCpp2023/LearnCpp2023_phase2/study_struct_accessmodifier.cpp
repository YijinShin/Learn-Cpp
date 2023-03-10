/*
struct에서 접근제어 지시자 써보기 
=> class랑 똑같다. 
*/

#include "stdafx.h"

using namespace std;

struct tagTest {
private:
	void pri_Display() { cout << "private" << endl; }
	int pri_Data;
public:
	void pub_Display() { cout << "public / " << pri_Data<< endl; }
	int pub_Data;
};

int main() {
	tagTest t1;
	//t1.pri_Data = 10;	// private이니까 외부접근안됨
	//t1.pri_Display(); // private이니까 외부접근안됨
	t1.pub_Display();
}