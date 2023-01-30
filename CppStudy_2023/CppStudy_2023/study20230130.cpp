#include <iostream>

using namespace std;


struct tagInfo {			// 구조체 이름: tagInfo
    char szName[20];   	 	// 구조체의 맴버 1
    int age;			// 구조체의 맴버 2
    float weight;		// 구조체의 맴버 3
    float height;		// 구조체의 맴버 4
};

int main() {
    tagInfo t;
    t = { "he", 10,10.f,10.f };

    cout << endl;

    tagInfo t1 = { "Jully",20 };
    cout << " szName: " << t1.szName << endl;
    cout << " age: " << t1.age << endl;
    cout << " weight: " << t1.weight << endl;
    cout << " height: " << t1.height << endl;
}