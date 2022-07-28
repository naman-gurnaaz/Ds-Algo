#include <iostream>
using namespace std;

class ComplexNumbers{
    private:
    int real;
    int imaginary;
    
    public:
    
    ComplexNumbers(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
    
    void print(){
        cout << this->real << "+" << this -> imaginary << "i" << endl;
    }
    
    void plus(ComplexNumbers const &c2){
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }
    
    void multiply(ComplexNumbers const &c2){
        real = real * c2.real;
        imaginary = imaginary * c2.imaginary;
    }
    
};
