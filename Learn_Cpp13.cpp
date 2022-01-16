/*content
- inheritance(상속)
    상속은 객체지향 프로그래밍을 구성하는 중요한 특징 중 하나
    class상속 : 기존에 정의되어있는 클래스의 모든 맴버를 물려받아 새로운 클래스를 작성하는 것. 
    이떄 기존 클래스 = base class, parent class, super class라고 한다.
    새롭게 파생된 클래스 = derived class(파생), child class, sub class라고 한다. 

    derived class(파생클래스) 선언방법
    class className : 접근제어지시자 기초클래스이름[, 접근제어지시자 기초클래스이름,  ...]
    이거 쉽표로 여러 클래스 상속 받도록 가능 > 다중상속
    상속받는 기초 클래스 하나면 > 단일상속 
    
    파생 클래스 특징 
        - 파생 클래스는 반드시 자신만의 생성자 작성해야함
        - 파생 클래스에는 기초 클래스의 접근할 수 있는 모든 맴버 변수들이 저장된다. 
        - 파생클래스는 기초 클래스의 접근할 수 있는 모든 맴버 함수를 사용할 수 있다. 
        - 파생 클래스에는 필요한 만큼 맴버를 추가할 수 있다. 
*/

#include <iostream>
using namespace std;

/* 파생 클래스의 객체 생성 순서
1. 기초 클래스의 생성자를 호출한다. 
2. 파생 클래스의 생성자 호출

파생 클래스 객체 소멸 순서
1. 파생 클래스의 소멸자 호출
2. 기초 클래스의 소멸자 호출 
*/

//base class
class Person{
    private:
        string name_;
        int age_;
    public:
        Person(const string& name, int age); //생성자 선언
        void ShowPersonInfo();
};

//derived class 
class Student: public Person{ // class [Name] : [접근제어지시자, baseClassName] 
    private:
        int sid_;
    public:
        Student(int sid, const string& name, int age); // 생성자가 꼭 있어야한다. 
        void ShowStudentInfo();
};

int main(){
    Student s1 = Student(21800408, "A", 10);
    s1.ShowStudentInfo();
}

//기초 클래스 생성자 정의 
Person::Person(const string& name, int age){
    name_ = name;
    age_ = age;
}

void Person::ShowPersonInfo(){
    cout<<"Name: "<<name_<<" , age: "<<age_<<endl;
}

// 파생 클래스 생성자의 정의 
Student::Student(int sid,const string& name, int age): Person(name , age){
    sid_ = sid;
    // person 클래스를 상속받았기 때문에 Person(name , age) 이걸로 name, age는 Person의 생성자가 값을 넣어줄 것이다. 
    // 이렇게 파생 클래스의 생성자는 기초클래스의 생성자를 사용한다. 
    // 왜 ? 파생 클래스의 생성자는 기초클래스의 private맴버에 접근할 수 없기 때문이다. 
    // 여기서 :Person() 이렇게 기초클래스의 생성자를 사용하지 않으면 디폴트 생성자를 사용하게 된다. 
}
void Student::ShowStudentInfo(){
    ShowPersonInfo();
    cout<< "sid: "<<sid_ << endl;
}