#include<bits/stdc++.h>
using namespace std;

// Brute approach :- 
// First we'll identify the element which has element as 0
// Now we'll first make that element's row and column element values as -1
// than we'll make all the -1 as 0

// TC = O((n*m)*(n+m)) + O(n*m)
void markRow(vector<vector<int>>&arr,int i,int m)
{
	for(int j=0;j<m;j++)
	{
		if(arr[i][j] != 0)
		{
			arr[i][j] = -1;
		}
	}	
}

void markCol(vector<vector<int>>&arr , int j , int n)
{
	for(int i = 0;i<n;i++)
	{
		if(arr[i][j] != 0)
		{
			arr[i][j] = -1;
		}
	}
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j] == 0)
			{
				markRow(matrix,i,m);
				markCol(matrix,j,n);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j] == -1)
			{
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}

// Better Approach :- 
// TC = O(2*n*m)
// SC = O(n+m)

vector<vector<int>>ZeroMatrix(vector<vector<int>>&matrix , int n, int m)
{
    vector<int>row(n,0);
    vector<int>col(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i]==1 || col[j]==1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}