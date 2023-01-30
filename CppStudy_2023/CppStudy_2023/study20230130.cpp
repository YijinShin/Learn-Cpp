#include <iostream>

using namespace std;

void Skill_NormalCut(int iDamage);
void Skill_StrongBite(int iDamage);



typedef struct tagInfo {			// 구조체 이름: tagInfo
    char szName[20];   	 	// 구조체의 맴버 1
    char* szName_ptr;
    int age;			// 구조체의 맴버 2
    float weight;		// 구조체의 맴버 3
    float height;		// 구조체의 맴버 4
} STUDENT, *PSTUDENT;

struct Monster {
    char szName[20];
    int iHP;
    void DisplayInfo() { cout << " 이름:" << szName << ", HP: " << iHP << endl; } // 맴버 함수 
    void (*Skill)(int); // 함수 포인터
};

struct tagInfo3 {
    long long llData1;	// 8 byte
    long long llData2;	// 8 byte
};

struct tagData {
    char cData;	// 1 byte
    int iData;	// 4 byte
    float fData;	// 4 byte
    long long llData;
    tagInfo3 tInfo;	// 16 byte
};


int main() {
 
    /*
    {
        tagInfo* t1 = new tagInfo;
        t1->age = 20;		// write
        cout << t1->age << endl;	// read

        cout << "문자열 입력:";
        cin >> t1->szName;
        cout << t1->szName << endl;

        tagInfo t2;
        cout << "문자열 입력:";
        cin >> t2.szName;
        cout << t2.szName << endl;

        strcpy_s(t2.szName, sizeof(t2.szName), "hello");
        cout << t2.szName << endl;

        char str_arr[20] = "world";
        t2.szName[0] = 'H';
        cout << t2.szName << endl;


    }
    

    {
        STUDENT std;

        char str_arr1[] = "hello";
        char str_arr2[] = "world";

        std.szName_ptr = str_arr1;
        cout << " " << std.szName_ptr << endl;
        std.szName_ptr = str_arr2;
        cout << " " << std.szName_ptr << endl;
    }
    cout << endl;

    {
        Monster monster1 = { "Slime", 50,  Skill_NormalCut };
        Monster monster2 = { "Golem", 50,  Skill_StrongBite };

        monster1.Skill(10);
        monster2.Skill(20);
    }
    */
    {
        tagInfo3 tInfo1;
        tagData tInfo2;

        cout << " tagInfo의 크기 : " << sizeof(tInfo1) << endl;
        cout << " tagData의 크기 : " << sizeof(tInfo2) << endl;

    }
}

void Skill_NormalCut(int iDamage) {
    cout << " 평범한 베기! " << iDamage << "만큼의 데미지를 입혔다!" << endl;
}

void Skill_StrongBite(int iDamage) {
    cout << " 강하게 물기! " << iDamage << "만큼의 데미지를 입혔다!" << endl;
}