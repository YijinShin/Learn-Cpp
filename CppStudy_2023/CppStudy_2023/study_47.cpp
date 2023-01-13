/* [ C++ study with TCP school 38part]
topic: Ŭ������ �ɹ��Լ��� ���Ͽ� (this ������)

* this�� �� �ʿ��ϳĸ�
	- ��� �ɹ��Լ��� this��� �����͸� ������ ����
	  this = �ش� �ɹ� �Լ��� ȣ���� ��ü�� ����Ŵ
	- Ŭ������ �ɹ� �Լ��� �ɹ� ������ �ٸ���, �ش� Ŭ������ ��� �ν��Ͻ��� �����Ѵ�. 

	- �׷��ϱ� ���࿡ �� Ŭ������ ���� �ν��Ͻ��� 3��(A,B,C)�� �ְ�,
		Ŭ������ �ɹ��Լ��� �ν��Ͻ� �ڱ��ڽ��� return �ϴ� ���� �߻��ϸ� 
		�� �ɹ��Լ��� A,B,C�� ��� �ν��Ͻ��� ��ȯ�ؾ��ϴ��� �𸥴�. 
		�׷��� *this�� ��ȯ�϶�� �ϸ� ��Ȯ�� �� �Լ��� ȣ���� �ν��Ͻ��� ��ȯ�Ѵ�. 

	����) this = �ɹ��Լ��� ȣ���� ��ü�� ã�Ƴ��� ���� �ʿ���

* ����
	- this�� Ŭ���� / ����ü / ����ü���� ����
	- static �ɹ� �Լ��� this������ �Ȱ����� ����		( static / ��� �ɹ� �� study 56)
	
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
		void DisplayInfo() { cout << name << "�� �� " << total_page << "��, ���� �β��� å�Դϴ�." << endl; }
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

	// �� �ν��Ͻ��� �Ű������� ���޹��� �ν��Ͻ��� �� ���������� �� -> �� ū���� ������

	if (comp_book.total_page > total_page) {
		return comp_book;
	}
	else {
		return *this;	// ���⼭ *this�� �� �ɹ��Լ��� ȣ���� ���� �ν��Ͻ��� ���Ѵ�. 
	}
}

void Book:: GetInfo() {

	cout << "å�� �̸� : ";
	getline(cin, name);
	cout << "�� ������ �� : ";
	cin >> total_page;
	cin.ignore();
}