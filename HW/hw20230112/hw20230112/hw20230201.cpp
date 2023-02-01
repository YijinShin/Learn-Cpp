#include <iostream>

using namespace std;

int main() {

    FILE* pFile = nullptr;
    int len;
    char* buf = nullptr;

    errno_t err_r = fopen_s(&pFile, "../Data/Image.jpg", "rb");	// 바이너리모드파일을, 읽기 전용으로

    // 파일 개방 성공
    if (0 == err_r) {
        
        fseek(pFile, 0, SEEK_END); //go to end
        len = ftell(pFile);
        fseek(pFile, 0, SEEK_SET); //go to beg.
        
        buf = (char*)malloc(len); //malloc buffer
        
        fread(buf, len, 1, pFile); //read into buffer
        fclose(pFile);	// 스트림 소멸

        cout << " 파일 읽기 성공" << endl;
    }
    // 파일 개방 실패
    else {

    }

    errno_t err_w = fopen_s(&pFile, "../Data/Image_copy.jpg", "wb");	// 바이너리모드파일을,쓰기 전용으로

    // 파일 개방 성공
    if (0 == err_w) {
        fwrite(buf,1, len, pFile);	// 쓰기
        fclose(pFile);	// 스트림 소멸
        cout << " 파일 쓰기 성공" << endl;
    }
    // 파일 개방 실패
    else {

    }
}