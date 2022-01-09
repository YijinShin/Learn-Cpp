/* content
- function overloading
- function signature
- 인라인 함수 
- 메크로 함수(macro)
*/

#include <iostream>
using namespace std;

/*function overloading : 같은 이름의 함수 중복 정의하기 
function signature: 함수의 매개변수 리스트 
즉, 함수 오버로딩 = 서로 다른 시그니처르 갖는 여러 함수를 같은 이름으로 정의하는 것 */

void Display(int);
void Display(int,int);
void Display(char,char);

/* inline함수 
    C++에서 함수를 호출하려면 꽤 복잡한 과정을 거치게 되므로 약간의 시간이 걸린다. 
만약 함수를 실행하는 시간자체가 아주 길면 함수 호출에서 걸리는 시간은 별로 문제가 되지 않는다.
그러나 아주 간단한 함수라서 실행 시간이 아주 짧다면, 함수 호출하는데 걸리는 시간이 부담될 수 있다. 
이런 경우 inline함수를 사용한다. 
    inline함수는 호출될 때 일반적인 함수 호출 과정을 거치지 않고, 함수의 모든 코드를 함수가 호출된 자리에 
삽입해서 실행하는 방식의 함수이다. 
inline function은 
    inline함수는 보통 크기가 작으므로 함주 원형자리에 함수의 본체까지 정의하는 경우가 많다. */
inline void Print(int c){cout<<"inline: "<< c<<endl;}

/*c에서는 c++의 inline과 비슷한 기능으로 메크로 함수를 사용한다. 
#define 선행처리 지시문에 인수로 함수를 정의를 전달해서 함수처럼 동작하는 메크로를 만드는 것.*/
#define ADD(a,b) ((a)+(b))

int main(){
    //Display("a","b"); 이거는 paramater 타입때문에 에러남 
    Display(5);
    Display(1,2);

    //inline함수
    Print(3);
    
    //메크로 함수
    int result = ADD(4,5);
    cout<< " 메크로 함수" <<result<<endl;
    

    return 0;

}
void Display(char a, char b){ cout<< a <<" , "<<b<<endl;}
void Display(int a){ cout<< a <<endl;}
void Display(int a, int b){ cout<< a <<" , "<<b<<endl;}
