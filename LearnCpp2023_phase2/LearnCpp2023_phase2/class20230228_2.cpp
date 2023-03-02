/*
예외처리

1. mutable 
읽기 전용함수에서 쓰기를 해야하는 특수한 경우가 있을 수 있잖아. 
이때 해당 맴버를 mutable키워드 붙여서 선언하면 읽기 전용함수에서도 이 맴버 변수는 쓰기가 가능하다.
	mutable int m_i;		// void func () const {m_i = 10;}
const cast랑은 다른거임

2. try catch
int iN1 = 0, iN2=3;
cout << iN2/iN1<<endl;	//0나누기하면 당연히 문제 생김 
cout << iN2%iN1<<endl;	//0나누기하면 당연히 문제 생김
이거 그냥 프로그램 종료됨. 
이걸 잡기 위해 try-catch쓸수있음. 물론 조건문으로도 할수있지만 그냥 이렇게 쓰면 예외처리라는걸 한눈에 알수있으니까 

try{
	if(if 0==iN1) throw iN1;
	cout << iN2/iN1<<endl;
	cout << iN2%iN1<<endl;
}catch(int iN1){
	cout << "No"<<endl;
}


---------------------------------------------------------------
c++11의 몇가지 문법들

====
[ 오토키워드 ]
사용자가 직접 타입을 지정하지 ㅇ낳아도 컴파일러가 맞는 타입을 찾아주는 키워드 
auto s = 20ll;	// 8바이트 longlong	
suto i = 20;	// int 4바이트 
auto& r = i;	// int형 레퍼런스가 됨. 

보통 
stl컨테이너 반복문같은거 돌릴때 for안에 졸라긴반복자 타입쓰는거 힘들면 걍
for(auto iters= vec.being();..)이런식으로 씀. 
원래는 막 vector<int>::iterator iter = 이런식으로 쓰잖아. 

====
[ 범위 기반 for문 ]
원래 c#, 자바에서 제공했음 근데 c++11에서도 제공함

int iArray[5] = {1,2,3,4,5};
for(int i=0;i<8;i++)		// 이렇게 범위 초과하면 위험하잖아 
	cout << iArray[i];	

for(int i:iArray)	//이렇게 하면 알아서 그 범위만큼(길이 5)만 반복문 실행함. 
배열의 인덱스 범위를 넘어가는 위험한 행동을 방지할 수 있따. 

더 많이 쓰는 곳은 stl에서 쓴다. 
for(auto i:vec) //이렇게 쓴다. 반복자 쓸일도 없고 좐나 편함 

====
[유니폼 초기화]
{}로 초기화 하는거 ㅣ것도 c++11에서 나온거임 
int iArray{1,2,3,4,5}
동작은 대입을 통해 초기화 하는게 아니라 메모리 할당하면서 하는..이거 전에 필기한거 찾아보셈 
사용자 정의 타입(구조체 같은거) 유니폼초기화로됨 알지?
tagInfo tInfo{1,20f,10};	

class CTest
{
private:
	
public:	
	CTest(): {}	// 필기 보고 
}

CTest ct{{10,20}};	// 인자값이 잇는 생성자가 있으면 이렇게도 가능 




*/


#include "stdafx.h"
using namespace std;

