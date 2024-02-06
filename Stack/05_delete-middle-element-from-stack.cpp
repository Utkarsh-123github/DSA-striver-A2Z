#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int count , int size)
{
    // Base case
    if(count == size/2)
    {
        inputStack.pop();
        return;
    }

    // Storing the top element
    int num = inputStack.top();
    inputStack.pop();

    // Recursive Call
    solve(inputStack,count+1,size);

    // while returning push back the stored elements
    inputStack.push(num);

}

void deleteMiddle(stack<int>&inputStack , int N)
{
    int count = 0;
    solve(inputStack,count,N);
}

int main()
{
    stack<int>st;
    st.push(22);
    st.push(33);
    st.push(11);
    deleteMiddle(st,st.size());
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}