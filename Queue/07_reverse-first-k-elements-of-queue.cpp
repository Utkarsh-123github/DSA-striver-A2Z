#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
        stack<int>st;
        queue<int>ans;
        // store first k elements in the stack
        for(int i=0;i<k;i++)
        {
            int x = q.front();
            st.push(x);
            q.pop();
        }
        // Push the stack elements in the answer queue
        while(!st.empty())
        {
            int x = st.top();
            ans.push(x);
            st.pop();
        }
        // From the main queue, push the remaining elements to the answer queue
        while(!q.empty())
        {
            int x = q.front();
            ans.push(x);
            q.pop();
        }
        return ans;
}

// TC = O(n)
// SC = O(k)