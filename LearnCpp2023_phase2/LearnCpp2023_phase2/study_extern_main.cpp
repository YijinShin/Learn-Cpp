#include "stdafx.h"
#include "study_extern_CTest.h"

int g_iData;				// �Ϲ� �������� ���� ( �����̶� static�ƴ϶� 0���� �ʱ�ȭ �� )
int g_iSrc;					// �Ϲ� �������� ���� ( �����̶� static�ƴ϶� 0���� �ʱ�ȭ �� )
static int g_iData_static;	// static ��������	( �����̶� 0���� �ʱ�ȭ ��. ������ static�̶� �̰� �Լ� �ȿ� �����ص� 0�ʱ�ȭ�� )

int main() {
	CTest t1;
	t1.Draw();
}