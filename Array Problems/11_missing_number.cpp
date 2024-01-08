#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute force approach
// TC = o(n*n)
//SC = O(1)
int missing(int arr[],int n){
    for(int i=1;i<=n;i++){
        int flag = 0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}

// Better approach - Using Hash Array
// TC = O(n)+O(n)
// SC = O(n+1)

int missing_2(int arr[],int N){
    int hash[N+1]={0};
    for(int i=0;i<N-1;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=N;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;

}

// Optimal Approach - Using Sum formula
// TC = O(n) SC = O(1)

int missing_3(int arr[],int N){
    int real_sum = (N*(N+1))/2;
    int sum = 0;
    for(int i=0;i<N-1;i++){
        sum+=arr[i];
    }
    return real_sum-sum;
}

// Optimal Approach - Using XOR

int missing_4(int arr[],int N){
    int XOR1 = 0;
    for(int i=1;i<=N;i++){
        XOR1 = XOR1^i;
    }
    int XOR2 = 0;
    for(int i=0;i<N-1;i++){
        XOR2 = XOR2^arr[i];
    }
    return XOR1^XOR2;
}

int main()
{
    int a[9]={1,2,3,4,5,6,7,8,10};
    cout<<missing_4(a,10);
}