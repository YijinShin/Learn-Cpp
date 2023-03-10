/* 


*/

#include "stdafx.h"
using namespace std;


// cout 만들기 예시
namespace MyStd {
	class OSTREAM {
	public:
		OSTREAM& operator<<(int iData) {
			printf("%d", iData);
			return *this;
		}
		OSTREAM& operator<<(const char* pData) {
			printf("%s", pData);
			return *this;
		}
	};

	OSTREAM COUT;
	const char* ENDL = "\n";

}

using namespace MyStd;

int main() {
	COUT << 100 << ENDL;
	COUT << "wwwww" << ENDL;
}
