#include<bits/stdc++.h>
using namespace std;

// Write a program to reverse a queue

// Better approach using recursion
void reverseQueue(queue<int>q)
{
    if(q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

// Optimal approach using a stack
// TC = O(N)
// SC = O(N)

queue<int> rev (queue<int>q)
{
    stack<int> st;
    while(!q.empty())
    {
        int x = q.front();
        st.push(x);
        q.pop();
    }

    queue<int>ans;
    while(!st.empty())
    {
        int x = st.top();
        ans.push(x);
        st.pop();
    }
    return ans;

}