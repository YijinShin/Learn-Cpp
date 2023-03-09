#include <iostream>
#include <string>
#include <vector>
#define DEFAULT 1000

using namespace std;


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    vector<int> vecMemo(26, DEFAULT);

    for (auto iter : keymap) {
        for (int i = 0; i < iter.length(); i++) {
            vecMemo[iter[i] - 'A'] = min(vecMemo[iter[i] - 'A'], i + 1);
        }
    }

    for (auto iter : targets) {
        int iCnt(0);

        for (int i = 0; i < iter.length(); i++) {
            if (vecMemo[iter[i] - 'A'] == DEFAULT) {
                iCnt = -1;
                break;
            }
            else iCnt += vecMemo[iter[i] - 'A'];
        }

        answer.push_back(iCnt);
    }


    return answer;
}

int main() {
    vector<string> keymap{ "AGZ", "BSSS" };
    vector<string> targets{ "ASA","BGZ" };

    vector<int> answer = solution(keymap, targets);
    for (auto iter : answer) {
        cout << iter << ",";
    }
}