#pragma once
#include <iostream>
using namespace std;

// 이진트리를 linked list로 구현

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree{
    private:
        Node* root;
    public:
        BinaryTree();
        ~BinaryTree();
        void CreateNode(){} // 새로운 노드 생성
        void SetData(){} // 노드의 값 지정하기 
        int GetData(){} // 노드의 값 반환하기  

        void RemoveNode(){} // 특정 노드 지우기 

        void SetLeftNode(){} // 왼쪽 자녀 노드값 지정
        void SetRightNode(){} // 오른쪽 자녀 노드값 지정
        
        int ReturnLeftNode(){} // 왼쪽 자녀 노드값 반환
        int ReturnRightNode(){} // 오른쪽 자녀 노드값 반환
};