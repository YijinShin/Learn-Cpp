/*content
- reference(참조자)
- default argument (디폴트 인수)*/

#include <iostream>
using namespace std;

void add(int,int);
void addRef(int&,int&);

// 디폴트 인수 
// 이게 함수 원형이면 ch와 z에는 값 안 넣고 함수 호출해도 자동으로 a,5가 들어감. 물론 덮어쓸 수 있음. 
void Display(int,int,char ch = 'a', int z=5);
//밑에 함수 정의한거에서는 파라미터 변수이름까지만 적고, 여기서 함수 원형 선언할 때 디폴트 값을 넣어야한다.

int main(){
    int a,b; //변수 
    int& aRef = a; //참조자
    // 참조자는 대상 변수와 같은 메모리 위치를 참조함 &a == &aRef
    // 참조자를 이용해 값을 바꾸면 대상 변수값도 바뀜 
    // 함수 paramater로 전달할 때 주로 사용한다.
    a=4;
    b=6;
    cout<<a<<" , "<<b<<endl;
    add(a,b);
    cout<<a<<" , "<<b<<endl;
    addRef(a,b);
    cout<<a<<" , "<<b<<endl;

    Display(1,2);
    Display(1,2,'b');
    Display(1,2,'c',10);
    //Display(1,2,,10);  인자를 건너뛸 수는 없음. 

}
// 여기서 함수가 받은 a,b는 위에서 넘겨준 a,b와 메모리가 다르다. 변수 이름만 같은것. 
// 따라서 함수내에서 a,b값을 바꿔도 main의 a,b에 영향이 가지 않는다.  
void add(int a, int b){
    a++;
    b++;
}
//여기서 a,b는 main의 a,b와 완전히 같은 메모리주소를 가리킨다. 때문에 여기서 값을 바꾸면  main의 a,b도 당연히 바뀐다. 
void addRef(int& a, int&b){
    a++;
    b++;
}
// 어떤 함수에서 구조체를 변경할일이 없다면 const 키워드를 사용해서 원본 구조체에 대한 변경을 허용하지 않는 것이 좋다. 
void func( const int& a){

}
void Display(int a ,int b,char ch, int z){
    cout<< a<<" , "<<b<<" , "<<ch<<" , "<<z<<endl;
}