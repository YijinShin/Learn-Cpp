/*
탬플릿: 함수나 클래스가 각기 다른 자료형에서도 동작할 수 있도록 만드는 문법
	기능은 결정되어있지만 자료형은 결정되어있지 않은걸 탬플릿이라고함. 

함수 탬플릿 = 탬플릿
			함수 모양을 띈 탬플릿 
탬플릿 함수 = 함수 
			함수 탬플릿으로 찍어낸 함수 = 탬플릿 함수 ? 이거 맞음? ㅋㅋㅋㅋ 확인해보기 


함수 탬플릿 만들고나서 우리가 만약에 T를 int형으로 치고 호출해 => 그럼 이때 인스턴스화가 일어남


탬플릿 특수화: 특정 자료형에 대해 예외적으로 동작하는 원리를 만드는 문법
원형 탬플릿이 있다는 조건 하에 작성할 수 있는 문법


단항 템플릿, 이항 템플릿(2개 이상이면 걍 다 이항이라고 부름 ㅋㅋ) 

예시 코드 오류 찾기(댕글링포인터) => 사본에 대한 delete인지, &의 delete인지 문제였음. 
메크로로 하던 safe delete를 이제 탬플릿으로 만들어서 할거다. 매개변수는 &로 받고 꼭. 이거 *로 해도 nullptr넣는게 문제가 되어ㅓ서 안됨. 
무조건 safe delete는 &로 해야함. *는 delete는 되는데 댕글링포인터 처리는 안됨. 

*/

// 함수 탬플릿 => 탬플릿 함수랑 함수 탬플릿이랑 헷갈리지 말기. 
					
#include "stdafx.h"
using namespace std;


#define SAFE_DELETE(p) if(p) { delete p; p = nullptr;}


class CObj {


};

template<typename T>
void Safe_Delete(T& Temp)	// 문제 없음. 
//void Safe_Delete(T* Temp)	// 댕글링 포인터 문제 발생 
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}


int main() {
	CObj* obj = new CObj;
	Safe_Delete<CObj*>(obj);
	//Safe_Delete<CObj*>(&obj);
}
