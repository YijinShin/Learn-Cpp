#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    // 메모이제이션 
    vector<int> iMemo(26, 101);
    int iCnt(0); // for문 돌때마다 초기화 필요 

    for (auto iter : targets) {
        for (int i = 0; i < iter.length(); i++) {

            char cTarget = iter[i];
            int iTargetIdx = cTarget - 65;
            cout << cTarget << ":" << endl;
            // 해당 문자의 최소 키입력값을 모르는 경우
            if (iMemo[iTargetIdx] == 101 ) {
                    // 해당 알파벳의 최소값 찾아서 저장
                    for (auto iterK : keymap) {
                        
                        int iIndex = iterK.find(cTarget);
                        if (iIndex != -1) iIndex++;

                        if (iMemo[iTargetIdx] == -1 || iMemo[iTargetIdx] == 101) { iMemo[iTargetIdx] = iIndex;  }
                        else { 
                            if(iIndex != -1) iMemo[iTargetIdx] = min(iMemo[iTargetIdx], iIndex); 
                        }

                        cout << cTarget << "("<<iMemo[iTargetIdx] << ")" << endl;
                    }
            }

            // 해당 문자열은 입력이 불가능한 경우
            if (iMemo[iTargetIdx] == -1) {
                iCnt = -1;
                break;
            }
            // 해당 문자의 최소 키 입력값을 아는 경우
            else iCnt += iMemo[iTargetIdx];
        }
        answer.push_back(iCnt);
        iCnt = 0;
    }
    return answer;
}

int main() {
    vector<string> keymap{ "AGZ", "BSSS"};
    vector<string> targets{ "ASA","BGZ" };

    vector<int> answer = solution(keymap,targets);
    for (auto iter : answer) {
        cout << iter << ",";
    }
}