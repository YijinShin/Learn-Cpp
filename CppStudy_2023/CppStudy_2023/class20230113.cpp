#include <iostream>

using namespace std;

int main() {

	// if
	{
		int i1 = 10, i2 = 20;

		if ((i1 < i2) && (i1 = 200))
			cout << "이거 참임!" << endl; //결과는 200 

		if ((i1 < i2) || (i1 = 200))
			cout << i1 << endl; // 이거는 10임. 앞에 참이라 뒤에 대입안함
	}


	//switch
	{
		// case [상수] >>무조건 상수가 와야함 ( 리터럴 상수 / 심볼릭 상수 모두 가능) 
		
		int iA = 10;
		const int ten = 10;
		
		switch (iA) {
			case ten:	// 심볼릭 상수

				break;

			case 11:	// 리터럴 상수
				break;

			default:
				break;
		}
	}
	
}

/*while문 이용해서 구구단 2 ~ 9 단 출력해오기 */