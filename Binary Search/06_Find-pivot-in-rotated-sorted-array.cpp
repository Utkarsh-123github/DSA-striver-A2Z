#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>&arr)
{
    int n = arr.size();
    int low = 0 , high = n-1;
    int mid = low + (high-low)/2;

    while(low<high)
    {
        if(arr[mid]>=arr[0])
        {
            low = mid+1;
        }
        else{
            high = mid;
        }
        mid = low +(high-low)/2;
    }
    return mid;
}

int main()
{
    vector<int>a = {7,8,1,2,3,4};
    cout<<getPivot(a)<<endl;
    return 0;
}