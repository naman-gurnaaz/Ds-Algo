/*

John is a geologist, and he needs to count rock samples in order to send it to a chemical laboratory. He has a problem. The laboratory only accepts rock samples by a range of sizes in ppm (parts per million). John needs your help. Your task is to develop a program to get the number of rocks in each range accepted by the laboratory.

Problem Statement: Given an array samples[] denoting sizes of rock samples and a 2D array ranges[], the task is to count the rock samples that are in the range ranges[i][0] to ranges[i][1], for every possible 1 <= i <= N.

Input: samples[] = {345, 604, 321, 433, 704, 470, 808, 718, 517, 811}, ranges[] = {{300, 380}, {400, 700}}
Output: 2 4
Explanation: 
Range [300, 380]: Samples {345, 321} lie in the range. Therefore, the count is 2. 
Range [400, 700]: Samples {433, 604, 517, 470} lie in the range. Therefore, the count is 4.

Input: samples[] = {400, 567, 890, 765, 987}, ranges[] = {{300, 380}, {800, 1000}
Output: 0 2

*/


#include<iostream>
#include<vector>

using namespace std;

void CountRocks(int samples[], int ranges[][2], int size, int row){

    vector<int> count;

    for(int i = 0; i< row; i++){

        int c = 0;
        int high = ranges[i][1];
        int low = ranges[i][0];

        for(int i = 0; i < size; i++){

            if(samples[i] <= high && samples[i] >= low){
                c++;
            }
        }
        
        count.push_back(c);
    }

    for(int i = 0; i < count.size(); i++){
        cout << count[i] << " ";
    }
}


int main(){
    int size, row;
    cin >> size;
    int samples[size];
    for(int i = 0; i< size; i++){
        cin >> samples[i];
    }
    cin >> row;
    int ranges[row][2];
    for(int i = 0; i < row; i++){
        for(int j=0; j < 2; j++){
            cin >> ranges[i][j];
        }
    }
    CountRocks(samples, ranges, size, row);
}