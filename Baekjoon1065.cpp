// 2:40 start - 3:26 end
#include <iostream>
using namespace std;

int Calc(int N);

int main(){
    int N;
    cin >> N;
    cout << Calc(N)<<endl;
}

int Calc(int N){
    int count=0;
    int t = 100;
    int num[3];
    int total;
    int target;

    for(int i=1;i<=N;i++){
        // 1,2자리 수는 다 한수 
        if(i < 100) count++;
        // 3자리수부터 공차 계산해야함 (N은 1000이하이므로 무조건 3자리수)
        // a-b, a, a+b 이므로 세 자리수의 합이 3a가 된다. 
        else{
            target = i;
            // 각 자리수 저장 
            for(int j=0;j<3;j++){
                num[j] = target/t;                
                total += num[j];
                target -= num[j]*t;
                t = t/10;
            }
            // 한수 확인
            if(num[0]+ num[2] == 2* num[1]) count++;
        }   
        t = 100;
    }
    return count;
}