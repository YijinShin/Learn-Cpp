/* [ C++ study with TCP school ]
topic: 함수 / 메인함수의 인자 / 재귀함수 / 함수 포인터

* 메인 함수의 인자 
	메인 함수의 인자는 2개이다.물론 void로 해도됨.
		1. int argc
			인수로 전달되는 문자열의 개수
		2. char *argv[]
			전달된 각각의 문자열이 포함되는 배열 
-------------------------------------------------------------------------------------

* 일반 함수에 인자 전달
	함수에 인수를 전달하는 방법
	- 값으로 전달
		이거는 원본 데이터를 주는게 아니라 매개변수로 값을 복사해 넘기는 것. 
		함수 내에서 원본 데이터를 건드리지 못함. 
	- 참조에 의한 전달
		변수의 주소값을 직접 전달한다. 즉, 원본 데이터를 줘버리는 셈
	- 포인터를 전달
		이거나 참조에 의한 전달이나 같다. 
		단지 그 &value 이렇게 할건지, &value를 포인터 변수에 넣어 전달할건지 그 차이일뿐 

	결론: 참조, 포인터 -> 원본 데이터의 "주소값"을 전달하는 것. 
-------------------------------------------------------------------------------------

* 재귀함수
	재귀함수를 끝내는 조건이 없으면 무한으로 함수가 실행되면서 스택오버플로우 에러에 의해 종료될 것이다. 
	
	* stackoverflow : stack 영역에 해당 프로그램이 사용할 수 있는 메모리 공간 이상을 사용하려고 한다는 오류
-------------------------------------------------------------------------------------

* 함수 포인터 (function pointer)
	함수의 이름 = constant pointer(포인터 상수)이다. ( 함수의 이름 자체가 포인터 변수인 것) 
				 포인터 상수니까 당연히, 이 포인터 변수가 가지고있느 주소값을 우리가 바꿀 수 없다. 
				 메모리에 올라간 함수의 시작 주소를 의미함. 
	함수 포인터(function pointer) = 함수의 시작 주소를 가리키는 상수 

	* 상수 포인터 vs 포인터 상수
		상수 포인터(pointer of constant) = 상수를 가르키는 포인터
		포인터 상수 (constant pointer) = 포인터 변수가 가지고 있는 주소값을 변경할 수 없는 포인터

	* 함수 포인터의 타입 
		[ 함수의 리턴타입 + 매개변수 ]에 의해 결정된다. 

	* 사용하는 방법
		함수를 -> 또 다른 함수의 인수로 전달할 떄 유용하게 사용됨. 
	
	* 함수 포인터 표기를 단순화 하는 두가지 방법
		
		- typedef
				함수 포인터에 새로운 이름을 붙인다. 
				함수 포인터를 말하려면 [int (*Func)(int, int)] 이렇게 긴데 이걸 그냥 변수 처럼 선언해서 아주 간단한 이름으로 사용
				Func ptr_func = [함수 포인터에 넣을 함수이름(포인터 상수)]
		- auto
				auto ptr_func = calc; 
				이렇게 하면 자동으로 calc() 함수의 형식을 가져와 ptr_func 함수 포인터의 타입을 지정해버림
*/

#include <iostream>

using namespace std;
	
void func_call_by_value(int data);		 // 함수에 인수를 -> 값으로 전달.
void func_call_by_reference(int& data);	 // 함수에 인수를 -> 참조에 의한 전달.
void func_call_by_pointer(int* data);	
int Sum(int num);
double Add(int i1, int i2);
double Min(int i1, int i2);
double Mul(int i1, int i2);
double Div(int i1, int i2);
double Calculator(int i1, int i2, double (*func)(int, int));

typedef double (*Operator)(int, int); // typedef로 [double이 리턴값이고, 매게변수가 (int, int) 인 함수 포인터 이르믈 Operator로 지어줌


int main( int argc ,char *argv[]) {
	
	// [ 메인 함수의 인자 ] 
	{
		//cout << "(" << argc << ")";
		//cout << argv << endl;
	}

	// [ 함수 인자와 원본 데이터 ]
	{	
		int iData = 10;
		func_call_by_value(iData);
		cout << "iData 원본값: " << iData << endl;
		func_call_by_reference(iData);
		cout << "iData 원본값: " << iData << endl;
		func_call_by_pointer(&iData);
		cout << "iData 원본값: " << iData << endl;
	}

	// [ 재귀 호출 ] 
	{
		int result;
		result = Sum(10);
		cout << "1~10까지 더한 결과: " << result << endl;
	}

	// [ 함수 포인터 사용 예시]
	{
		int i1, i2;
		double result;
		char type;
		cout << "숫자1: ";
		cin >> i1;
		cin.ignore();
		cout << "숫자2: ";
		cin >> i2;
		cin.ignore();
		cout << "무슨 연산을 할까? (+,-,*,/): ";
		cin >> type;
		cin.ignore();

		switch (type)
		{
		case '+':
			result = Calculator(i1, i2, Add);
			break;
		case '-':
			result = Calculator(i1, i2, Min);
			break;
		case '/':
			result = Calculator(i1, i2, Div);
			break;
		case '*':
			result = Calculator(i1, i2, Mul);
			break;
		default:
			cout << "연산을 잘못 입력했습니다.";
			break;
		}
		cout << "결과: " << result << endl;

	}

}

// ---------------------------------------------인자 설명 위한 함수--------------------------------------------- 

void func_call_by_value(int data) {
	data = data + 10;
	cout << "[함수 실행] data: " << data << endl;
}

void func_call_by_reference(int& data) {
	data = data + 20;
	cout << "[함수 실행] data: " << data << endl;
}

void func_call_by_pointer(int* data) {
	*data = *data + 20;
	cout << "[함수 실행] data: " << *data << endl;
}

// ---------------------------------------------재귀함수--------------------------------------------- 
int Sum(int num) {

	if (num == 1) {
		return 1;
	}

	return num + Sum(num - 1);
}
// ---------------------------------------------함수 포인터 설명 위한 함수--------------------------------------------- 
double Calculator(int i1, int i2, double (*func)(int, int )) {	//	 함수 포인터 사용 방법 
	return func(i1, i2);
}

// 위의 함수와 같다. 근데 typedef로 정의해준 이름 Operator를 [double (*func)(int,int) 대신 써준 것. ]
double Calculator_using_typedef(int i1, int i2, Operator func) {	
	return func(i1, i2);
}

/* // typedef와 다르게 auto는 이런식으로 사용 못함. 
double Calculator_using_typedef(int i1, int i2, auto func) {
	return func(i1, i2);
}
*/

double Add(int i1, int i2) {return i1 + i2;}
double Min(int i1, int i2) { return i1 - i2; }
double Mul(int i1, int i2) { return i1 * i2; }
double Div(int i1, int i2) { return i1 / i2; }