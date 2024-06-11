#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&arr) {
    for (int i = 0; i <= arr.size()- 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    vector<int>arr = {6,7,4,3,8,9,1,2};
    insertion_sort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
