/*
struct���� �������� ������ �Ẹ�� 
=> class�� �Ȱ���. 
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
	//t1.pri_Data = 10;	// private�̴ϱ� �ܺ����پȵ�
	//t1.pri_Display(); // private�̴ϱ� �ܺ����پȵ�
	t1.pub_Display();
}