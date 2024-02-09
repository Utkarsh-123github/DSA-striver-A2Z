// In this problem we'll use the concept of next smaller element (last question)
// But instead of pushing values in the stack, this time we'll push the indexes
#include<bits/stdc++.h>
using namespace std;

vector<int>nextSmall(vector<int>&arr, int n)
{
  stack<int>st;
  vector<int>ans(n);
  // This time this stack stores indexes not values
  st.push(-1);
  for(int i=n-1;i>=0;i--)
  {
    int current = arr[i];
    while(st.top()!=-1 && arr[st.top()]>=current)
    {
      st.pop();
    }
    ans[i] = st.top();
    st.push(i);
  }
  return ans;
}

vector<int>prevSmall(vector<int>&arr, int n)
{
  stack<int>st;
  vector<int>ans(n);
  // This time this stack stores indexes not values
  st.push(-1);
  for(int i=0;i<n;i++)
  {
    int current = arr[i];
    while(st.top()!=-1 && arr[st.top()]>=current)
    {
      st.pop();
    }
    ans[i] = st.top();
    st.push(i);
  }
  return ans;
}

int largestRectangle(vector < int > & heights) {
   int n = heights.size();
   vector<int>next(n);
   vector<int>previous(n);
   next = nextSmall(heights,n);
   previous = prevSmall(heights,n);
   int area = -1000;
   for(int i=0;i<n;i++)
   {
     int l = heights[i];
     if(next[i] == -1)
     {
       next[i] = n;
     }
     int b = next[i] - previous[i] - 1;
     int newArea = l*b;
     area = max(area,newArea);
   }
   return area;

}
