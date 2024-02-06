#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st;
    for(int i=1;i<=5;i++)
    {
        st.push(i);
    }
    cout<<"Size of stack before printing is "<<st.size()<<endl;
    while(st.empty()==false)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<"Size of stack after printing is "<<st.size()<<endl;

}