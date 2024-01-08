#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Approach :- Using two pointer approach
// T.C = O(n^2) S.C = O(1)

bool twoSum(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                return true;
            }
        }
    }
    return false;
}

// Better Approach :- Using hashing
// T.C = O(n) S.C = O(n)

bool twoSum_1(int arr[],int n,int k){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int more = k - a;
        if(mpp.find(more)!=mpp.end()){
            return true;
        }
        mpp[a] = i;
    }
    return false;
}

// Optimal Approach :-  Two pointer Apporach using sort

bool twoSum_2(vector<int>&arr,int n,int k){
    int i=0,j=n-1;
    sort(arr.begin(),arr.end());
    while(i<j){
        if(arr[i]+arr[j]==k){
            return true;
        }
        else if(arr[i]+arr[j]<k){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main()
{
    vector<int>arr={2,6,5,8,11};
    cout<<twoSum_2(arr,5,20);
}