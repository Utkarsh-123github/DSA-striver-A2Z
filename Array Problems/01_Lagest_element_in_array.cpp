#include<iostream>
#include<vector>
using namespace std;

// Optimal approach Github

int largest(vector<int>arr)
{
    int maxi = arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

