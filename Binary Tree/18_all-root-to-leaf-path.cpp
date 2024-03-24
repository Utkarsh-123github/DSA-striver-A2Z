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

void helper(Node* root , vector<string>&ans , string prev)
{
    if(root == NULL)return;
    prev += to_string(root->data) + " ";
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(prev);
    }
    helper(root->left , ans , prev);
    helper(root->right , ans, prev);
}

vector<string> allRootToLeaf(Node* root)
{
    vector<string> ans;
    helper(root , ans, "");
    return ans;
}