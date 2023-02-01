#include <iostream>

using namespace std;

int main() {

    FILE* pFile = nullptr;
    int len;
    char* buf = nullptr;

    errno_t err_r = fopen_s(&pFile, "../Data/Image.jpg", "rb");	// ���̳ʸ����������, �б� ��������

    // ���� ���� ����
    if (0 == err_r) {
        
        fseek(pFile, 0, SEEK_END); //go to end
        len = ftell(pFile);
        fseek(pFile, 0, SEEK_SET); //go to beg.
        
        buf = (char*)malloc(len); //malloc buffer
        
        fread(buf, len, 1, pFile); //read into buffer
        fclose(pFile);	// ��Ʈ�� �Ҹ�

        cout << " ���� �б� ����" << endl;
    }
    // ���� ���� ����
    else {

    }

    errno_t err_w = fopen_s(&pFile, "../Data/Image_copy.jpg", "wb");	// ���̳ʸ����������,���� ��������

    // ���� ���� ����
    if (0 == err_w) {
        fwrite(buf,1, len, pFile);	// ����
        fclose(pFile);	// ��Ʈ�� �Ҹ�
        cout << " ���� ���� ����" << endl;
    }
    // ���� ���� ����
    else {

    }
}