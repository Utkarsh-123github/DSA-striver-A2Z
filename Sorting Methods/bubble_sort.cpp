#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int size = arr.size();
    for(int i=size-1;i>=0;i--)
    {
        for(int j = 0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
} 

int main()
{
    vector<int>arr = {6,7,4,3,8,9,1,2};
    bubbleSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// TC = O(n^2)
// SC = O(1)