#include<bits/stdc++.h>
using namespace std;
int peak(vector<int>arr)
{
    int n = arr.size();
    if(n==1)return arr[0];
    if(arr[0]>arr[1])return arr[0];
    if(arr[n-1]>arr[n-2])return arr[n-1];
    int low = 1 , high = n-2;
    int mid = low + (high-low)/2;
    while(low<=high){
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])return arr[mid];
        else if(arr[mid]>arr[mid+1]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main()
{
    vector<int>arr = {7,8,9,3,2};
    cout<<peak(arr);
}