#include <iostream>

using namespace std;

int main() {
    cout << endl;
    int* iData = (int*)malloc(5 * sizeof(int));
    int* iTemp = (int*)calloc(5, sizeof(int));

    cout << " malloc���� �Ҵ����: ";
    for (int i = 0; i < 5; i++) cout << iData[i] << ", ";
    cout << endl<<" calloc���� �Ҵ����: ";
    for (int i = 0; i < 5; i++) cout << iTemp[i] << ", ";
    cout << endl;
}