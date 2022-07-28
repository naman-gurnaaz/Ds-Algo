#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int s1, int b[], int s2, int c[]){
    int i=0, j=0, k=0;

    while(i<s1 && j<s2){

        if(a[i] < b[j]){
            c[k] = a[i];
            k++;
            i++;
        }else{
            c[k] = b[j];
            j++;
            k++;
        }
    }

    while(i<s1){
        c[k] = a[i];
        k++;
        i++;
    }

    while(j < s2){
        c[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int a[], int si, int ei){

    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2 ;

    int a1[500], a2[500];
    int i=0;
    for(; i <= mid; i++){
        a1[i] = a[i];
        i++;
    }

    int k = mid+1;
    for(; k<=ei; k++){
        a2[k] = a[i];
        k++;
    }

    mergeSort(a, si, mid);
    mergeSort(a, mid+1, ei);

    merge(a1, mid-si+1, a2, ei-mid, a);
}

void swap(int a, int b){
    int temp = a;
    a = b; 
    b = temp;
}

int partition(int a[], int si, int ei){
    int x = a[si];
    int count=0;
    for(int i = si+1; i<ei; i++){
        if(a[i]<x){
            count++;
        }
    }
    int position = si+count;
    int temp = a[si];
    a[si] = a[position];
    a[position] = temp;

    int i = si, j = ei;
    while (i<position && j>position)
    {
        if(a[i]<x){
            i++;
        }
        else if(a[j]>x){
            j--;
        }
        else{
            int temp = a[i];
            a[i] = a[j]; 
            a[j] = temp;
            i++;
            j--;
        }
    }
    
    return position;
}

void quickSort(int a[], int si, int ei){
    if(si < ei){
        int c = partition(a, si, ei);
        quickSort(a, si, c-1);
        quickSort(a, c+1, ei);
    }else{
        return;
    }
}

int subsequences(string ip, string op[]){
    if(ip.empty()){
        op[0] = "";
        return 1;
    }

    string smallString = ip.substr(1);
    int smallOutput = subsequences(smallString, op);

    for(int i = 0; i < smallOutput; i++){
        op[i + smallOutput] = ip[0]+op[i];
    }

    return 2*smallOutput;
}

void pairStar(char s[], int si){

    if(s[si] == '\0'|| s[si+1] == '\0'){
        return;
    }
    pairStar(s, si+1);

    int len = 0;
    for(int i = 0; s[i] != '\0'; i++){
        len++;
    }

    if(s[si]==s[si+1]){
        s[len+1] = '\0';
        int i = 0;
        for(i = len-1; i >=si+1; i--){
            s[i+1] = s[i];
        }
        s[i+1] = '*';
    }
}

bool checkAB(string s, int si){
    if(s[si] == '\0'){
        return true;
    }

    if(s[si] != 'a'){
        return false;
    }

    if(s[si+1] != '\0' && s[si+2] != '\0'){

        if(s[si+1] == 'b' && s[si+2] == 'b'){
            return checkAB(s, si+3);
        }
    }

    return checkAB(s, si+3);
}

int binarySearch(int ip[], int size, int x){
    int si = 0; 
    int ei = size-1;
    while(si<=ei){
        int mid = (si+ei)/2;
        if(ip[mid] == x){
            return mid;
        }
        else if(x < ip[mid]){
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }
    return -1;
}

void replaceCharRecursively(char ip[], char a, char b){
    if(ip[0] == '\0'){
        return;
    }

    if(ip[0] == a){
        ip[0] = b;
    }

    replaceCharRecursively(ip+1, a, b);
}

int stairCase(int n){
    if(n==0||n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int ans = stairCase(n-3) + stairCase(n-2) + stairCase(n-1);
    return ans;
}

int subsetOfArray(int ip[], int size, int op[][20]){
    if(size <= 0){
        op[0][0] = 0;
        return 1;
    }

    int smallOp = subsetOfArray(ip+1, size-1, op);
    for(int i=0; i<smallOp; i++){
        op[i+smallOp][0] = op[i][0]+1;
        op[smallOp+i][1] = ip[0];

        for(int j =1; j<smallOp; j++){
            op[i+smallOp][j+1] = op[i][j];
        }
    }
    return 2*smallOp;
}

int main(){

    int n;
    cin >> n;
    int ans = stairCase(n);
    cout << ans << endl;

}