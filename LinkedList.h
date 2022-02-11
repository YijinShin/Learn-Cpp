#pragma once // 헤더파일에 필요함 
#include <iostream>
using namespace std;

/* 헤더 사용과 클래스 사용 정리
    클래스 이름과 namespace 이름기 같으면 안되는 것 같다. ambigous하다는 애러가 남

    다른 파일의 클래스를 사용하려면 
    1. 클래스 객체 선언
    2. 클래스 내의 함수 사용시 [클래스객체].[함수명] 으로 사용해야한다. 

    네임스페이스는 그 안의 클래스나 struct, 함수 사용에 오해가 없도록 하는 것인데, 
    네임스페이스 내의 클래스 내의 함수나 변수 등에는 네임스페이스를 붙일 필요가 없다. 클래스 내의 것들은 무조건 [클래스객체].[함수명]을 따라야 한다. 

    // A.h 헤더파일
    namespace A{
        int data;
        class classA{
            int num;
        }
    }
    
    //.cpp 파일
    #include "A.h"
    int main(){
        A::classA ca;
        cin >> ca.num; // 네임스페이스 내의 클래스 내의 변수 사용
        cin >> A::data; // 네임스페이스 내의 변수 사용
    }
*/

struct Node{
    int data;
    struct Node *next;
};

struct List{
    Node* head;
    Node* last;
};

namespace LList{
    class LinkedList {
        public:   
            List* CreateList(){
                List* list = new List;
                list->head = NULL;
                list->last = NULL;
                return list;
            }

            void Insert(List * list, int data){
                Node* newNode = new Node;
                newNode->data = data;
                newNode->next = NULL;

                // list에 연결시키기 
                if(list->head == NULL){
                    list->head = newNode;
                    list->last = newNode;
                }
                else {
                    list->last->next = newNode;
                    list->last = newNode;
                }
                cout << data << "를 추가했습니다."<< endl << endl;
            }

            void Delete(List * list, int targetData){
                Node* front = NULL;
                Node* curr = list->head;
                bool isDeleted = false;

                cout << "가장 앞에 있는 "<< targetData << " 삭제중 . . ."<< endl;
                while(curr != NULL){
                    if(curr->data == targetData){
                        //샥제 대상이 head node인 경우 
                        if(front == NULL){
                            list->head = curr->next;
                            delete curr;
                        }
                        //삭제 대상이 head node가 아닌경우 
                        else{   
                            front->next = curr->next;
                            delete curr;
                        }
                        isDeleted = true;
                        break;
                    }
                    front = curr;
                    curr = curr->next;
                }
                if(isDeleted) cout << "Delete!" << endl << endl;
                else cout << "No such data!" << endl << endl;
            }   

            void ShowList(List * list){
                Node* curr = list->head;

                cout << "[Show List]"<<endl;
                while(curr != NULL){
                    cout << curr->data << " / ";
                    curr = curr->next;
                }
                cout << endl << endl;
            }
    };
}
