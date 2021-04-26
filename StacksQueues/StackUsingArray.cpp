#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray {

    int *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    int size(){    //returm the no. of elements in my stack
        return nextIndex;
    }

    bool isEmpty(){

        /*if(nextIndex == 0){
            return true;
        }else{
            return false;
        }*/

        return nextIndex == 0;
    }

    void push(int element){ //insert elelment

        if(nextIndex == capacity){
            cout << "The stack is full." << endl;
            return;
        }
        
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop(){   //delete element

        if(isEmpty()){
            cout << "The stack is empty." << endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }

    int top() {

        if(isEmpty()){
            cout << "The stack is empty." << endl;
            return INT8_MIN;
        }

        return data[nextIndex -1];
    }

};