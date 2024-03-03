#include<bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[] , long long int N, long long int K) {
    
    vector<long long>ans;
    deque<long long>q;
    
    // Process first window
    for(int i=0;i<K;i++)
    {
        if(A[i]<0)
        {
            q.push_back(i);
        }
    }
    
    // Store answer
    if(!q.empty())
    {
        ans.push_back(A[q.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    // Process rest all windows
    for(int i=K;i<N;i++)
    {
        // removal of extra element from the deque to store the next element of next k size window
        if(!q.empty() && i - q.front() >= K)
        {
            q.pop_front();
        }
        
        // Addition of the new index in the window
        if(A[i]<0)
        {
            q.push_back(i);
        }
        
        // Storing answer
        if(!q.empty())
        {
            ans.push_back(A[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
                                                 
 }