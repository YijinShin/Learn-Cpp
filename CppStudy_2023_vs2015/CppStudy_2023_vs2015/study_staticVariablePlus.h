/* [정리]


* exturn
	- 원조 전역변수(즉, 선언과 초기화를 모두 하는 쪽에서는)에는								  -> 써도, 안써도 상관없음. 
	- 다른 파일에 원조 전역변수가 있는데, 그거랑 같은 메모리를 참조하려는 전역변수를 만드는 경우 -> 필수! 

* static
	외부연결이 안되는건 맞는데 
	- 사용하려는 파일에서 extern 선언을 안했으면  -> 읽기, 쓰기 모두 안됨
	- 사용하려는 파일에서 extern 선언을 했으면		-> 읽기는 가능	
												-> 쓰기는 불가능 
*/


#pragma once
#include <iostream>
using namespace std;


// 전역변수 
extern int world_extern_v_ = 0;		/* [exturn의 기본적인 의미 : 다른 파일에서, 이미 이 변수를 전역으로 선언하고 있으니 -> 그 변수와 메모리를 공유해서 쓰겠다.]
										
										즉, 다른 파일에서 이미 int world_exturn_v_ 라는 변수가 전역으로 선언되어있는 경우 
												-> 초기화 필요없고, 그 변수와 같은 메모리를 참조해서 쓰게 됨. 
										
										여기서 int world_exturn_v_가 처음 전역으로 선언된 경우 
												-> 초기화 해야지 다른 파일에도 얘를 쓸 수 있다. 
												이 경우, 얘가 결국 원본값(?) 같은 애가 되므로, exturn 안써도 괜찮음. 
									*/
int world_v_;						/*전역변수라서 data영역에 할당되므로 0으로 초기화됨 -> 다른 파일에서 exturn int world_v_; 라고 전역선언을 하면 얘랑 같은 메모리를 공유하는거고,
																					 -> 다른 파일에서 int world_v_;라고 전역 선언을 하면 얘랑은 다른 메모리를 쓰는거임. 걍 동명이인 같은..*/
static int world_statc_v_(20);			// 전역변수라서 data영역에 할당되므로 0으로 초기화됨.



void Display_worldInfo() {
	//int local_v_;					// local 변수인 경우 초기화 안해줘서 에러남 (stack영역에 저장되기 때문에 자동초기화가 안된다.)
	int local_v_(0);				
	static int local_static_v_;		// static의 경우 로컬변수라도 data영역에 할당되므로 0으로 초기화됨.

	cout << "[world_v_, world_extern_v_,  world_static_v_] : " << world_v_ << "," << world_extern_v_ << "," << world_statc_v_ << endl;
}