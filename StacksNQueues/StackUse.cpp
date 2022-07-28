#include <iostream>
#include <cstring>
#include "StacksUsingArray.cpp"
#include "StacksWithLL.cpp"
using namespace std;


//BALANCED BRACKETS PRACTICE QUESTION:
bool checkBrackets(char *s){

    StackWithLL<char> b;

    int length = strlen(s);

    for(int i = 0; i<length; i++){

        if(s[i] == '{'|| s[i] == '['|| s[i] == '('){
            b.push(s[i]);
        }

        if(s[i] == '}'){
            if(!b.isEmpty() && b.top() == '{'){
                b.pop();
            }else{
                return false;
            }
        }
        else if(s[i] == ']'){
            if(!b.isEmpty() && b.top() == '['){
                b.pop();
            }else{
                return false;
            }
        }
        if(s[i] == ')'){
            if(!b.isEmpty() && b.top() == '('){
                b.pop();
            }else{
                return false;
            }
        }
    }

    if(!b.isEmpty()){
        return false;
    }else{
        return true;
    }
}


int main(){
    char str[1000000];
    cin >> str;
    if(checkBrackets(str)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}