#include <iostream>

using namespace std;


struct tagInfo {			// ����ü �̸�: tagInfo
    char szName[20];   	 	// ����ü�� �ɹ� 1
    int age;			// ����ü�� �ɹ� 2
    float weight;		// ����ü�� �ɹ� 3
    float height;		// ����ü�� �ɹ� 4
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