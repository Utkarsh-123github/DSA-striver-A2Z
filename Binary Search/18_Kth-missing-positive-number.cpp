#include<bits/stdc++.h>
using namespace std;

// Brute approach

int missingNum(vector<int>arr,int k){
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

// Better approach using hash array

int missing(vector<int>arr,int k)
{
    int hashSize = arr[arr.size()-1]+1;
    vector<int>hashArray(hashSize,0);
    for(int i=0;i<arr.size();i++)
    {
        hashArray[arr[i]]=1;
    }
    int count = 0;
    for(int i=0;i<hashSize;i++)
    {
        
        if(hashArray[i]==0)
        {
            count++;
            if(count == k+1) return i;
        }
        
    }
    return -1;
    
}

// Optiml Approach

int missing_Kth(vector<int>arr,int k)
{
    int n = arr.size();
    int low = 0 , high = n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int missingNumbers = arr[mid] - (mid+1);
        if(missingNumbers<k)
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return k+high+1;

}



int main()
{
    vector<int>arr = {4,5,7,10};
    cout<<missing_Kth(arr,6);
}