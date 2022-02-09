/* note
1.1 이 월요일이면 2월 1일은 
1.1과 31칠 차이 > 31/7 = 4...3 월 > 화 > 수 > 목 
정답: 목
*/

#include <iostream>
#include <array>
using namespace std;

int CalcTotalDays(int month, int day, int* monthTotalDays);

int main(){
    array<string,7> day_arr = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int monthTotalDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month,day;
    int totalDays;
    cin >> month >> day;
    
    totalDays = CalcTotalDays(month, day, monthTotalDays);
    // 요일 계산 
    cout << day_arr[(totalDays%7)];
}

int CalcTotalDays(int month, int day, int* monthTotalDays){ // 1/1일부터 month/day까지의 날짜 수 계산
    int totalDays = 0;
    for(int i=0;i<month-1;i++){
        totalDays += monthTotalDays[i];
    }
    totalDays += day;
    return totalDays;
}

