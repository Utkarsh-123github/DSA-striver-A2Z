#include<bits/stdc++.h>
using namespace std;

// brute approach

bool isPossible(vector<int>arr,int distance, int cows)
{
    int lastPosition = arr[0];
    int cowCount = 1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]-lastPosition >= distance){
            cowCount++;
            lastPosition = arr[i];
        }
    }
    return cowCount >= cows;
}

int aggressiveCows(vector<int>stalls , int cows)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int min = stalls[0];
    int max = stalls[n-1];
    for(int i=1;i<=max-min;i++)
    {
        if(isPossible(stalls,i,cows)){
            continue;
        }
        else{
            return i-1;
        }
    }
    return max-min;
}

// Optimal Approach

int AggressiveCows(vector<int>stalls,int cows)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int low = 0;
    int high = stalls[n-1]-stalls[0];
    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(isPossible(stalls,mid,cows)){
            ans = mid;
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
    vector<int>stalls = {0 ,3, 4, 7, 10, 9};
    cout<<AggressiveCows(stalls,4);
}