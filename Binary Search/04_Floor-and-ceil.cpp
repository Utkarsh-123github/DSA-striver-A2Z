#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getCeil(vector<int>&a,int x)
{
    int n = a.size();
    int ans = -1;
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(a[mid]>=x){
            ans = a[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int getFloor(vector<int>&a,int x)
{
    int n = a.size();
    int low = 0 , high = n-1 , ans = -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(a[mid]<=x)
        {
            ans = a[mid];
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main()
{
    vector<int>a = {3, 4, 7, 8, 8, 10};
    cout<<" The value of Ceil for x = 5 is "<<getCeil(a,5)<<endl;
    cout<<" The value of Floor for x = 5 is "<<getFloor(a,5)<<endl;
    return 0;
}