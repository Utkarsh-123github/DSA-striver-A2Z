#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Brute force approach using visited array
// T.c = O(n1*n2)
// S.C = O(n2) n2 is the smaller array size
vector<int> intersection_array(vector<int>a,vector<int>b){
    vector<int>ans;
    int n1 = a.size();
    int n2 = b.size();
    vector<int>visited(n2,0);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i]==b[j] && visited[j]==0){
                ans.push_back(a[i]);
                visited[j]=1;
                break;
            }
            if(a[i]<b[j]){
                break;
            }
        }
    }
    return ans;
}

// Optimal Approach - Two pointer approach
// T.C = O(n1+n2) S.C = O(1)

vector<int>Intersection(vector<int>a,vector<int>b){
    vector<int>ans;
    int n1=a.size();
    int n2=b.size();
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<a[i]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> a= {1,2,2,3,4,5,6,6,7};
    vector<int> b= {0,2,3,4,7};
    vector<int>ans;
    ans=Intersection(a,b);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}