#include<bits/stdc++.h>
using namespace std;

int countDays(vector<int>arr, int capacity)
{
    int n = arr.size();
    int sum = 0;
    int numberOfdays = 1;
    for(int i=0;i<n;i++)
    {
        
        if(sum+arr[i]>capacity)
        {
            numberOfdays++;
            sum = arr[i];

        }
        else{
            sum += arr[i];
        }
    }
    return numberOfdays;
}

int minimumCapacity(vector<int>arr,int days)
{
    int maxi = INT_MIN;
    int weightSum = 0;
    for(int i=0;i<arr.size();i++)
    {
        maxi = max(maxi,arr[i]);
        weightSum += arr[i];
    }
    int low = maxi;
    int high = weightSum;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int numberOfdays = countDays(arr,mid);
        if(numberOfdays<=days){
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
    vector<int>weights = {5 ,4, 5, 2, 3, 4, 5, 6};
    cout<<minimumCapacity(weights,5)<<endl;
    return 0;
}