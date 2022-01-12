/*content
class 연습 : 책들 중 더 두꺼운 책을 반환*/
#include <iostream>
using namespace std;

class Book{
    private:
        int current_page; 
    public:
        // class 디폴트 생성자
        Book(const string& name = "None", const int& age = 0);
        // class 소멸자. 기본적으로 컴파일러가 알아서 실행한다. 자동으로 호출되지만 소멸시 뭔가 동작하게 하고싶다면 선언가능
        ~Book();
        string name;
        int total_page;
        void SetInfo();
        void Display();
        void UpdateCurrPage(int page); // 함수 원형
        const Book& thickerBook(const Book& comp_book); //함수 원형
};

int main(){
    Book book1; // 이렇게 해도 괜찮고
    Book book2 = Book(); //이렇게 명시적 호출해도 괜찮다.
    Book *book3 = new Book(); // 이렇게 암시적 호출해도 괜찮다. 
    Book thickerBook;

    book1.Display();
    book2.Display();
    book3->Display();
    cout<<endl;

    book1.SetInfo();
    cin.ignore(); // 한번 입력받고나면 두번째 name입력을 건너뛰어서 버퍼에ㅔ 있는걸 한번 비워줘야함.
    book2.SetInfo();

    thickerBook = book1.thickerBook(book2);
    cout<< "thicker book: "<<thickerBook.name<<"_"<<thickerBook.total_page<<endl;

    return 0;
}   

// 함수 본체
//생성자 
Book::Book(const string& name, const int& total_page){
    this->name = name;
    this->total_page = total_page;
}
Book::~Book(){
    //컴파일러가 자동으로 호출함
    cout << this->name <<" 이 소멸되었습니다."<<endl;
}
void Book::Display(){
    cout<<this->name<<" _ "<<this->total_page<<endl;
}
void Book:: SetInfo(){
    cout<< "Name: ";
    getline(cin,this->name);
    cout<< "Total page: ";
    cin >> this->total_page;
    cout<< "["<<this->name<<"] "<<this->total_page<<endl<<endl;
}
void Book:: UpdateCurrPage(int page){ 
    current_page = page;
}

const Book& Book:: thickerBook(const Book& comp_book){
    if(comp_book.total_page < this->total_page){
        return *this;
    }else{
        return comp_book;
    }
}