#include<bits/stdc++.h>
using namespace std;
// TC = O(n) SC = O(n) 
string reverseString(string s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        st.push(s[i]);
    }
    string ans;
    while(st.empty()==false)
    {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string s = "Utkarsh";
    s = reverseString(s);
    cout<<s<<endl;
}