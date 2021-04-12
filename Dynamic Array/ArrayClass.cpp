#include <iostream>
using namespace std;

class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

        DynamicArray(){    //default constructor

            data = new int[5];
            nextIndex = 0;
            capacity = 5;

        }

        void add(int element){    //add elements while creating array
                                    // double the size of array when i >= capacity
            if(capacity == nextIndex){
                int *newData = new int[capacity*2];

                for (int i = 0; i < capacity; i++){
                    newData[i] = data[i];
                }
                delete []data;
                data = newData;
                capacity *= 2;
            }

            data[nextIndex] = element;
            nextIndex++;
        }

        int get(int i){      //return an element
            
            if(i<nextIndex){
                return data[i];
            }else{
                return -1;
            }
        }

        int add(int i, int element){    //add an element at the ith position and
                                        
            if(i < nextIndex){
                data[i] = element;
            }

            else if(i == nextIndex){
                add(element);
            }

            else{
                return;
            }
        }

        void print(){
            for(int i = 0; i < nextIndex; i++){
                cout << data [i] << " ";
                cout << endl;
            }
        }

        DynamicArray(DynamicArray const &d){    //copy construsctor
            this -> data = new int[d.capacity];

            for (int i = 0; i < d.capacity; i++){
                this -> data[i] = d.data[i];
            }

            this -> nextIndex = d.nextIndex;
            this -> capacity = d.capacity;
        }

        void operator=(DynamicArray const &d){    //copy operator overloading
                
            this -> data = new int[d.capacity];

            for (int i = 0; i < d.capacity; i++){
                this -> data[i] = d.data[i];
            }

            this -> nextIndex = d.nextIndex;
            this -> capacity = d.capacity;
        }

};