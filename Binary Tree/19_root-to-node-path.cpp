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

bool helper(Node* root , vector<int>&ans , int x)
{
    if(root == NULL)return false;
    ans.push_back(root->data);
    if(root->data == x)
    {
        return true;
    }
    if(helper(root->left , ans , x) || helper(root->right , ans , x))return true;
    ans.pop_back();
    return false;
}

vector<int> rootToNodePath(Node* root , int x)
{
    vector<int>ans;
    if(root == NULL)return ans;
    helper(root , ans , x);
    return ans;
}