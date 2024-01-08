// In the array all numbers appear twice except one number which appears only once. Find that number.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute force approach :- Using concept of Linear search
// TC = O(n^2) SC = O(1)
int num(int arr[],int n){
    for(int i=0;i<n;i++){
        int num=arr[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==num){
                count++;
            }
        }
        if(count==1){
            return arr[i];
        }
    }
    return -1;
}

// Better Approach using map data structure
// Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
// Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.

int num_1(int arr[],int n){
    map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}

// Optimal approach using XOR
// TC = O(n)
// SC = O(1)

int num_2(int arr[],int n){
    int xorr=0;
    for(int i=0;i<n;i++){
        xorr = xorr^arr[i];
    }
    return xorr;
}

int main()
{
    int arr[11]={1,1,2,2,3,3,4,4,5,6,6};
    cout<<num_2(arr,11);
}
