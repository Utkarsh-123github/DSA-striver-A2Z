#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxOnes(int arr[],int n){
    int maxi = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxi = max(count,maxi);
        }
        else{
            count=0;
        }
    }
    return maxi;
}
int main()
{
    int arr[10]={1,1,0,1,1,1,1,0,1,0};
    cout<<maxOnes(arr,10);
}
