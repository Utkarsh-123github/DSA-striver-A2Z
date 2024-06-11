#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr){
    int size = arr.size();
    for(int i=0;i<size-1;i++)
    {
        for(int j = i+1;j<size;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
} 

int main()
{
    vector<int>arr = {6,7,4,3,8,9,1,2};
    selectionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}