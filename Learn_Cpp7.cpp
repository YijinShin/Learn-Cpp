/* content
- scope(유효범위)*/
#include <iostream>
using namespace std;

/*scope란 해당 변수가 사용될 수 있는 범위를 말한다.(ex_함수내에서 선언된 변수는 함수내에서만 사용가능)
linkage: 해당 변수를 사용할 수 있는 파일의 접근 가능 여부
    - external linkage: 여러 파일에서 사용가능, internal linkage: 하나의 파일에서만 사용가능. 
    - 함수내에서 선언된 변수는 해당 함수에서만 사용이 가능하므로 linkage를 가지지 않는다. 
- automatic variable: 자동 변수 (일반적으로 선언하는 대부분의 변수. stack 영역에 저장. 초기화 하지 않으면 쓰레깃값으로 초기화됨. local variable과 같은 의미)
- register variable: 레지스터 변수 (register 키워드를 붙여서 선언한 변수. CPU의 register 메모리에 저장되어 빠르게 접근 가능. 그러나 
   컴터의 레지스터는 워낙 작은 크기의 메모리이므로 선언이 어려울 수 있음.)
- static variable: 정적 변수 (프로그램 내내 유지되는 변수. 메모리상의 data 영역에 저장됨. 초기화 하지 않으면 0으로 초기화됨. )
    3가지 유형의 정적 변수 : 
        - 연결을 가지지 않는 정적변수: 블록내에서 static 사용 static int a
        - 내부 연결을 가지는 : global 영역에서 static 사용. 해당 파일에서만 사용가능. 
        - 외부 연결을 가지는 :  global 영역에서 static 사용없이 정의. 다른 파일에서도 사용가능 */

int a; // 외부 연결을 가지는 정적변수 ( = 전역변수 global, 외부변수 external)
static int b; // 내부 연결을 가지는 정적변수

int main(){
    static int c; // 연결을 가지지 않는 정적변수
    int d; // 자동변수(local variable)

    extern int a; // 외부 변수를 사용하기 위한 재선언 
}