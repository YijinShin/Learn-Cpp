#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    // --

    int iWidth = maps[0].length();  // �̷��� ���� ����
    int iHight = maps.size();       // �̷��� ���� ���� 

    // ������ ã�� 
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

    // �̷� ã�� 
    int iSec(0);    
    bool isFinish(false);
    pair<int, int> currPos;

    while (true) {

        // ã�� 
        



        // ���� 
        if (isFinish) break;

    }

    // --
    return answer;
}

int main() {
    vector<string> maps{ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" };
    solution(maps);
}