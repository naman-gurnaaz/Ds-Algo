#include <iostream>
#include <climits>
using namespace std;
template <typename T>

class StackUsingArray {

    T *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingArray(){
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
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

    void push(T element){ //insert elelment

        if(nextIndex == capacity){

            T *newData = new T [capacity * 2];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
            capacity = capacity * 2;


            /*cout << "The stack is full." << endl;
            return;*/
        }
        
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop(){   //delete element

        if(isEmpty()){
            cout << "The stack is empty." << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    T top() {

        if(isEmpty()){
            cout << "The stack is empty." << endl;
            return 0;
        }

        return data[nextIndex -1];
    }

};