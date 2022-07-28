#include <iostream>

using namespace std;

template <typename T>
class QueueWithArrays{
    T *data;
    int nextIndex;
    int size;
    int capacity;
    int firstIndex;

    public:

    QueueWithArrays(int s){
        data = new T[s];
        size = 0;
        capacity = s;
        nextIndex = 0;
        firstIndex = -1;
    }

    bool isEmpty(){
        return size==0;
    }

    int getSize(){
        return size;
    }

    T front(){
        if(isEmpty()){
            cout << "Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    void enqueue(T element){

        if(size == capacity){

            T *newData = new T[capacity*2];
            int j = 0;

            for(int i =firstIndex; i<capacity; i++){
                newData[j] = data[i];
                j++;
            }

            for(int i = 0; i < firstIndex; i++){
                newData[j] = data[i];
            }

            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity = capacity*2;

        }
        data[nextIndex]= element;
        nextIndex = (nextIndex+1)%capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    T dequeue(){
        if(size == 0){
            cout << "Queue is empty"<< endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size == 0){
            nextIndex = 0;
            firstIndex = -1;
        }
        return ans;
    }
};