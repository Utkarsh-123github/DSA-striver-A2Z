// Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses.
#include<bits/stdc++.h>
using namespace std;
// Brute approach 
bool isPossible(vector<int>arr , int k ,int m,int day)
{
    int numberOfBouquet = 0;
    int n = arr.size();
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=day)
        {
            count++;
        }
        else{
            numberOfBouquet += count/k;
            count = 0;
        }
    }
    numberOfBouquet += count/k;
    if(numberOfBouquet>=m) return true;
    else return false;

}

int roseGarden(vector<int> arr, int k, int m)
{
    int value = m*k;
    int n = arr.size();
    if(n<value) return -1;
    int maxi = arr[0];
    int mini = arr[0];
    for(int i=0;i<n;i++){
        maxi = max(arr[i],maxi);
        mini = min(arr[i],mini);
    }
    for(int i=mini;i<=maxi;i++)
    {
        if(isPossible(arr,k,m,i)) return i;
    }
    return -1;
}

// Optimal Approach using Binary search
// isPossible function from brute force approach is required here also

int bsearch(vector<int>arr,int k , int m)
{
    int maxi = arr[0];
    int mini = arr[0];
    for(int i=0;i<arr.size();i++){
        maxi = max(arr[i],maxi);
        mini = min(arr[i],mini);
    }

    int low = mini, high = maxi;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(isPossible(arr,k,m,mid))
        {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    int k = 3, m = 2;
    cout<<bsearch(arr,k,m);
    return 0;
}