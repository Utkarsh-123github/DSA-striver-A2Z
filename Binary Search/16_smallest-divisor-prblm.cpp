/*
Problem statement
You are given an array of integers 'arr' and an integer 'limit'.

Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer's limit.

Note:
Each result of the division is rounded to the nearest integer greater than or equal to that element. For Example, 7/3 = 3.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>arr,int mid,int limit)
{
	int sum = 0;
	for(int i=0;i<arr.size();i++)
	{
		sum += ceil((double)arr[i] / (double)mid);
	}
	if(sum<=limit) return true;
	else return false;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int n = arr.size();
	int mini = INT_MAX;
	int maxi = INT_MIN;
	for(int i=0;i<n;i++)
	{
		mini = min(arr[i],mini);
		maxi = max(maxi,arr[i]);
	}
	int high = maxi;
	int low = mini;
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		if(isPossible(arr,mid,limit))
		{
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return low;
}

int main()
{
    vector<int> arr = {2 ,3, 5, 7, 11};
    int limit = 11;
    cout<<smallestDivisor(arr,limit)<<endl;
    return 0;
}