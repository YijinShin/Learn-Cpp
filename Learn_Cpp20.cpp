#include <iostream>
using namespace std;

int main(){
    char chArr[10]; 
    char arrtwo[10];
    cout<< "chArr size: "<<sizeof(chArr)<<endl; // 3 byte


    for(int i=0;i<3;i++) printf("firstArr[%d]: %x\n", i, &chArr[i]);//cout<< "chArr ["<<i<<"]: "<< &chArr[i] << endl;
    for(int i=0;i<3;i++) printf("secondArr[%d]: %x\n", i, &arrtwo[i]);//cout<< "chArr ["<<i<<"]: "<< &arrtwo[i] <<  endl;

    cout<<"1: "; cin >> chArr; cout << endl;
    cout<<"2: ";cin >> arrtwo; cout << endl;
    //cin.clear();
    
    
    cout<< "a: "<<chArr<<endl;
    cout << "b: "<<arrtwo<<endl;
}