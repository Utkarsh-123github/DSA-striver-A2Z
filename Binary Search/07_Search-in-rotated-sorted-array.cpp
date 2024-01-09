#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>arr)
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
        mid = low + (high-low)/2;
    }
    return mid;
}

int bsearch(vector<int>& a,int n,int key,int start,int end){
    int s=start;
    int e=end;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int search(vector<int>arr,int target)
{
    int n = arr.size();
    int low = 0 , high = n-1;
    int pivot = getPivot(arr);
    if(target >= arr[pivot] && target <= arr[high]){
        low = pivot;
        return bsearch(arr,n,target,low,high);
    }
    else{
        high = pivot-1;
        return bsearch(arr,n,target,low,high);
    }
}

int main()
{
    vector<int>arr = {12,15,18,2,4};
    cout<<search(arr,20)<<endl;
}