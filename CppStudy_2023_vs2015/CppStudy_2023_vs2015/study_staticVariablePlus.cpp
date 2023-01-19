#include <iostream>
#include "study_staticVariablePlus.h"

using namespace std;

//--------------------------------------------------[ static 아닌 전역변수 (extern) ]--------------------------------------------------------------

// ( 애네는 기본적으로 이렇게 쓰려는 파일에서 extern으로 선언 안해줘도 사용 가능한 변수들이다. )

/*int world_v_;			 얘는 study_staticVariablePlus.h 의 world_v_전역 변수와 이름만 같고 다른 애인 것. -> 그렇기 때문에 애초에 선언이 불가능함. 같은 선언을 가지는 변수를 여러개 만들수 없으니까.
																								    이거 쓰면 study_staticVariablePlus.h 의 int world_v_와 겹치는거임 */
extern int world_v_;	// 얘는 study_staticVariablePlus.h 의 world_v_전역 변수와 같은 메모리를 쓰는 것.

/*extern int world_extern_v_ = 10;			얘는 study_staticVariablePlus.h에서 이미 exturn int world_exturn_v_를 선언하고, 초기화 까지 했기때문에, 그게 원조가된다. 
											따라서 여기서 한번더 선언 + 초기화를 하면 같은 변수에 대해 초기화를 여러번 하는 격이 된다. 그래서 에러남. */
extern int world_extern_v_;					// h파일에서 이미 extern int world_extern_v_;를 선언 + 초기화 했음 -> 그러니까 얘는 헤더파일의 원조와 같은 메모리를 쓰게 됨. 

//---------------------------------------------------------[ static 전역변수 ]-------------------------------------------------------------------

extern int world_static_v_;					/* static으로 선언된 전역변수도 extern 으로 가능. 근데 외부연결이 안된다고 하잖아. 그거는 읽기 쓰기의 차이임
												읽기 -> 다른 파일에서 읽는 것은 문제 안됨
												쓰기 -> 다른 파일에서 쓰기가 안됨	= 외부 연결이 안됨. 
												
												+ static인 경우, 이렇게 사용하려는 파일에서 exturn선언을 안해주면 읽기 조차 안됨. 아예 변수가 있다는걸 인식하지 못함. 
											*/

//-----------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	
	world_v_ = 10;		// 여기서 world_v_에 값을 쓰면 당연히 study_staticVariablePlus.h의 world_v_값이 같이 바뀌는거임. 같은 메모리 보는거니까.
	cout << "[read in cppfile] world_v_: " << world_v_ << endl;
	Display_worldInfo();	// 여기서 world_v_는 10으로 값이 바뀌어있어야함. 

	world_extern_v_ = 10;		
	cout << "[read in cppfile] world_extern_v_: " << world_extern_v_ << endl;
	Display_worldInfo();	

	/* world_static_v_ = 10;													// static이라서 -> 외부 파일이 쓸 수 없다. */
	cout << "[read in cppfile] world_static_v_: " << world_statc_v_ << endl;	//			    -> 읽기는 static이라도 가능 ( 위에 extern 선언을 해줬으니까 읽기라도 되는거임 )
	Display_worldInfo();
}