/*content
스마트 포인터(smart pointer)
    - c++에서 new 키워드를 사용해서 동적으로 할당받은 메모리는 무조건 delete를 사용해 지워야만한다.  
    - mem leak 없게 하려고 스마트 포인터를 제공한다. 
    - 포인터처럼 동작하는 클래스 템플릿. 사용이 끝난 메모리를 자동으로 해제해준다. 

    동작
    - 일단 new를 통해 Raw pointer(기본 포인터)가 실제 메모리를 가리키도록 한다. 
    - 기본 포인터를 스마트 포인터에 대입한다.
    - 포인터의 수명이 다하면 소멸자가 자동으로 delete사용해서 메모리 해제한다. 

    포인터 종류 (c++11 부터 auto_ptr가 삭제되고 여러 종류가 생김)
    - unique_ptr
        하나의 스마트 포인터만이 특정 객체 소유 가능. 이 포인터는 해당 객체의 소유권을 
        가지고잇을 때만, 소멸자가 해당 객체를 삭제 할 수 있다. 
        <memory> 헤더파일에 속한 표준 포인터이다.
    - shared_ptr
    - weak_ptr

    * 소유권을 이전한다 = a가 b를 복사하는게아니라 소유한다. 
        이 경우 복사와 다르게 a에 새로 메모리를 할당하지 않아도 된다. 생성자를 다시 호출하지 않아도 된다.
        이걸 해주는 함수가 move()
*/

#include <iostream>
#include <memory>
using namespace std;

int main(){
    // 소유권에 관하여 
    int d = 10;
    int c = d; // 이건 복사 
    cout<< d<<","<<c<<endl;
    cout<< &d<<","<<&c<<endl;
    
    int* a = new int(5);
    int* b = move(a); //  이건 소유권 이전. 
    cout<< *a <<","<< *b <<endl;
    cout<< a<<","<<b<<endl; // 둘이 아예 주소도 같다. 

    //1. unique_ptr
    unique_ptr<int> ptr1(new int(5)); //1. 포인터 변수 선언 : int형 unique_ptr인 포인터 변수 ptr1을 선언하고, 5로 초기화 
    auto ptr2 = move(ptr1); // ptr1에서 ptr2로 소유권을 이전 
}