#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// brute approach :- TC = O(n^2) SC = O(1)
int majElem(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        
        int count = 0;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        if(count>arr.size()/2){
            return arr[i];
        }
    }
    return -1;
} 

// Better Approach :- Using hashing 
// TC = O(n*logn)+O(n)  SC = O(n)

int majElem_1(vector<int>arr){
    map<int,int>mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second > arr.size()/2){
            return it.first;
        }
    }
    return -1;
}

// Best Approach :- Using Moore's Voting Algorithm
// TC = O(n)+O(n)  SC = O(1)
/*
    Initialize 2 variables:
        Count –  for tracking the count of element
        Element – for which element we are counting
    Traverse through the given array.
    If Count is 0 then store the current element of the array as Element.
    If the current element and Element are the same increase the Count by 1.
    If they are different decrease the Count by 1.
    The integer present in Element should be the result we are expecting
*/

int majElem_2(vector<int>&arr){
    int n = arr.size();
    int element;
    int count = 0;
    for(int i=0;i<n;i++){
        if(count == 0){
            count=1;
            element = arr[i];
        }
        else if(element == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    int count1 = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            count1++;
        }
    }
    if(count1>n/2){
        return element;
    }
    return -1;
}

int main()
{
    vector<int>a = {1,2,2,2,2,2,3,4};
    cout<<majElem_2(a);
}