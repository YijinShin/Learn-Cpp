#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    // --

    int iWidth = maps[0].length();  // 미로의 가로 길이
    int iHight = maps.size();       // 미로의 세로 길이 

    // 시작점 찾기 
    pair<int, int>   startPos;
    pair<int, int>   laberPos;
    pair<int, int>   exitPos;
    for (int i = 0; i < iHight; i++) {
        for (int j = 0; j < iWidth; j++) {
            if (maps[i][j] == 'S') startPos = pair<int, int>(i, j);
            else if (maps[i][j] == 'L') startPos = pair<int, int>(i, j);
            else if (maps[i][j] == 'E') startPos = pair<int, int>(i, j);
        }
    }

    // 미로 찾기 
    int iSec(0);    
    bool isFinish(false);
    pair<int, int> currPos;

    while (true) {

        // 찾기 
        



        // 종료 
        if (isFinish) break;

    }

    // --
    return answer;
}

int main() {
    vector<string> maps{ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" };
    solution(maps);
}