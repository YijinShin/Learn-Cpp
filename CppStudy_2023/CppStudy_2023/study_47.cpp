/* [ C++ study with TCP school 38part]
topic: 클래스의 맴버함수에 대하여 (this 포인터)

* this가 왜 필요하냐면
	- 모든 맴버함수는 this라는 포인터를 가지고 있음
	  this = 해당 맴버 함수를 호출한 객체를 가리킴
	- 클래스의 맴버 함수는 맴버 변수와 다르게, 해당 클래스의 모든 인스턴스가 공유한다. 

	- 그러니까 만약에 한 클래스에 대해 인스턴스가 3개(A,B,C)가 있고,
		클래스의 맴버함수가 인스턴스 자기자신을 return 하는 일이 발생하면 
		그 맴버함수는 A,B,C중 어느 인스턴스를 반환해야하는지 모른다. 
		그래서 *this를 반환하라고 하면 정확히 그 함수를 호출한 인스턴스를 반환한다. 

	정리) this = 맴버함수를 호출한 객체를 찾아내기 위해 필요함

* 주의
	- this는 클래스 / 구조체 / 열거체에만 있음
	- static 맴버 함수는 this포인터 안가지고 있음		( static / 상수 맴버 는 study 56)
	
*/

#include <iostream>
#include <string>

using namespace std;


class Book {
	private: 
		int total_page;
		string name;
	public:
		void GetInfo();
		const Book& ThickerBook(const Book& comp_book);
		void DisplayInfo() { cout << name << "은 총 " << total_page << "로, 가장 두꺼운 책입니다." << endl; }
};


int main() {
	
	Book b1, b2, TickerBook;
	string name;

	
	b1.GetInfo();

	b2.GetInfo();

	TickerBook = b1.ThickerBook(b2);
	TickerBook.DisplayInfo();
}


const Book& Book::ThickerBook(const Book& comp_book) {

	// 현 인스턴스와 매개변수로 전달받은 인스턴스의 총 페이지수를 비교 -> 더 큰쪽을 리턴함

	if (comp_book.total_page > total_page) {
		return comp_book;
	}
	else {
		return *this;	// 여기서 *this는 이 맴버함수를 호출한 쪽의 인스턴스를 말한다. 
	}
}

void Book:: GetInfo() {

	cout << "책의 이름 : ";
	getline(cin, name);
	cout << "총 페이지 수 : ";
	cin >> total_page;
	cin.ignore();
}