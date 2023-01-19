#include <iostream>
#include "study_staticVariablePlus.h"

using namespace std;

//--------------------------------------------------[ static �ƴ� �������� (extern) ]--------------------------------------------------------------

// ( �ֳ״� �⺻������ �̷��� ������ ���Ͽ��� extern���� ���� �����൵ ��� ������ �������̴�. )

/*int world_v_;			 ��� study_staticVariablePlus.h �� world_v_���� ������ �̸��� ���� �ٸ� ���� ��. -> �׷��� ������ ���ʿ� ������ �Ұ�����. ���� ������ ������ ������ ������ ����� �����ϱ�.
																								    �̰� ���� study_staticVariablePlus.h �� int world_v_�� ��ġ�°��� */
extern int world_v_;	// ��� study_staticVariablePlus.h �� world_v_���� ������ ���� �޸𸮸� ���� ��.

/*extern int world_extern_v_ = 10;			��� study_staticVariablePlus.h���� �̹� exturn int world_exturn_v_�� �����ϰ�, �ʱ�ȭ ���� �߱⶧����, �װ� �������ȴ�. 
											���� ���⼭ �ѹ��� ���� + �ʱ�ȭ�� �ϸ� ���� ������ ���� �ʱ�ȭ�� ������ �ϴ� ���� �ȴ�. �׷��� ������. */
extern int world_extern_v_;					// h���Ͽ��� �̹� extern int world_extern_v_;�� ���� + �ʱ�ȭ ���� -> �׷��ϱ� ��� ��������� ������ ���� �޸𸮸� ���� ��. 

//---------------------------------------------------------[ static �������� ]-------------------------------------------------------------------

extern int world_static_v_;					/* static���� ����� ���������� extern ���� ����. �ٵ� �ܺο����� �ȵȴٰ� ���ݾ�. �װŴ� �б� ������ ������
												�б� -> �ٸ� ���Ͽ��� �д� ���� ���� �ȵ�
												���� -> �ٸ� ���Ͽ��� ���Ⱑ �ȵ�	= �ܺ� ������ �ȵ�. 
												
												+ static�� ���, �̷��� ����Ϸ��� ���Ͽ��� exturn������ �����ָ� �б� ���� �ȵ�. �ƿ� ������ �ִٴ°� �ν����� ����. 
											*/

//-----------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	
	world_v_ = 10;		// ���⼭ world_v_�� ���� ���� �翬�� study_staticVariablePlus.h�� world_v_���� ���� �ٲ�°���. ���� �޸� ���°Ŵϱ�.
	cout << "[read in cppfile] world_v_: " << world_v_ << endl;
	Display_worldInfo();	// ���⼭ world_v_�� 10���� ���� �ٲ���־����. 

	world_extern_v_ = 10;		
	cout << "[read in cppfile] world_extern_v_: " << world_extern_v_ << endl;
	Display_worldInfo();	

	/* world_static_v_ = 10;													// static�̶� -> �ܺ� ������ �� �� ����. */
	cout << "[read in cppfile] world_static_v_: " << world_statc_v_ << endl;	//			    -> �б�� static�̶� ���� ( ���� extern ������ �������ϱ� �б�� �Ǵ°��� )
	Display_worldInfo();
}