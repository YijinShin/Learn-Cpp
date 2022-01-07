//include, define은 선행처리기에 의해 처리되는 선행처리문이다. 
#include <iostream> //preprocess
#define MAXNUM // preprocess

//C는 .h 헤더파일을 사용함. 그러나 C++은 헤더파일 확장자 사용안함. 
// c 헤더파일은 앞에 c를 붙여서 c++에서 사용가능
#include <cmath> // c에서는 그냥 math

//name space는 c에는 없는, c++에만 존재하는 기능 
// 클래스, 함수, 변수 등은 std라는 namespace에 저장되어있다. 
//iostream은 c++의 표준 헤더파일인데, 이 안의 요소를 쓰려면 std::cout 이런식으로 써야한다. 
// 이게 싫으면 
using namespace std; // 이렇게 미리 명령문 추가하면 됨. std namespace에 속한 정의들은 ns이름 안붙여도 사용가능. 

int main(){
    
    /*포인터
    * : 참조 연산자. 포인터자체 
    & : 주소 연산자. 해당 변수의 주소값을 반환*/
    int n = 100;
    int *ptr = &n;
    int *ptr1, *ptr2; // 여러 포인터 선언 
    int arr[3]={1,2,3};
    int *ptr_arr = arr; // 배열의 가장 첫 메모리 주소 
    cout << ptr_arr[0] << endl; //배열을 통한 요소 접근 cout << arr[0];와 같다. 
    cout << *(arr+0) << endl; // 배열의 이름으로, 포인터 연산을 해서 첫번째 인자 출력 
    cout << *(arr+1)<< endl; // 배열의 이름으로, 포인터 연산을 해서 두번째 인자 출력 
    int sizeP = sizeof(ptr_arr); // 포인터, 즉 주소값 자체의 크기가 반환됨 8
    int sizeA =sizeof(arr); // 배열길일가 반환됨. 12 (4*3)
    cout<<"hello"<<endl;

    /* 동적할당 
    new연산자: c에서 malloc, calloc으로 메모리 동적할당함. c++에서는 new로 함. 
    delete 연산자: c에서 free()를 사용해 메모리를 반환함. c++에서는 delete로 반환*/
    int *ptr_int = new int; // 할당
    *ptr_int = 100;
    delete ptr_int; // 해제

    /* 문자열_ cin, get, ignore
    - cin: 띄어쓰기, tap, 캐리지 리턴 문자등을 모두 문자열의 끝으로 인식
    - get(): 띄어쓰기를 포함한 문자열을 전부 입력받을때 씀
    - ignore(): 정확히 size만큼만 읽는다. 이걸 안하면 name에서 20바이트 이상 썼을 때, */
    const int SIZE = 5;
    char name[SIZE];
    char memo[SIZE];
    char name2[SIZE];
    char memo2[SIZE];
    //cin_SIZE이상으로 name을 입력하면 메모를 못받고 종료됨, 띄어쓰기 안됨.
    cout<<"[only cin]"<<endl;
    cout<< "name: "; // print
    cin >> name; // intput
    cout << "memo:";
    cin >> memo;
    cout<<"your name:"<<name<<" / your memo:"<<memo<<endl<<endl;
    //get_SIZE이상으로 name을 입력하면 메모를 못받고 종료됨, 띄어쓰기도 문자열에 포함함. 
    cout<<"[get]"<<endl;
    cout<< "name: "; // print
    cin.get(name2, SIZE).get(); // intput
    cout << "memo:";
    cin.get(memo2,SIZE).get();
    cout<<"your name:"<<name2<<" / your memo:"<<memo2<<endl<<endl;
    // ignore()_ name을 size이상으로 입력해도 size만큼만 읽어오고 버림 
    cout<<"[ignore]"<<endl;
    cout<< "name: "; // print
    cin.get(name, SIZE).ignore(SIZE,'\n'); // intput
    cout << "memo:";
    cin.get(memo,SIZE).ignore(SIZE,'\n');
    cout<<"your name:"<<name<<" / your memo:"<<memo<<endl<<endl;
    
    return 0;
}