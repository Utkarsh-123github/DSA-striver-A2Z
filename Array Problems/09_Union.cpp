#include<iostream>
#include<vector>
#include<set>
using namespace std;
// Brute force approach using set
vector<int> Union(vector<int>arr1,vector<int>arr2){
    vector<int>ans;
    set<int> s;
    for(int i=0;i<arr1.size();i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++){
        s.insert(arr2[i]);
    }
    for(auto it:s){
        ans.push_back(it);
    }
    return ans;
}

// Optimal Approach --> Two pointer approach
// T.C = O(n1+n2)
//S.C = O(n1+n2)

vector<int> union_array(vector<int>a,vector<int>b){
    vector<int>ans;
    int i=0,j=0;
    int n1= a.size();
    int n2 = b.size();
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(ans.size()==0 || ans.back()!=a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(ans.size()==0 || ans.back()!=a[i]){
                ans.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(ans.size()==0 || ans.back()!=b[j]){
                ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    vector<int>a={1,2,2,3,4,5,5,6};
    vector<int>b = {1,2,3,4,7,8,9,10};
    vector<int>ans;
    ans=union_array(a,b);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}