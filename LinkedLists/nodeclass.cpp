#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        next = nullptr; 
    }
};

class Pair{
    public:
    Node* head;
    Node* tail;
};