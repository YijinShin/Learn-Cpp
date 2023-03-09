#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    // �޸������̼� 
    vector<int> iMemo(26, 101);
    int iCnt(0); // for�� �������� �ʱ�ȭ �ʿ� 

    for (auto iter : targets) {
        for (int i = 0; i < iter.length(); i++) {

            char cTarget = iter[i];
            int iTargetIdx = cTarget - 65;
            cout << cTarget << ":" << endl;
            // �ش� ������ �ּ� Ű�Է°��� �𸣴� ���
            if (iMemo[iTargetIdx] == 101 ) {
                    // �ش� ���ĺ��� �ּҰ� ã�Ƽ� ����
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

            // �ش� ���ڿ��� �Է��� �Ұ����� ���
            if (iMemo[iTargetIdx] == -1) {
                iCnt = -1;
                break;
            }
            // �ش� ������ �ּ� Ű �Է°��� �ƴ� ���
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