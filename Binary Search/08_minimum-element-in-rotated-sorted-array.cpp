#include<bits/stdc++.h>
using namespace std;

// It is similar to finding the pivot of a rotated sorted array

int findMin(vector<int>arr)
{
    int n = arr.size();
    int low = 0 , high = n-1;
    int mid = low + (high-low)/2;
    int ans = INT_MAX;
    while(low<=high)
    {
        if(arr[mid]>=arr[low]){
            ans = min(ans,arr[low]);
            low = mid+1;
        }
        else{
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
        mid = low + (high-low)/2;
    }
    return ans;
}

int main()
{
    vector<int>a = {7,8,0,2,3};
    cout<<findMin(a);
    return 0;
}