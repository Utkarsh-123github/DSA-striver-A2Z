#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Brute force approach
vector<int> zeroes(vector<int>&arr,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
    return arr;
}

// Optimal Approach - Two pointer approach

vector<int> zeroEnd(vector<int>arr,int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1){
        return arr;
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}

int main()
{
    vector<int> a = {1,2,3,0,0,4,5,0,8};
    a=zeroEnd(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
}