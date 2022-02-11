#include <iostream>
#include "Queue.h" 
using namespace std;
using namespace Que;

int ShowMenu();

int main(){
    Queue queue;

    int data;
    int menu;

    while(true){
        menu = ShowMenu();

        if(menu == 1){
            cout << endl << "Insert data: ";
            cin >> data;
            queue.Inqueue(data);
        }
        else if(menu == 2) queue.Dequeue();
        else if(menu == 3) queue.ShowList();
        else if(menu == 4) break;
    }
    queue.~Queue();
    return 0;
}

int ShowMenu(){
    int menu;
    cout << "1. Inqueue" << endl << "2. Dequeue" << endl << "3. Show List" << endl << "4. Quit" << endl << "menu: ";
    cin >> menu;
    cout << endl;
    return menu;
}

