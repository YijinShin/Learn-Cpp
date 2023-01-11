/* [ C++ study with TCP school ]
 topic: structure (구조체)

 * 구조체란
	사용자가 새롭게 정의할 수 있는 "사용자 정의 타입"

* 구조체의 크기 
	구조체의 크기는 맴버 변수들의 크기에 따라 결정
	
	그러나! 맴버 변수들의 총합과 일치하는 것은 아님. 
		-> 이유 : 바이트 패딩 
				  맴버 변수 중 가장 바이트 사이즈가 큰 애를 기준으로 모든 맴버 변수의 메모리 크기를 맞춘다. 
				  EX)	
					char, int, bouble 이면 1,4,8이라서 총 13인데 구조체 크기는 16으로 나옴
					1. 8에 맞추기 위해 첫 char에 8바이트 할당 -> 7바이트가 빈 상태로 남음
					2. 그 다음 맴버가 7바이트보다 작으니까 다시 8바이트 할당이 아니라 남은 7바이트에서 차감함 -> 3바이트 남음
					3. 마지막 double은 8바이트로, 남은 3바이트보다 크니까 -> 다시 8바이트 할당함 -> 총 11중 8쓰니까 -> 3남음
					결과 => 총 16바이트 할당받은게 됨

					(여기서 남은 3바이트는 패딩 바이트로 그냥... 빈거임) 	

*/


#include <iostream>
#include <string>

using namespace std;

// [ 구조체 선언 ]
struct Book {		// 구조체 이름
	string title;	// 맴버 변수 1
	char author[10];// 맴버 변수 2
	int price;		// 맴버 변수 3
};

// 함수  -> 함수들의 매개변수로 Book구조체를 쓰니까 구조체 선언이 더 위에 있어함. 
void testFunc_without_pointer(Book book);
void testFunc_without_const(Book*);
void testFunc_with_const(const Book*);


int main() {

	// [ 구조체 변수 사용 ]
	{
		// 구조체 변수 + 초기화
		Book book1;
		book1 = { "Great Math" , "John", 10000 };

		// 구조체변수의 맴버변수에 접근
		book1.title = "The Greate Math";
		cout << "책소개: " << book1.title << " - " << book1.author << " - " << book1.price << endl;
	}

	// [ 구조체의 크기 ]
	{
		// 
	}


	// [ 구조체와 포인터 ]
	{
		// 포인터 변수의 타입을 구조체 타입으로 가능	( 포인터에 구조체의 주소 저장) 
		Book book2 = { "Greate English", "Yijin", 20000 };
		Book* book_ptr = &book2;

		// 포인터 구조체에 접근하는 방법
		cout << "책소개: " << book_ptr->title << " - " << book_ptr->author << " - " << book_ptr->price << endl;
	}

	// [구조체 포인터와 함수]
	{
		Book book1 = { "Great Math" , "John", 10000 };
		testFunc_without_pointer(book1);
		cout << "원본 가격: " << book1.price << endl;
		testFunc_without_const(&book1);
		cout << "원본 가격: " << book1.price << endl;
		testFunc_without_const(&book1);
	}
	
}

void testFunc_without_pointer(Book book) {
	book.price = 30000;	// -> 구조체 원본의 값을 바꾸게됨 따라서 이 다음부터는 진짜 가격이 30000으로 변경됨

	cout << "책소개: " << book.title << " - " << book.author << " - " << book.price << endl;
}

void testFunc_without_const(Book* book_ptr) {
	book_ptr->price = 30000;	// -> 구조체 원본의 값을 바꾸게됨 따라서 이 다음부터는 진짜 가격이 30000으로 변경됨

	cout << "책소개: " << book_ptr->title << " - " << book_ptr->author << " - " << book_ptr->price << endl;
}

void testFunc_with_const(const Book* book_ptr) {
	//book_ptr->price = 30000; -> 매개변수가 '심볼릭 상수' 즉, 값을 바꿀 수 없는 특성을 가지고 있기 때문에 원본의 값 변경이 불가능함. 
	cout << "책소개: " << book_ptr->title << " - " << book_ptr->author << " - " << book_ptr->price << endl;
}