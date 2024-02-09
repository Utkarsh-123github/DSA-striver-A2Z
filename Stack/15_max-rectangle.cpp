#include<bits/stdc++.h>
using namespace std;

// Optimal Approach using largest area in histogram concept
// TC = O(n*m)
// SC = O(m)

vector<int>nextSmallest(vector<int>&arr , int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int current = arr[i];
        while(st.top()!= -1 && arr[st.top()]>=current)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int>prevSmallest(vector<int>&arr , int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        int current = arr[i];
        while(st.top()!= -1 && arr[st.top()]>=current)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleinHistogram(vector<int>&arr , int n)
{
    vector<int>next = nextSmallest(arr,n);
    vector<int>prev = prevSmallest(arr,n);
    int area = -1000;
    for(int i=0;i<n;i++)
    {
        int l = arr[i];
        if(next[i]==-1)
        {
            next[i]=n;
        }
        int b = next[i]-prev[i]-1;
        int newArea = l*b;
        area = max(area,newArea);
    }
    return area;
}

int maxRectangle(vector<vector<int>>&arr , int n, int m)
{
    int area = largestRectangleinHistogram(arr[0],m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] != 0)
            {
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }
            else{
                arr[i][j] = 0;
            }
        }
        area = max(area,largestRectangleinHistogram(arr[i],m));
    }
    return area;
}