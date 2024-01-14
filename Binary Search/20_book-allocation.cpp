#include<bits/stdc++.h>
using namespace std;

// Optimal approach

bool isPossible(vector<int>arr, int pages , int m){
    int studentCount = 1;
    int n = arr.size();
    int pageSum = 0;
    for(int i=0;i<n;i++){
        if(pageSum + arr[i] > pages){
            studentCount++;
            if(studentCount > m || arr[i]>pages){
                return false;
            }
            pageSum = arr[i];
        }
        else{
            pageSum += arr[i];
        }
    }
    return true;
}

int findPages(vector<int>arr,int m)
{
    int n = arr.size();
    if(m>n) return -1;
    int low = 0 , sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    int high = sum;
    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(isPossible(arr,mid,m)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int>arr = {12, 34, 67, 90};
    int student = 2;
    cout<<findPages(arr,student)<<endl;
    return 0;
}