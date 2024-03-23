// For explanation refer :- https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root , int level , vector<int>&ans)
{
    if(root == NULL)return;
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left , level+1 , ans);
    solve(root->right , level+1 , ans);
}

vector<int> leftView(Node* root)
{
    vector<int> ans;
    solve(root , 0 , ans);
    return ans;
}