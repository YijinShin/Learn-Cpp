#include <iostream>
#include "Stack.h"
using namespace std;

int ShowMenu();

int main(){
    Stack stack;
    List* list = stack.CreateList();

    int menu;
    int data;

    while(1){
        menu = ShowMenu();

        if(menu == 1){
            cout << endl << "Insert data: ";
            cin >> data;
            stack.Push(list, data);
        }
        else if(menu == 2) stack.Pop(list);
        else if(menu == 3) stack.ShowList(list);
        else if(menu == 4) break;
    }
}


int ShowMenu(){
    int menu;
    cout << "1. Push" << endl << "2. Pop" << endl << "3. Show List" << endl << "4. Quit" << endl << "menu: ";
    cin >> menu;
    cout << endl;
    return menu;
}