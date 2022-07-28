#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans = n*fact(n-1);
    return ans;
}

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int smolOp1 = fib(n-1);
    int smolOp2 = fib(n-2);
    int ans = smolOp1 + smolOp2;

    return ans;
}
bool is_sorted(int a[], int size){
    if(size == 0||size == 1){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    bool isSmallerSorted = is_sorted(a+1, size-1);
    return isSmallerSorted;
}

int firstIndex(int a[], int size, int x ){
    if(size ==0){
        return -1;
    }
    if(a[0]==x){
        return 0;
    }
    int fIndex = firstIndex(a+1, +size-1, x);
    if(fIndex == -1){
        return -1;
    }else{
        return fIndex+1;
    }
}

int lastIndex(int a[], int size, int x){
    if(size==0){
        return -1;
    }

    if(a[size-1]==x){
        return size-1;
    }

    int lindex = lastIndex(a, size-1, x);

    return lindex;
}

int countZeroes(int n){
    if(n==0){
        return 0;
    }
    if(n%10 == 0){
        return 1+countZeroes(n/10);
    }else{
        return countZeroes(n/10);
    }
}

bool palindrome(char s[], int si, int ei){
    if(ei < si){
        return true;
    }
    if(s[si] != s[ei]){
        return false;
    }
    cout<<s<<endl;
    bool pal = palindrome(s, si+1, ei-1);
    return pal;
}

int sumOfArray(int a[], int size){
    if(size == 0){
        return 0;
    }
    if(size==1){
        return a[0];
    }
    int sum = a[0] + sumOfArray(a+1, size-1);
    return sum;
}

int power(int x, int n){
    if(x==0){
        return 0;
    }
    if(x==1||n==0){
        return 1;
    }
    int ans = x*power(x, n-1);
    return ans;
}

bool checkNum(int a[], int size, int x){
    if(size==0){
        return false;
    }
    if(a[0] == x){
        return true;
    }
    bool isThere = checkNum(a+1, size-1, x);
    return isThere;
}

int sumOfDigits(int n){
    if(n==0){return 0;}
    int sum = n%10 + sumOfDigits(n/10);
    return sum;
}

double geoSum(int k){
    if(k==0){
        return 1;
    }
    double smallerSum = 1 + 0.5*geoSum(k-1);
    return smallerSum;
}

int multiply(int n, int m){
    if(n==0||m==0){
        return 0;
    }
    int ans = n+multiply(n, m-1);
    return ans;
}

void removeX(char s[]){
    if(s[0] == '\0'){
        return;
    }
    if(s[0]!='x'){
        removeX(s+1);
    }else{
        int i = 1;
        for(;s[i]!='\0'; i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeX(s);
    }
}

void replacePi(char s[]){

    if(s[0] == '\0'){
        return;
    }

    if(s[0] == 'p' && s[1] == 'i'){
        int len = strlen(s);
        s[len+2] = '\0';
        for(int i = len+1; i>=2; i--){
            s[i+2] = s[i];
        }
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';

    }

    replacePi(s+1);
}

void removeDupes(char s[]){
    if(s[0]=='\0'){
        return;
    }
    if(s[0] == s[1]){
        int i =1;
        for(; s[i] !='\0'; i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeDupes(s);
    }
    removeDupes(s+1);
}

int main(){
    /*int n, m;
    cin>>n >>m;
    int a[n];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    cout<< lastIndex(a, n, m)<< endl;
    int *pa = new int[n];
    for(int i = 0; i<n; i++){
        cin >> pa[i];
    }

    int max = -1;
    for(int i = 0; i<n; i++){
        if(max < pa[i]){
            max = pa[i];
        }
    }*/
    char  n[100];
    cin >> n;
    removeDupes(n);
    cout << n << endl;
    
}