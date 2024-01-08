#include<iostream>
using namespace std;
void reverse (int arr[],int n){
    int i=0,j=n-1;
    while(i<=j){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    reverse(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}