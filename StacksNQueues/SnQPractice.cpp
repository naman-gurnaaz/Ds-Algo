#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int length(char *a){
    if(*a == 0){
		return 0;
    }
	else{
		return 1 + length(a+1);
    }
}

int minBracketRev(char ip[]){
    int len = length(ip);
    stack <int> s;
    

    if(len%2 == 0){

        int count = 0;

        for(int i = 0; i < len; i++){

            if(ip[i] == '{'){
                s.push(ip[i]);
                count++;
            }

            else if(ip[i] == '}' && !s.empty()){

                if(s.top() == '{'){
                    s.pop();
                    count--;
                }
                else{
                    s.push(ip[i]);
                    count++;
                }
            }

            else{
                s.push(ip[i]);
                count ++;
            }
        }
        return count/2;
    }

    else{
        return -1;
    }
}

int* stockSpan(int *price, int size){        //time complexity = O(n)
    stack <int> s;
    int *si = new int[size];
    si[0] = 1;
    s.push(0);
    for(int i = 1; i < size ; i++){
        while(!s.empty() && price[s.top()] <= price[i]){
            s.pop();
        }
        if(s.empty()){
            si[i] = i+1;
        }
        else{
            si[i] = i-s.top();
        }
        s.push(i);
    }
    return si;
}


void reverseStack(stack<int> &s1, stack<int> &s2){  //O(n^2)complexity with recusion
    if(s1.size() == 0){
        return;
    }
    int top = s1.top();
    s1.pop();

    reverseStack(s1, s2);

    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(top);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

void reverseQueue(queue<int> &q){
    if(q.size() == 0){
        return;
    }
    int x = q.front();
    q.pop();

    reverseQueue(q);
    q.push(x);
}

int main(){

    char bracket[1000000];
    cin >> bracket;
    int x = minBracketRev(bracket);
    cout << x << endl;


    /*
    int n;
    cin >> n;
    int *price = new int [n];
    for(int i = 0; i<n; i++){
        cin >> price[i];
    }

    int *si = stockSpan(price, n);
    for (int i = 0; i < n; i++){
        cout << si[i] << " ";
    }
    cout << endl;
        
    queue<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    
    reverseQueue(s1);
    cout << s1.front() << endl ;
    */
}