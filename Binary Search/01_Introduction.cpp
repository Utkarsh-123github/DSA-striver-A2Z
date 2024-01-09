#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Iterative Binary Search

int binarySearch(vector<int>&arr, int target)
{
    int n = arr.size();
    int low = 0 , high = n-1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

// Recursive Binary Search

int binarySearchRec(vector<int>&arr,int low,int high,int target)
{
    if(low>high) return -1;
    int mid = low + (high-low)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target){
        return binarySearchRec(arr,low,mid-1,target);
    }
    else{
        return binarySearchRec(arr,mid+1,high,target);
    }
}

int main()
{
    vector<int>a = {1,2,3,4,5,8,9,23};
    cout<< binarySearchRec(a,0,7,8);

}