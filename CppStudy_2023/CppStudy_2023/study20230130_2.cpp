#include <iostream>

using namespace std;

int main() {
    cout << endl;
    int* iData = (int*)malloc(5 * sizeof(int));
    int* iTemp = (int*)calloc(5, sizeof(int));

    cout << " malloc으로 할당받음: ";
    for (int i = 0; i < 5; i++) cout << iData[i] << ", ";
    cout << endl<<" calloc으로 할당받음: ";
    for (int i = 0; i < 5; i++) cout << iTemp[i] << ", ";
    cout << endl;
}