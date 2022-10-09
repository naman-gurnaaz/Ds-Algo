#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/*
def differenceofSum(n.m)

The function takes two integrals m and n as arguments. You are required to obtain the total of all integers ranging between 1 to n (both inclusive) which are not divisible by m. You must also return the distinction between the sum of integers not divisible by m with the sum of integers divisible by m.

Assumption

m > 0 and n > 0
Sum lies within the integral range
*/

int differenceOfSum(int m, int n){
    vector < int> notDiv;
    int divisible = 0, notDivisible = 0;
    for(int i = 1; i <= n; i++){
        if(i % m == 0){
            divisible = divisible + i;
        }
        if(i % m != 0){
            notDivisible += i;
            notDiv.push_back(i);
        }
    }
    if(divisible > notDivisible){
        return (divisible - notDivisible);
    }
    else{
        return (notDivisible - divisible);
    }

}

/*
def LargeSmallSum(arr)

The function takes an integral arr which is of the size or length of its arguments. Return the sum of the second smallest element from the odd position ‘arr’ and the largest element from the even position.

Assumption

Every array element is unique.
We are treating the zero position as 7th.
Note:

If the array is empty, return 0.
If array length is 3 or <3, return 0.
*/

int LargeSmallSum(int *array, int n){
    if(n<=3){
        return 0;
    }
    if(array == nullptr){
        return 0;
    }
    int evenarray[n];
    int oddarray[n];
    evenarray[0] = array[0];
    int evencount = 1, oddcount = 0;
    for(int i = 1; i < n; i++){
        if(i%2 == 0){
            evenarray[evencount] = array[i];
            evencount++;
        }else{
            oddarray[oddcount] = array[i];
            oddcount++;
        }
    }
    sort(evenarray, evenarray+n);
    sort(oddarray, oddarray+n);
    int answer = evenarray[evencount-2] + oddarray[1];    //the array terms here can be changed as per thr questions
    return answer;
}


/*
Write a function to validate if the provided two strings are anagrams or not. If the two strings are anagrams, then return ‘yes’. Otherwise, return ‘no’.
*/

void isAnagram(string str1, string str2){
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if(str1 == str2){
        cout << "Yes"<< endl;
    }else{
        cout << "No" << endl;
    }
}



/*
def Productsmallpair(sum,arr)

This function accepts the integers sum and arr. It is used to find the arr(j) and arr(k), where k ! = j. arr(j) and arr(k) should be the smallest elements in the array.

Keep this in mind:

If n<2 or empty, return –1.
If these pairs are not found, then return to zero.
Make sure all the values are within the integer range.
Example

Input:
Sum: 9
Arr: 5 4 2 3 9 1 7

Output:
2

Explanation

From the array of integers, we have to select the two smallest numbers, i.e 2 and 1. Sum of these two (2 + 1) = 3. This is less than 9 (3 < 9). The product of these two is 2 (2 x 1 = 2) Hence the output is integer 2.

*/


int ProductSmallPair(int sum, int *array, int n){
    if(n < 2 ){
        return -1;
    }
    sort(array, array+n);
    int p1, p2;
    for(int i = 0; i < n; i++){
        if(array[i] + array[i+1] <= sum){
            return (array[i] * array[i+1]);
        }
    }
    return 0;
}



/*
For writing numbers, there is a system called N-base notation. This system uses only N-based symbols. It uses symbols that are listed as the first n symbols. Decimal and n-based notations are 0:0, 1:1, 2:2, …, 10:A, 11:B, …, 35:Z.

Perform the function: Chats DectoNBase(int n, int num)

This function only uses positive integers. Use a positive integer n and num to find out the n-base that is equal to num.

Steps

Select a decimal number and divide it by n. Consider this as an integer division.

Denote the remainder as n-based notation.

Again divide the quotient by n.

Repeat the above steps until you get a 0 remainder.

The remainders from last to first are the n-base values.

Assumption
1 < n < = 36

Example

Input:
N: 12
Num: 718

Output:
4BA

Explanation:

num	   Divisor	  Quotient	  Remainder
718	     12	       59	      10(A)
59	     2	       4	      11(B)
4        12	       0	      4(4)

Sample input:
N: 21
Num: 5678

Sample output:
CI8

*/

string DectoNBase(int n, int num){
    vector<int> notation;
    string ans;
    int quotient = num / n;
    notation.push_back(num%n);
    while (quotient != 0){
        notation.push_back(quotient % n);
        quotient = quotient/n;
    }
    for(int i =0; i < notation.size(); i++){
        if(notation[i] > 9){
            ans = (char)(notation[i] - 9 + 64) + ans;
        }else{
            ans = to_string(notation[i]) + ans;
        }
    }
    return ans;
}



/*
When the sum of the digits exceeds a total of 9, a carry digit is added to the right-left of the digit. Execute the function: Int Numberofcarry(Integer num 1, Integer num 2)

Assumption

num1, num2 > = 0

Example

Input:
num1: 451
num2: 349

Output:
2

Explanation

When we add these two numbers from the right to the left, we get two carries. The value of each of the carries is 1. Hence, the output is the total of these two carries, i.e., 2.

Sample input:
num1: 23
num2: 563

Sample output:
0

*/

int NumberofCarry(int n1, int n2){
    int count = 0;
    int temp1, temp2, sum, carry =0;
    while(n1 != 0 && n2 != 0){
        temp1 = n1%10;
        temp2 = n2%10;
        sum  = carry + temp1 + temp2;
        if(sum > 9){
            carry = 1;
            count++;
        }else{
            carry = 0;
        }
        n1 = n1/10;
        n2 = n2/10;
    }
    while(n1 != 0){
        temp1 = n1%10;
        sum = carry + temp1;
        if(sum > 9){
            carry = 1;
            count ++;
        }else{
            carry = 0;
        }
        n1 = n1/10;
    }
    while(n2 != 0){
        temp2 = n2%10;
        sum = carry + temp2;
        if(sum > 9){
            carry = 1;
            count ++;
        }else{
            carry = 0;
        }
        n2 = n2/10;
    }
    return count;
}



/*
The given function has a string (str) and two characters, ch1 and ch2. Execute the function in such a way that str returns to its original string, and all the events in ch1 are replaced by ch2, and vice versa.

Replacecharacter(Char str1, Char ch1, Int 1, Char ch2)

Assumption

This string has only alphabets that are in lower case.

Example

Input:
str: apples
ch1: a
ch2: p

Output:
paales

Explanation
All the ‘a’ in the string is replaced with ‘p’. And all the ‘p’s are replaced with ‘a’.
*/

void ReplaceChar(char str[], char ch1, char ch2, int n){
    
    for(int i = 0; i < n; i++){
        if(str[i] == ch1){
            str[i] = ch2;
        }
        else if(str[i] == ch2){
            str[i] = ch1;
        }
    }
}



/*
Perform the function: Int operationchoices(int c, int n, int a, int b). This function considers three positive inputs of a, b and c.

Execute the function to get:
(a + b), if c = 1
(a / b), if c = 4
(a – b), if c = 2
(a x b), if c = 3

Example:

Input:
a: 12
b: 16
c: 1

Output:
28

Explanation
C = 1, hence the function is (a + b). Hence, the output is 28.
*/

int operationChoices(int a, int b, int c){
    if(c == 1){
        return (a+b);
    }
    else if(c == 2){
        return (a-b) ;
    }
    else if(c == 3){
        return (a*b);
    }
    else if(c == 4){
        return (a/b);
    }
}


/*
Perform the function Int calculate(int m, int n). This function needs two positive integers. Calculate the sum of numbers between these two numbers that are divisible by 3 and 5.

Assumption
m > n > = 0

Example

Input:
m: 12
n: 50

Output:
90

Explanation
The numbers between 12 and 50 that are divisible by 3 and 5 are 15, 30, and 45. The sum of these numbers is 90.
*/


int calculate(int n, int m){
    
    int sum = 0;
    for(int i = n; i <= m; i++){
        if((i%3 == 0) && (i%5 == 0)){
            sum =  sum + i;
        }
    }
    return sum;
}


/*
Given two integers n and m. The problem is to find the number closest to n and divisible by m. If there are more than one such number, then output the one having maximum absolute value. If n is completely divisible by m, then output n only. Time complexity of O(1) is required.
*/

int absolute(int n){
    if(n < 0){
        n = (-1) * n;
    }
    return n;
}

int NearestNumber(int num, int m){
    int q = num/m;
    int n1 = q*m;
    int n2;
    if(num*m > 0){
        n2 = m*(q+1);
    }else{
        n2 = m*(q-1);
    }
    if(absolute(num - n2) > absolute(num-n1)){
        return n1;
    }else{
        return n2;
    }
}


/*
you are given a function 
int* PriductArray(int *arr, int n)

The function accepts an int array 'arr' of length 'n'. Implement the function to modify the given array such that 
each index i is the product of the nos at all other indices except that one.

eg :

arr: 2 3 7 5

op : 105 70 30 42
*/

int* ProductArray(int *arr, int n){
    if(n<=1){
        return nullptr;
    }
    int product=1;
    for(int i = 0; i < n; i++){
        product = product * arr[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] = product/arr[i];
    }
    return arr;
}



int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i =0 ; i < n; i++){
        cin >> arr[i];
    }
    arr = ProductArray(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i]<<  " ";
    }
}