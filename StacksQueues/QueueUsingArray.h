#include <iostream>
using namespace std;
template <typename T>

class QueueArray{

    T *data;
    int nextIndex, firstIndex;
    int size;
    int capacity;

    public:
        QueueArray(int s){
            data = new T[s];
            nextIndex = 0;
            firstIndex = -1;
            size = 0;
            capacity = s;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size == 0;
        }

        void enqueue(T element){    //insert an element
            if(size == capacity){

                T *newData = new T[capacity *2];
                int j = 0;

                for(int i = firstIndex; i < capacity; i++){
                    newData[j] = data[i];
                    j++;
                }
                for(int i = 0; i < firstIndex; i++){
                    newData[j] = data[i];
                    j++;
                }

                delete []data;
                data = newData;
                firstIndex = 0;
                nextIndex = capacity;
                capacity *= 2;

            }
            
            data[nextIndex] = element;
            nextIndex = ((nextIndex + 1) % capacity);
            size++;
            if(firstIndex == -1){
                firstIndex = 0;
            }
        }

        T front(){
            if(isEmpty()){
                cout << "The queue is empty." << endl;
                return 0;
            }
            return data[firstIndex];
        }

        T dequeue(){
            if(isEmpty()){
                cout << "The queue is empty." << endl;
                return 0;
            }
            T temp = data[firstIndex];
            firstIndex = ((firstIndex + 1) % capacity);
            size--;
            if(size == 0 ){
                firstIndex = -1;
                nextIndex = 0;
            }
            return temp;
        }
};