#include<bits/stdc++.h>
using namespace std;

// Brute approach 

vector<int>nextSmaller(vector<int>arr,int n)
{
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        int currentElement = arr[i];
        int ansElement = -1;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<currentElement)
            {
                ansElement = arr[j];
                break;
            }
        }
        ans.push_back(ansElement);
    }
    return ans;
}

// Stack appproach

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    vector<int>ans(n);
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        int currentElement = arr[i];
        while(st.top()>=currentElement)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(currentElement);
    }
    return ans;
}