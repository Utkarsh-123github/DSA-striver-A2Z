#include<iostream>
#include<vector>
using namespace std;
int secondLargest(vector<int>arr)
{
    int largest = arr[0];
    int sLargest = INT32_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>largest){
            sLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>sLargest){
            sLargest=arr[i];
        }
    }
    return sLargest;
}
int main()
{
    vector<int> a = {8,8,8,8,8,7};
    cout<<"The Second largest element is "<<secondLargest(a)<<endl;
    return 0;
}