#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int>arr,int target)
{
    int n = arr.size();
    int ans = n;
    int low = 0 , high = n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]>target){
            ans = mid;
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
    vector<int>a = {3,5,8,15,19};
    cout<<"Lower bound of target = 9 is "<<upperBound(a,9)<<endl;
    cout<<"Lower bound of target = 20 is "<<upperBound(a,20)<<endl;
    return 0;
}