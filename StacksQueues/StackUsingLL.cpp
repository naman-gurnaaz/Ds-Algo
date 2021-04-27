#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node *next;
    
    Node(int data){
        this -> data = data;
        next = nullptr;
    }

};

class Stack {
    Node *head;
    int size;

    public:

    Stack(){
        head = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty(){
        return (size == 0);
    }

    void push(int element){
        Node *newNode = new Node(element);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    int pop() {
        int temp = head->data;
        Node* c = head -> next;
        delete head;
        head = c;
        size--;
        return temp;
    }

    int top() {
        return head->data;
    }

};