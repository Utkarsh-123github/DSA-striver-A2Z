#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute force approach -> By generating all the subarrays and finding the correct one.
// TC = O(n^3) SC = O(1)
int longest(int arr[],int n,long long k){
    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += arr[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Brute force approach by just using only two loops
// TC = O(n^2) SC = O(1)

int longest_1(int arr[],int n,long long k){
    int len = 0;
    for(int i=0;i<n;i++){
        long long sum = 0;
        for(int j=i;j<n;j++){
            sum = sum + arr[j];
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}

// Optimal approach :- Shrinking / Trimming approach

int longest_2(int arr[],int n,long long k){
    int left=0 , right =0;
    int maxLen = 0;
    long long sum = arr[0];
    while(right<n){
        while(left <= right && sum>k){
            sum = sum - arr[left];
            left++;
        }
        if(sum==k){
            maxLen = max(maxLen,right-left+1);
        }
        right++;
        if(right<n){
            sum=sum+arr[right];
        }
    }
    return maxLen;
}

int main()
{
    int arr[5] = {2, 3, 5, 1, 9};
    int k = 5;
    cout<< longest_2(arr,5,k);
}