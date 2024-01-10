#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n)
{
    int low = 1, high = n;
    int ans = -1;
    long long mid = low + (high-low)/2;
    while(low<=high){
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            ans = mid;
            low = mid+1;

        }
        else{
            high = mid-1;
        }
        mid = low + (high - low)/2;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<squareRoot(n)<<endl;
    return 0;
}