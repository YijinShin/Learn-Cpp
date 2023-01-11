/* [ C++ study with TCP school ]
 topic: structure (����ü)

 * ����ü��
	����ڰ� ���Ӱ� ������ �� �ִ� "����� ���� Ÿ��"

* ����ü�� ũ�� 
	����ü�� ũ��� �ɹ� �������� ũ�⿡ ���� ����
	
	�׷���! �ɹ� �������� ���հ� ��ġ�ϴ� ���� �ƴ�. 
		-> ���� : ����Ʈ �е� 
				  �ɹ� ���� �� ���� ����Ʈ ����� ū �ָ� �������� ��� �ɹ� ������ �޸� ũ�⸦ �����. 
				  EX)	
					char, int, bouble �̸� 1,4,8�̶� �� 13�ε� ����ü ũ��� 16���� ����
					1. 8�� ���߱� ���� ù char�� 8����Ʈ �Ҵ� -> 7����Ʈ�� �� ���·� ����
					2. �� ���� �ɹ��� 7����Ʈ���� �����ϱ� �ٽ� 8����Ʈ �Ҵ��� �ƴ϶� ���� 7����Ʈ���� ������ -> 3����Ʈ ����
					3. ������ double�� 8����Ʈ��, ���� 3����Ʈ���� ũ�ϱ� -> �ٽ� 8����Ʈ �Ҵ��� -> �� 11�� 8���ϱ� -> 3����
					��� => �� 16����Ʈ �Ҵ������ ��

					(���⼭ ���� 3����Ʈ�� �е� ����Ʈ�� �׳�... �����) 	

*/


#include <iostream>
#include <string>

using namespace std;

// [ ����ü ���� ]
struct Book {		// ����ü �̸�
	string title;	// �ɹ� ���� 1
	char author[10];// �ɹ� ���� 2
	int price;		// �ɹ� ���� 3
};

// �Լ�  -> �Լ����� �Ű������� Book����ü�� ���ϱ� ����ü ������ �� ���� �־���. 
void testFunc_without_pointer(Book book);
void testFunc_without_const(Book*);
void testFunc_with_const(const Book*);


int main() {

	// [ ����ü ���� ��� ]
	{
		// ����ü ���� + �ʱ�ȭ
		Book book1;
		book1 = { "Great Math" , "John", 10000 };

		// ����ü������ �ɹ������� ����
		book1.title = "The Greate Math";
		cout << "å�Ұ�: " << book1.title << " - " << book1.author << " - " << book1.price << endl;
	}

	// [ ����ü�� ũ�� ]
	{
		// 
	}


	// [ ����ü�� ������ ]
	{
		// ������ ������ Ÿ���� ����ü Ÿ������ ����	( �����Ϳ� ����ü�� �ּ� ����) 
		Book book2 = { "Greate English", "Yijin", 20000 };
		Book* book_ptr = &book2;

		// ������ ����ü�� �����ϴ� ���
		cout << "å�Ұ�: " << book_ptr->title << " - " << book_ptr->author << " - " << book_ptr->price << endl;
	}

	// [����ü �����Ϳ� �Լ�]
	{
		Book book1 = { "Great Math" , "John", 10000 };
		testFunc_without_pointer(book1);
		cout << "���� ����: " << book1.price << endl;
		testFunc_without_const(&book1);
		cout << "���� ����: " << book1.price << endl;
		testFunc_without_const(&book1);
	}
	
}

void testFunc_without_pointer(Book book) {
	book.price = 30000;	// -> ����ü ������ ���� �ٲٰԵ� ���� �� �������ʹ� ��¥ ������ 30000���� �����

	cout << "å�Ұ�: " << book.title << " - " << book.author << " - " << book.price << endl;
}

void testFunc_without_const(Book* book_ptr) {
	book_ptr->price = 30000;	// -> ����ü ������ ���� �ٲٰԵ� ���� �� �������ʹ� ��¥ ������ 30000���� �����

	cout << "å�Ұ�: " << book_ptr->title << " - " << book_ptr->author << " - " << book_ptr->price << endl;
}

void testFunc_with_const(const Book* book_ptr) {
	//book_ptr->price = 30000; -> �Ű������� '�ɺ��� ���' ��, ���� �ٲ� �� ���� Ư���� ������ �ֱ� ������ ������ �� ������ �Ұ�����. 
	cout << "å�Ұ�: " << book_ptr->title << " - " << book_ptr->author << " - " << book_ptr->price << endl;
}