#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&st , int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack,num);
}