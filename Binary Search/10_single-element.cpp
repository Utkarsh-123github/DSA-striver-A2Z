#include<bits/stdc++.h>
using namespace std;

// Better approach using hash map

int element(vector<int>arr){
    map<int,int>mpp;
    int n = arr.size();
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

// Optimal approach using Binary Search
/*  If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
    If arr[0] != arr[1]: This means the very first element of the array is the single element. So, we will return arr[0].
    If arr[n-1] != arr[n-2]: This means the last element of the array is the single element. So, we will return arr[n-1].
    Place the 2 pointers i.e. low and high: Initially, we will place the pointers excluding index 0 and n-1 like this: low will point to index 1, and high will point to index n-2 i.e. the second last index.
    Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
    Check if arr[mid] is the single element:
    If arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the single element. We will return arr[mid].
    If (mid % 2 == 0 and arr[mid] == arr[mid+1])
    or (mid%2 == 1 and arr[mid] == arr[mid-1]): This means we are in the left half and we should eliminate it as our single element appears on the right. So, we will do this:
    low = mid+1.
    Otherwise, we are in the right half and we should eliminate it as our single element appears on the left. So, we will do this: high = mid-1.
*/

int singleElement(vector<int>arr){
    int n = arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    int low = 1 , high = n-2;
    int mid = low + (high-low)/2;
    while(low<=high)
    {
        // check if arr[mid] is the single element.
        if(arr[mid] != arr[mid+1] && arr[mid]!=arr[mid-1])return arr[mid];

        // move in left

        if(mid % 2 ==1 && arr[mid]==arr[mid-1] || mid % 2 == 0 && arr[mid] == arr[mid+1]){
            low = mid +1;
        }
        else{
            high = mid-1;
        }
        mid = low + (high-low)/2;
    }
    return -1;
}

int main()
{
    vector<int>a = {1,1,2,2,3,3,4};
    cout<<singleElement(a)<<endl;
    return 0;
}