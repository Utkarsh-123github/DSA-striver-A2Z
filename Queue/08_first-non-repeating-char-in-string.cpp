#include<bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A){
		    unordered_map<char,int>count;
		    queue<char>q;
		    string ans = "";
		    for (int i=0;i<A.length();i++)
		    {
		        count[A[i]]++;
		        q.push(A[i]);
		        
		        while(!q.empty())
		        {
		            // If repeating character than pop
		            if(count[q.front()]>1)
		            {
		                q.pop();
		            }
		            
		            // Non repeating hai to answer me push krdo
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        // Loop se bahar do conditions me aayenge
		        // First - Answer mil gya
		        // Second - Pop krte krte queue empty hogya
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		    }
		    return ans;
}