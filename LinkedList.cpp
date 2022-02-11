#include <iostream>
#include "LinkedList.h" // linked list 기능을 구현해 놓은 헤더파일 
using namespace std;
using namespace LList; 

int ShowMenu();

int main(){ 
    LinkedList linkedList; // using을 안쓰면  LinkedList::LinkedList linkedList; 이렇게 해야한다. 
    List* list = linkedList.CreateList(); // 이건 클래스 내의 함수라 무조건 앞에 클래스 이름 붙이기.

    int data;
    int menu;

    while(true){
        menu = ShowMenu();

        if(menu == 1){
            cout << endl << "Insert data: ";
            cin >> data;
            linkedList.Insert(list, data);
        }
        else if(menu == 2){
            cout << endl << "Delete data: ";
            cin >> data;
            linkedList.Delete(list, data);
        }
        else if(menu == 3) linkedList.ShowList(list);
        else if(menu == 4) break;
    }
    return 0;
}

int ShowMenu(){
    int menu;
    cout << "1. Insert" << endl << "2. Delete" << endl << "3. Show List" << endl << "4. Quit" << endl << "menu: ";
    cin >> menu;
    cout << endl;
    return menu;
}