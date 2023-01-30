#include <iostream>

using namespace std;

void Skill_NormalCut(int iDamage);
void Skill_StrongBite(int iDamage);



typedef struct tagInfo {			// ����ü �̸�: tagInfo
    char szName[20];   	 	// ����ü�� �ɹ� 1
    char* szName_ptr;
    int age;			// ����ü�� �ɹ� 2
    float weight;		// ����ü�� �ɹ� 3
    float height;		// ����ü�� �ɹ� 4
} STUDENT, *PSTUDENT;

struct Monster {
    char szName[20];
    int iHP;
    void DisplayInfo() { cout << " �̸�:" << szName << ", HP: " << iHP << endl; } // �ɹ� �Լ� 
    void (*Skill)(int); // �Լ� ������
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

        cout << "���ڿ� �Է�:";
        cin >> t1->szName;
        cout << t1->szName << endl;

        tagInfo t2;
        cout << "���ڿ� �Է�:";
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

        cout << " tagInfo�� ũ�� : " << sizeof(tInfo1) << endl;
        cout << " tagData�� ũ�� : " << sizeof(tInfo2) << endl;

    }
}

void Skill_NormalCut(int iDamage) {
    cout << " ����� ����! " << iDamage << "��ŭ�� �������� ������!" << endl;
}

void Skill_StrongBite(int iDamage) {
    cout << " ���ϰ� ����! " << iDamage << "��ŭ�� �������� ������!" << endl;
}