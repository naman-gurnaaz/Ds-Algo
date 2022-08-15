#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


bool isPrime(int n){     //check if no. is prime
    if(n <= 1){
        return false;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

float sumOfSeries(float a, float d, float n){
    float sum = 0;
    for(float i=1; i<=n; i++){
        sum += (a + (i-1)*d) ; 
    }
    return sum;
}

float sumOfSeriesBetter(float a, float d, float n){
    float sum = ((n/2) * (2*a + (n-1)*d));
    return sum;
}

float sumOfGeometricSeries(float a, float r, float n){
    float sum=0;
    if(r > 1){
        sum = (a* (pow(r, n) - 1))/(r - 1);
        return sum;
    }else{
        sum = (a* (1 - pow(r, n)))/(1 - r);
        return sum;
    }
}

void printDivisors(int n){
    vector<int> divisors;

    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(n/i == i){
                cout << i << " ";
            }
            else{
                cout << i << " ";
                divisors.push_back(n/i);
            }
        }
    }

    for(int i = divisors.size()-1; i >= 0;  i--){
        cout << divisors[i] << " ";
    }
}

int replace0With5(int n){
    if(n == 0){
        return 0;
    }
    int digit = n % 10;
    if(digit == 0){
        digit = 5;
    }
    return replace0With5(n/10) * 10 + digit;
}

bool checkHarshad(int n){     //An n-harshad number is an integer number divisible by the sum of its digit in base n.
    string num = to_string(n);
    int sum = 0;
    for(int i = 0; i < num.length(); i++){
        sum = sum + (num[i] - '0');
    }
    if(n % sum == 0){
        return true;
    }
    else{
        return false;
    }
}

long long findGCD(long long int n, long long int m){
    
    if(m==0){
        return n;
    }
    return findGCD(m, n%m);
}

long long findLCM(int n, int m){
    int lcm = n*m/findGCD(n, m);
    return lcm;
}

int fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return (n+fact(n-1));
}


int f[10];
 
// Fills factorials of digits from 0 to 9.
void preCompute()
{
    f[0] = f[1] = 1;
    for (int i = 2; i<10; ++i){
        f[i] = f[i-1] * i;
    }
}

bool checkStrong(int num){
    preCompute();
    int sum = 0;
    int temp = num;

    while(temp){
        sum += f[temp%10];
        temp /=10;
    }
    return (sum == num);
}

bool checkLeapYear(int year){
    if(year % 400 == 0){
       return true;
    }

    if(year%4 == 0 && year%100 != 0){
        return true;
    }

    return false;
}

int reverseDigits(int num){
    int revnum = 0;
    while(num > 0){
        revnum = revnum*10 + num%10;
        num = num/10;
    }
    return revnum;
}


void meanAndMedian(int arr[], int size){
    int mean, median;
    if(size == 0){
        return;
    }
    int x = size/2;
    if(size%2 == 0){
        median = (arr[x] + arr[x-1])/2;
        cout << "The median of the array is " << median;
    }else{
        median = arr[x];
        cout << "The median of the array is " << median;
    }
    int sum;
    for(int i = 0; i<size; i++){
        sum = sum + arr[i];
    }
    mean = sum/size;
    cout << "The mean of the array is " << mean;
}



int equilibriumIndex(int arr[], int n){
    int totalSum = 0;
    int leftSum  = 0;

    for(int i=0; i<n; i++){
        totalSum = totalSum+ arr[i];
    }

    for(int i = 0; i< n; i++){

        int rightSum = totalSum - leftSum - arr[i];
        if(rightSum == leftSum){
            return i;
        }
        leftSum = leftSum + arr[i];
    }
    return -1;
}


/*
Given an integer N, the task is to find the number of prime numbers 
up to N that can be expressed as a sum of consecutive primes.
*/

int sumOfPrimes(int n){
    int count  = 0;
    vector<int> primes;

    for(int i = 2; i < n; i++){
        if(isPrime(i) == true){
            primes.push_back(i);
        }
    }

    int sum = primes[0];
    for(int i = 1; i < primes.size(); i++){
        sum += primes[i];
        if(sum > n){
            break;
        }
        if(isPrime(sum) == true){
            count++;
        }
    }
    return count;
}

/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.
*/

int fibb(int n){
    int a = 0, b=1, c, i;
    if(n==0){
        return a;
    }
    for(i = 2; i <= n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return b;
}

int countWays(int stairs){
    return fibb(stairs + 1);
}


/*
A number n is said to be an Abundant Number if the sum of all the proper divisors of the number denoted by sum(n) is greater than the value of the number n. And the difference between these two values is called abundance. 

Given a number n, our task is to find if this number is an Abundant number or not. 
The first few Abundant Numbers are: 12, 18, 20, 24, 30, 36, 40, 42, 48, 54, 56, 60, 66 ….. 
*/

vector<int> getDivisors(int n){
    vector<int> divs;
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            if(n/i == i){
                divs.push_back(i);
            }else{
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
    }
    return divs;
}


bool isAbundant(int n){
    int sum = 0;
    vector<int> divisors = getDivisors(n);
    /*for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            if(n/i == i){
                divs.push_back(i);
            }else{
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
    }*/
    for(int i = 0; i < divisors.size(); i++){
        sum += divisors[i];
    }

    if(sum > n){
        return true;
    }else{
        return false;
    }
}


/*
Given a prime number N   . The task is to check if it is possible to express N   as sum of two separate prime numbers.
*/

bool isPossible(int n){
    if(isPrime(n) && isPrime(n-2)){
        return true;
    }else{
        return false;
    }
}


/*
Given a number, check if it is square-free or not. A number is said to be square-free if no prime factor divides it more than once, i.e., the largest power of a prime factor that divides n is one. First few square-free numbers are 1, 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30, 31, 33, 34, 35, 37, 38, 39, …
*/

bool squareFree(int n){
    if(n%2 == 0){
        n = n/2;
        if(n%2 == 0){
            return false;
        }
    }
    for(int i = 3; i <= sqrt(n); i= i+2){
        if(n%i == 0){
            n = n/i;
            if(n%i == 0){
                return false;
            }
        }
    }
    return true;
}


/*
A number N is said to be Primitive Abundant Number if N is an Abundant number and all it’s proper divisors are Deficient Numbers. 
A number n is said to be Deficient Number if sum of all the divisors of the number denoted by divisorsSum(n) is less than twice the value of the number n. And the difference between these two values is called the deficiency.
Mathematically, if below condition holds the number is said to be Deficient:

divisorsSum(n) < 2 * n
deficiency = (2 * n) - divisorsSum(n)
*/

bool isDeficient(int n){
    int sum =0;
    vector<int> divisors = getDivisors(n);
    for(int i = 0; i<divisors.size(); i++){
        sum += divisors[i];
    }
    if(sum < (2*n)){
        return true;
    }

    return false;
}

bool primitiveAbundant(int n){
    if(!isAbundant(n)){
        return false;
    }
    vector<int> divs = getDivisors(n);
    for(int i = 0; i < divs.size(); i++){
        if(isAbundant(n) && isDeficient(divs[i])){
            return true;
        }
    }
    return false;
}


/*
Given a number x, determine whether the given number is Armstrong number or not. 

A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if. 

abcd… = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + …. 

Example: 

Input : 153
Output : Yes
153 is an Armstrong number.
1*1*1 + 5*5*5 + 3*3*3 = 153

Input : 120
Output : No
120 is not a Armstrong number.
1*1*1 + 2*2*2 + 0*0*0 = 9

Input : 1253
Output : No
1253 is not a Armstrong Number
1*1*1*1 + 2*2*2*2 + 5*5*5*5 + 3*3*3*3 = 723

Input : 1634
Output : Yes
1*1*1*1 + 6*6*6*6 + 3*3*3*3 + 4*4*4*4 = 1634
*/

int order(int n){
    int x=0;
    while(n){
        x++;
        n = n/10;
    }
    return x;
}


bool isArmstrong(int n){

    int p = order(n);
    int temp = n, sum = 0;
    while(temp > 0){
        int r = temp % 10;
        sum += round(pow(r, p));
        temp /= 10;
    }
    if(sum == n){
        return true;
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    cout << isArmstrong(n) << endl;
}