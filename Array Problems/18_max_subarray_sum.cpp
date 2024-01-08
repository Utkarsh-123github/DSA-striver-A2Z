#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute approach :- TC ~= O(n^3) SC = O(1)

int maxSum(vector<int>&arr){
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<j;k++){
                sum += arr[k];
            }
            maxi = max(sum,maxi);
        }
    }
    return maxi;
}

// Better Solution :- TC = O(n^2) SC = O(1)

int maxSum_1(vector<int>&arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxi = max(sum,maxi);
        }
    }
    return maxi;
}

// Optimal solution :- Using KADANE's ALGORITHM
/*
The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

Thus we can solve this problem with a single loop.
TC = O(n) SC = O(1)
*/

int maxSum_2(vector<int>&arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    if(maxi < 0){
        maxi = 0;
    }
    return maxi;
}

// If we have to print the subarray then the code is :-

long long maxSubarraySum(vector<int>&arr) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    int n = arr.size();

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]"<<endl;

    if (maxi < 0) maxi = 0;

    return maxi;
}



int main()
{
    vector<int> a={-2,-3,4,-1,-2,1,5,-3};
    cout<<maxSubarraySum(a);
}