#include "stdafx.h"	// 미리컴파일된 헤어파일이 존재하는이상 모든 cpp파일에는 무조건 써야함. 
#include "TestHeader_1.h"


/*
이 PCH폴더 안에있는 애들은 미리정의된 헤더, 그냥 헤더 사용법 알아보려고 만든 코드들이다.
이거 테스트하고싶으면 프로젝트 속성에서 미리정의된 헤더 > "만들기"로 해야함.

미리컴파일된 헤더를 사용한다고 한 이상 모든 .cpp파일에는 직접적으로 #include "stdafx.h"를 써야한다.
그러기에는 이미 생성되어있는 .cpp파일이 많아서 그냥 이거 전체를 컴파일에서 빼고, 설정도 미리컴파일된 헤더 사용안함으로 바꿔놓은거임. 



*/

int main() {


	cout << "This is Main .cpp " << endl;

	TestHeaderClass1 TH1;

	TH1.Display();
}