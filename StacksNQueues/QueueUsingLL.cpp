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
class QueueUsingLL{
    Node<S> *head;
    Node<S> *tail;
    int size;

    public:

    QueueUsingLL(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(S element){
        Node<S> *newNode = new Node<S>(element);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    S front(){
        if(size == 0){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return head->data;
    }

    S dequeue(){
        if(size == 0){
            cout<< "Queue is empty" <<endl;
            return 0;
        }
        S ans = head->data;
        Node<S> *x = head;
        head = head->next;
        delete x;
        size--;
        return ans;
    }

};