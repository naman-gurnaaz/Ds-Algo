#include <iostream>
using namespace std;
template <typename T>

class StacksUsingArray{
    T *data;
    int nextIndex;
    int capacity;

    public:

    StacksUsingArray(){
        
        data = new T[4];
        nextIndex = 0;
        capacity = 4;

    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        if(nextIndex == 0){
            return true;
        }else{
            return false;
        }

        // OR return nextIndex==0;
    }

    void push(T element){

        if(nextIndex == capacity){

            T *newData = new T[capacity*2];
            for(int i = 0; i<capacity; i++){
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
            capacity = capacity*2;
            
        }

        data[nextIndex] = element;
        nextIndex++;

    }


    T top(){

        if(nextIndex == 0){
            cout<< "The stack is EMPTY!" << endl;
            return 0;
        }
        return data[nextIndex-1];

    }

    T pop(){

        if(isEmpty()){
            cout << "The stack is EMPTY!" << endl;
            return 0;
        }
        capacity++;
        nextIndex--;
        return data[nextIndex];
    
    }



};