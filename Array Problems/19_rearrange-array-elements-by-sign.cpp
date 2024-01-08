#include<bits/stdc++.h>
using namespace std;

// Brute approach :- TC = O(n) + O(n)  SC = O(n)

vector<int> rearrange(vector<int>&arr){
    int n = arr.size();
    vector<int>positive;
    vector<int>negative;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }
    for(int i=0;i<n/2;i++){
        arr[2*i] = positive[i];
        arr[2*i + 1] = negative[i];
    }
    return arr;
}

// Optimal Approach :- TC = O(n)  SC = O(n)

vector<int> rearrange_1(vector<int>A){
    int n = A.size();
  
    // Define array for storing the ans separately.
    vector<int> ans(n,0);
    
    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;
    for(int i = 0;i<n;i++){
        
        // Fill negative elements in odd indices and inc by 2.
        if(A[i]<0){
            ans[negIndex] = A[i];
            negIndex+=2;
        }
        
        // Fill positive elements in even indices and inc by 2.
        else{
            ans[posIndex] = A[i];
            posIndex+=2;
        }
    }
  
    return ans;
}

int main()
{
    vector<int> arr = {-2,1,2,-1,-3,3};
    vector<int> ans;
    ans = rearrange_1(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}