#include <iostream>
using namespace std;

template <typename S>

class Node{
    public:
    S data;
    Node <S> *next;

    Node(S data){
        this->data = data;
        next = nullptr;
    }
};

template <typename S>
class StackWithLL{
    Node<S> *head;
    int size;

    public:

    StackWithLL(){
        head = nullptr;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void push(int element){

        Node<S> *newNode = new Node<S>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    S pop(){

        if(isEmpty()){
            cout << "The stack is EMPTY!" << endl;
            return 0;
        }
        S temp = head->data;
        Node<S> *x = head->next;
        delete head;
        head = x;
        size --;
        return temp;
    }

    S top(){
        if(isEmpty()){
            cout << "The stack is EMPTY!" << endl;
            return 0;
        }

        return head->data;
    }
};