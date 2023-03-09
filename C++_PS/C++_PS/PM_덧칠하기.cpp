#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
2 3 6
1,2,3,4,5,6,7,8
 
*/

int solution(int n, int m, vector<int> section) {
    int answer = 0; 

    // solution ------------
    vector<bool> isColored(n+1, false);

    for (int i = 0; i < section.size();i++) {
        // 안칠해져있으면 
        if (!isColored[section[i]]) {
            // 일단 칠하기 
            answer++;   
            for (int j = section[i]; j < section[i] + m; j++) {
                if (j >= n+1) break;
                isColored[j] = true;
            }
        }
    }
  
    // ----------------------
    
    return answer;
}

int main() {
    vector<int> section{ 2,3,6 };
    int answer = solution(8,4,section);
    cout << answer << endl;
}