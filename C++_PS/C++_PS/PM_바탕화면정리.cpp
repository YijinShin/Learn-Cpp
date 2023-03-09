

#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std;

/* wallpaper (문자열) : 컴퓨터 바탕화면의 상태를 나타냄
. : 빈칸
* : 파일이있는칸
리턴 : int [] (lux, luy / rdx ,rdy)
*/

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer; // 고정

    // init
    int iWidth = wallpaper[0].length();
    int iHight = wallpaper.size();

    int iMinX(iWidth), iMaxX(0);
    int iMinY(iHight), iMaxY(0);

    // iMinX, iMaxX, iMinY, iMaxY 찾기
    for (int i = 0; i < iHight; i++) {
        int iMinIndex = wallpaper[i].find("#");
        int iMaxIndex = wallpaper[i].rfind("#");
        // 해당 라인에 파일이 있으면 
        if (iMinIndex != string::npos) {
            /*// Y 갱신
            if (iMinY > i) iMinY = i;
            if (iMaxY < i) iMaxY = i;
            // X 갱신
            if (iMinX > iMinIndex) iMinX = iMinIndex;
            if (iMaxX < iMaxIndex) iMaxX = iMaxIndex;*/

            // 위에 부분 min, max함수로 대체 가능
            iMinY = min(iMinY, i);
            iMinX = min(iMinX, iMinIndex);
            iMaxY = max(iMaxY, i);
            iMaxX = max(iMaxX, iMaxIndex);
        }
    }
    // answer
    iMaxX++;
    iMaxY++;
    answer.push_back(iMinY);
    answer.push_back(iMinX);
    answer.push_back(iMaxY);
    answer.push_back(iMaxX);
    

    return answer; // 고정
}

int main() {
    vector<string> wallpaper{ "..........", ".....#....", "......##..", "...##.....", "....#....." };
    //vector<string> wallpaper{ ".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...." };
    vector<int> answer = solution(wallpaper);

    for (auto iter : answer) cout << iter << ",";
}