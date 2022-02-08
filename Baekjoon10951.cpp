#include <iostream> 
using namespace std;

int main() {
    int a,b;
    while (true) {   
        //cin >> a >> b; 
        if(scanf("%d %d",&a,&b) != EOF) cout << a+b<<endl;
        else break;
    }
    return 0;
}