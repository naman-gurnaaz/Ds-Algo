#include<iostream>
using namespace std;
template <typename H>

class Node {

    public:
    H data;
    Node<H> *next;
    
    Node(H data){
        this -> data = data;
        next = nullptr;
    }

};

template <typename H>
class Stack {
    Node<H> *head;
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

    void push(H element){
        Node<H> *newNode = new Node<H>(element);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    H pop() {
        if(head == nullptr){
            cout<<"The stack is empty."<<endl;
        
        }

        H temp = head->data;
        Node<H> *c = head -> next;
        delete head;
        head = c;
        size--;
        return temp;
    }

    H top() {
        return head->data;
    }

};