//brackets are balanced or not?

#include <iostream>
#include "StackUsingLL.cpp"
using namespace std;

bool checkBalance(char *brkt){

    Stack<char> c;

    for(int i = 0; brkt[i] != '\0'; i++){

        if(brkt[i] == '{' || brkt[i] == '[' || brkt[i] == '('){

            c.push(brkt[i]);
            
        }

        if(brkt[i] == ')'){
            if(!c.isEmpty() && c.top() == '('){
                c.pop();
            }
        }

        if(brkt[i] == ']'){
            if(!c.isEmpty() && c.top() == '['){
                c.pop();
            }
        }

        if(brkt[i] == '}'){
            if(!c.isEmpty() && c.top() == '{'){
                c.pop();
            }
        }
    }

    if(!c.isEmpty()){
        return false;
    }

    return true;

}

int main(){
    char str[1000];
    cin >> str;
    if(checkBalance(str)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

}