#include <iostream>
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

template <typename T>

class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;

    public: 

        Queue() {
            head = nullptr;
            tail =nullptr;
            size = 0;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size == 0;
        }

        void enqueue(T element){
            Node<T> *newNode = new Node<T>(element);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
            size++;
        }

        T dequeue(){
            if(isEmpty()){
                return 0;
            }

            T temp = head -> data;
            Node<T> *c = head;
            head = head -> next;
            delete c;
            size--;
            return temp;
        }

        T front(){
            if(isEmpty()){
                return 0;
            }
            return head -> data;
        }
};