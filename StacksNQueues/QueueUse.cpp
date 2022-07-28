#include <iostream>
#include "QueueUsingArrays.cpp"
#include "QueueUsingLL.cpp"

using namespace std;

int main(){
    QueueUsingLL<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);

    cout << q1.front()<<endl;
    cout<< q1.dequeue() << endl;
    cout<< q1.dequeue() << endl;
    cout<< q1.dequeue() << endl;
    cout << q1.front()<<endl;
    cout << q1.getSize()<<endl;
    cout << q1.isEmpty()<<endl;
    
}