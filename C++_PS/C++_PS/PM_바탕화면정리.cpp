

#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std;

/* wallpaper (���ڿ�) : ��ǻ�� ����ȭ���� ���¸� ��Ÿ��
. : ��ĭ
* : �������ִ�ĭ
���� : int [] (lux, luy / rdx ,rdy)
*/

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer; // ����

    // init
    int iWidth = wallpaper[0].length();
    int iHight = wallpaper.size();

    int iMinX(iWidth), iMaxX(0);
    int iMinY(iHight), iMaxY(0);

    // iMinX, iMaxX, iMinY, iMaxY ã��
    for (int i = 0; i < iHight; i++) {
        int iMinIndex = wallpaper[i].find("#");
        int iMaxIndex = wallpaper[i].rfind("#");
        // �ش� ���ο� ������ ������ 
        if (iMinIndex != string::npos) {
            /*// Y ����
            if (iMinY > i) iMinY = i;
            if (iMaxY < i) iMaxY = i;
            // X ����
            if (iMinX > iMinIndex) iMinX = iMinIndex;
            if (iMaxX < iMaxIndex) iMaxX = iMaxIndex;*/

            // ���� �κ� min, max�Լ��� ��ü ����
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
    

    return answer; // ����
}

int main() {
    vector<string> wallpaper{ "..........", ".....#....", "......##..", "...##.....", "....#....." };
    //vector<string> wallpaper{ ".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...." };
    vector<int> answer = solution(wallpaper);

    for (auto iter : answer) cout << iter << ",";
}