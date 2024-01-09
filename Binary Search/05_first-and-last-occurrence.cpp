#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int firstOccurrence(vector<int>&a,int num)
 {
    int n = a.size();
    int low = 0 , high = n-1;
    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(a[mid] == num){
            ans = mid;
            high = mid-1;
        }
        else if(a[mid]>num){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
 }

 int lastOccurrence(vector<int>&a,int num)
 {
    int n = a.size();
    int low = 0 , high = n-1;
    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(a[mid] == num){
            ans = mid;
            low = mid+1;
        }
        else if(a[mid]>num){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
 }

 int main()
 {
    vector<int>a = {1,2,2,2,4,5};
    cout<<"First occurrence of 2 is at index "<<firstOccurrence(a,2)<<endl;
    cout<<"Last occurrence of 2 is at index "<<lastOccurrence(a,2)<<endl;
    return 0;
 }