/*content
- 오버라이딩 : 서로 다른 시그니처(1.함수이름, 2. 매개변수 개수, 3. 매개변수의 자료형)를 갖는 여러 함수를 같은 이름으로 정의하는 것
    맴버 함수 오버라이딩 
    파생 클래스는 기초 클래스의 맴버 함수도 상속받는데, 이때 상속받은거 그대로 써도 되고, 내용만 재정의 해서 써도 된다. 
    대신 이 경우 시그니처를 바꿀 수는 없다. 원형은 상속받은 것과 같아야하고, 내용만 바꿀수있다. 
    맴버 함수 오버라이딩 하는 방법
        1. 파생 클래스에서 직접 오버라이딩하는 방법
        2. 가상 함수를 이용해 오버라이딩하는 방법
    파생 클래스에서 오버라이딩 문제점
    일반적인 상황에서는 잘 작동한다. 그러나 클래스 객체를 포인터 변수로 선언할 때는 예상치 못한 결과 반환 할 수도 있다. 
    -> 이걸 해결하기 위해 virtual 사용 
        가상함수로 선언된 함수는 포인터가 가리키는 객체의 종류에 따라 호출되도록 설정됨. 
        따라서 이걸 쓰려면 기초 클래스의 맴버 함수 정의에도 같이 키워드 붙여야함 

- 다중상속
- 가상 함수 (virtual function)  
    파생 클래스에서 재정의 할 것으로 기대하는 맴버함수를 의미함. 
    가상함수는 자신을 호출하는 객체의 타입에 따라 실제 호출할 함수가 정해짐. 

- dynamic binding (동적 바인딩)
    함수를 호출하는 코드는 컴파일 타임에 고정된 메모리 주소로 변환된다. 이걸 정적 바인딩(static binding, early binding)이라고 한다. 
    가상함수를 제외한 모든 맴버 함수는 정적바인딩을 한다. (호출되면 고정된 메모리주소로 변환)

    가상함수는 컴파일러가 어떤 함수를 호출해야하는지 미리 알 수 없다. 얘는 고정된 메모리가 처음부터 있는게 아니라 프로그램이 실행될 때 객체가 결정된다. 
    컴파일 타임에 객체를 특정할 수 없기 때문에 런타임에 올바른 메모리 주소로 변환한다. 이걸 동적바인딩(dynamic binding, late binding)이라고 한다. 
    
    가상함수는 기본적으로는 정적바인딩이고, 
    기초 클래스타입의 포인터나 참조를 통해 호출될 경우 동적바인딩을 한다. 

- 가상함수 테이블 (virtual function table, vtbl)
    가상함수를 다루는 가장 일반적인 방식은 가상함수테이블이다. 
    컴파일러는 각각의 객체마다 가상 함수 테이블을 가리키는 포인터를 저장하기 위한 숨겨진 맴버를 하나씩 추가한다.
    가상 함수를 가지는 클래스에 대해 테이블을 하나씩 작성한다. 
    이 테이블에는 선언된 가상함수들의 주소가 저장된다. 

    가상함수를 호출하면 이 테이블에 접근해서 자신이 필요한 함수를 찾아서 그 주소값을 반환하게된다. 
    근데 동적 바인딩이 보다싶이 과정이 복잡해서 메모리 실행 속도에 부담을 준다. 그래서 기본적으로는 정적 바인딩을 쓰고,필요한 경우에만 가상으로 선언함.

- 가상 소멸자 
    C++에서 기초 클래스의 소멸자는 반드시 가상으로 선언해야한다. 
    만약 
    Person* p1 = new Student; 이렇게 선언하면 일단 p1이라는 Student가 동적으로 선언될것이다. (*이라서)
    이 상태에서 
    delete p1을 하면 person* 이기 때문에 ~Person() 소멸자가 호출된다. 
    그러면 student 객체에 동적으로 할당된 메모리는 정상적으로 해제되지 않는다. 
    따라서 
    virtual ~person()
    virtual ~studnet()
    이렇게 소멸자를 가상함수로 선언해서 delete p1하면 ~student()가 호출되도록 해야한다. 
    따라서 기초 클래스는 명시적으로 소멸자를 선언할 필요가 없어도 그냥 무조건 가상소멸자로 선언해야한다! 

*/


#include <iostream>
using namespace std;

//----------------------------------------------------
class baseClass1{};
class baseClass2{};
//다중 상속 
class derivedClass: public baseClass1, private baseClass2{};
//----------------------------------------------------



//base class
class Person{
    private:
        string name_;
        int age_;
    public:
        Person(const string& name, int age);
        //void ShowInfo(); 
        virtual void ShowInfo(); 
        virtual ~Person(); // 기초 클래스의 소멸자는 명시적으로 선언할 이유가 없어도 가상함수로 선언해야하기 때문에 이렇게 적어야한다. 
};

//derived class
class Student: public Person{
    private:
        int sid_;
    public:
        Student(int sid, const string& name, int age);
        //void ShowInfo(); // 상속받은 맴버 함수를 재정의 할 거라서 여기 함수 정의 해야함.
        // virtual 키워드를 붙여서 가상함수로 재정의 하면 포인터가 실제로 가리키는 객체에 따라 호출하는 대상을 바꿀 수 있게 된다. 
        virtual void ShowInfo(); 
};

int main(){
    Person p1 = Person("A", 10);
    Student s1(2102,"B",22); // 이렇게도 클래스 객체 선언가능 

    p1.ShowInfo(); // 여기서는 person의 함수가 호출되고,
    s1.ShowInfo(); // 여기서는 student의 함수가 호출된다. 
    s1.Person::ShowInfo(); //::(범위지정연산자)를 사용하여 어떤 클래스의 함수인지 지정가능. 

    cout<<"------------------------"<<endl;
    Person* ptr_person = &p1; // p1의 주소값을 저장하는 Person 포인터 변수 선언
    ptr_person->ShowInfo();
    ptr_person = &s1;
    ptr_person->ShowInfo(); 
    /* 둘다 Person의 함수가 불린다. 왜냐면 포인터 변수가 실제로 가리키는 객체의 타입을 기준으로 함수를 호출하는게 아니라 
    해당 포인터의 타입을 기준으로 함수를 호출하기 때문. 여기서 ptr_person이 Person* 타입이니까 해당 타입의 맴버 함수를 호출함
    
    이러한 문제를 해결하기 위해 virtual 사용
    위에 void ShowInfo();로 선언했으면 이제 ptr_person에 s1을 넣으면 student의 함수가 호출됨 */

    delete ptr_person;
}

//기초클래스 생성자 
Person::Person(const string& name, int age){
    name_ = name;
    age_ = age;
}

void Person::ShowInfo(){
    cout<<"Name: "<<name_<<" , age: "<<age_<<endl;
}

//파생클래스 생성자 
Student::Student(int sid ,const string& name, int age): Person(name,age){
    sid_ = sid;
}

// 파생 클래스에서 맴버 함수를 오버라이딩
void Student::ShowInfo(){
    // 여기서 person의 private 변수에 접근하는건 불가능하다. 
    // public 맴버는 가능. 
    //cout<<"Name: "<<name_<<" , age: "<<age_<< " , sid: "<<sid_<<endl;
    cout<<" sid: "<<sid_<<endl;
}