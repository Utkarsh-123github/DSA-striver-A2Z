#include<iostream>
#include<vector>
using namespace std;
vector<int> lrotate(vector<int>&arr)
{
    int temp = arr[0];
    for(int i=1;i<arr.size();i++){
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;
    return arr;
}
int main()
{
    vector<int> a = {1,2,3,4,5,6};
    a = lrotate(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
