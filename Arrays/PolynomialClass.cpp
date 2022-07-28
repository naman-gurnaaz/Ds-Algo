#include <iostream>
using namespace std;

class Polynomial{
    int *degCoeff;
    int capacity;

    public:

    //Default Constructor
    Polynomial(){
        degCoeff = new int[5];
        capacity = 5;
        for(int j = 0; j < capacity; j++){
            degCoeff[j] = 0;
        } 
    }

    void setCoefficient(int d, int coeff){
        if(d == capacity){
            int *newDeg = new int[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newDeg[i] = degCoeff[i];
            }

            delete [] degCoeff;
            degCoeff = newDeg;
            capacity *=2;
        }
        degCoeff[d] = coeff;
    }

    Polynomial(Polynomial const &p){
        this -> degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
    }

    void operator=(Polynomial const &p){
        this -> degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
    }

    void print(){
        for(int i = 0; i < capacity; i++){
            if(degCoeff[i]!=0){
                cout << degCoeff[i]<< "x"<< " ";
            }
            cout << endl;
        }
    }

    Polynomial operator+(Polynomial const &p){
        
    }
};