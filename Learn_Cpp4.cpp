/* content
- function pointer
- typedef
*/
#include <iostream>
using namespace std;

/* 정의된 함수는 프로그램이 실행되면 메인메모리로 올라간다. 
함수의 이름 = 메모리에 올라간 함수의 시작 주소가 된다. = constant pointer(주소값을 변경할 수 없는 포인터) = function pointer
int Func (int a){} // 함수 원형
int (*Func) (int ){} // 함수 포인터  */

/*함수포인터를 선언하거나, 함수의 paramater로 넘겨줄때마다 번거롭게
int(*Func)(int,int)이런식으로 쓰는게 귀찮으니까 typedef를 사용함*/

typedef int (*FuncPointer)(int,int); // 이렇게 하면 이제부터 int (*calc)(int,int); 이거를 FuncPointer라고 쓸 수 있다.

int Add(int,int); 
int Sub(int,int); 
int Mul(int,int); 
int Calc(int,int,int (*func)(int,int)); // typedef 사용안함
int Calc2(int,int,FuncPointer); // typedef 사용함


int main(){
    //typedef 사용안함
    int(*calc)(int, int) = NULL; //함수 포인터 선언 
    calc = Add; // 함수 포인터에 특정 함수 주소 넣기 
    int result;
    result = Calc(5,7,calc);
    cout << result <<endl;

    //typedef 사용함
    FuncPointer calc2 = NULL;  //함수 포인터 선언 
    calc2 = Mul; // 함수 포인터에 특정 함수 주소 넣기 
    result = Calc(5,7,calc2);
    cout << result <<endl;

    return 0;
}

int Add(int a, int b){return a+b;} // 함수 원형
int Sub(int a, int b){return a-b;}
int Mul(int a, int b){return a*b;}
//typedef 사용안함
int Calc(int a, int b, int (*func)(int,int)){return func(a,b);} // 인자로 function pointer 넘겨주기 
//typedef 사용함
int Calc2(int a, int b,FuncPointer calc){return calc(a,b);} // 인자로 function pointer 넘겨주기 
