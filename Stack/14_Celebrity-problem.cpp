#include<bits/stdc++.h>
using namespace std;

// Brute approach
// TC = O(n^2)

int celebrity(vector<vector<int>>&arr , int n)
{
    for(int i=0;i<n;i++)
    {
        int ans = 1;
        for(int j=0;j<n;j++)
        {
            if(i == j || (arr[i][j] == 0 && arr[j][i] == 1))
            {
                continue;
            }
            else{
                ans = 0;
                break;
            }
        }
        if(ans == 1)
        {
            return i;
        }
    }
    return -1;
}

// Optimal Approach
// TC = O(n)
// SC = O(n)

bool knows(vector<vector<int>>&arr,int a, int b)
{
    if(arr[a][b] == 1)return true;
    else return false;
}

int Celebrity(vector<vector<int>>&arr , int n)
{
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }

    while(st.size()>1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(knows(arr,a,b))
        {
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int candidate = st.top();

    // Verifying if the candidate is celebrity or not

    bool rowCheck = false;
    int colcount = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[candidate][i]==0)
        {
            colcount++;
        }
    }
    if(colcount == n)rowCheck = true;

    bool colCheck = false;
    int rowcount = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i][candidate] == 1)
        {
            rowcount++;
        }
    }
    if(rowcount == n-1)colCheck = true;

    if(rowCheck== true && colCheck == true)
    {
        return candidate;
    }
    else return -1;
}