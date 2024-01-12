#include<bits/stdc++.h>
using namespace std;

int maxElement(vector<int>arr)
{
    int n = arr.size();
    int maxi = arr[0];
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

int calculateHours(vector<int>arr , int bananaPerHour)
{
    int totalHours = 0;
    for(int i=0;i<arr.size();i++)
    {
        totalHours += ceil((double)arr[i] / (double)bananaPerHour);
    }
    return totalHours;
}

int minimumEatingRate(vector<int>arr , int givenHours)
{
    int n = arr.size();
    int low = 1 , high = maxElement(arr);
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int totalHours = calculateHours(arr,mid);
        if(totalHours<=givenHours)
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
    vector<int>a = {7,15, 6, 3};
    int givenHours = 8;
    cout<<"Minimum number of bananas to eat per hour so that monkey can finish all the bananas in "<<givenHours<<" hours is :- "<<minimumEatingRate(a,8)<<endl;
    return 0;
}