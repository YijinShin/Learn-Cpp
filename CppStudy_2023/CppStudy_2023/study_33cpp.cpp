/* [ C++ study with TCP school 12~19part ]
topic : 공용체(Union) / 열거체 (Enum)

* 공용체(Union)란?
	구조체랑 다 똑같은데 맴버 변수들의 "메모리 사용"만 다름 
	1. 가장 큰 맴버 변수의 크기로 메모리 할당받고 
	2. 모든 맴버 변수가 그 메모리를 같이 씀 

	EX) char, short, int 맴버가 있으면
		- 구조체 : 1 + 2 + 4 + (1패링 바이트) => 총 8바이트 구조체가됨

		- 공용체 : 4바이트 공용체가됨. 저 안에 다 우겨넣음 
	
	즉, 공용체는 같은 "데이터"를 다양한 크기의 데이터로 저장이 가능함. 이게 주 목적임
	char, short, int라고 하면 "a", 1, 3034 이렇게 저장하기 위함이 아니라
	"a"라는 데이터를, char, short, int형태로 저장하기 위함임. 
	그래서 공용체는 맴버중 한명한테만 값을 넣으면 나머지도 그 데이터를 공유함

* 열거체


*/

#include <iostream>

using namespace std;

// [ 공용체 선언 ]
union ShareData {
	unsigned char ch;
	unsigned short sh;
	unsigned int i;
};

// [ 열거체 선언 ] 
enum Week { MON = 0, TUE = 1, WED = 2, THU = 3, FRI = 4, SAT = 5, SUN = 6};	 // 이때, 상수값을 명시 하지 않으면 자동으로 0부터 1씩 증가하는걸로 됨

int main() {
	// [ 공용체 사용 ]
	{
		ShareData sd1;
		
		sd1.ch = 'a';	// ch에만 'a'라고 데이터를 넣어도 sh, i 모두다 들어감 
		cout << "sd1: " << sd1.ch << " / " << sd1.sh << " / " << sd1.i << endl;
	
		sd1.ch = 'b';
		cout << "sd1: " << sd1.ch << " / " << sd1.sh << " / " << sd1.i << endl;
	}

	// [ 열거체 사용 ] 
	{
		Week wk;

		int input;
		cout << "오늘은 무슨 요일입니까 (월=0, 화=1, 수=2, 목=3, 금=4, 토=5, 일=6): ";
		cin >> input; 

		wk = (Week)input; // 입력받은 숫자를 열거체로 변환 

		switch (wk) {
			case MON: 
				cout << "월요일입니다.";
				break;
			case TUE:
				cout << "화요일입니다.";
				break;
			case WED:
				cout << "수요일입니다.";
				break;
			case THU:
				cout << "목요일입니다.";
				break;
			case FRI:
				cout << "금요일입니다.";
				break;
			case SAT:
				cout << "토요일입니다.";
				break;
			case SUN:
				cout << "일요일입니다.";
				break;
			default:
				break;
		}
	}

}