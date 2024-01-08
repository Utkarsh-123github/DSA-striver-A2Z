#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Approach:- Simple sorting

void sort012(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

// Better Apporach :- Using count of each element
// TC = o(n)+o(n)
// SC = O(1)

void sort012_1(vector<int>&arr,int n){
    int count0=0 , count1=0 , count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) count0++;
        else if(arr[i]==1) count1++;
        else count2++;
    }
    for(int i=0;i<count0;i++){
        arr[i]=0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i]=1;
    }
    for(int i=count0+count1;i<n;i++){
        arr[i]=2;
    }
}

/* Optimal Approach :- Using dutch national flag algorithm
   TC = O(n)  
   SC = O(1) 
*/

void sort012_2(vector<int>&arr,int n){
    int low = 0 , mid = 0 , high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> a={0,1,2,2,1,0};
    sort012_2(a,6);
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}