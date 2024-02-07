#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>&st , int x)
{
    if(st.empty() || ( !st.empty() && x>st.top()))
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    insertSorted(st , x);
    st.push(num);
}

void sortStack(stack<int>&st)
{
    if(st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();
    
    sortStack(st);
    insertSorted(st,num);
}