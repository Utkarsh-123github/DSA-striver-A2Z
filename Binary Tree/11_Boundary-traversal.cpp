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

// Approach - First we'll traverse left boundary excluding leaf nodes
// than leaf nodes
// than right boundary in reverse order excluding leaf nodes

bool isLeaf(Node* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

void addLeftBoundary(Node* root, vector<int>& ans)
{
    Node* current = root->left;
    while(current)
    {
        if(!isLeaf(current))
        {
            ans.push_back(current->data);
        }
        if(current->left)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}

void addRightBoundary(Node* root , vector<int>& ans)
{
    Node* current = root->right;
    stack<Node*>st;
    while(current)
    {
        if(!isLeaf(current))
        {
            st.push(current);
        }
        if(current->right)
        {
            current = current->right;
        }
        else{
            current = current->left;
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top()->data);
        st.pop();
    }
}

void addLeaves(Node* root, vector<int>& ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
    {
        addLeaves(root->left,ans);
    }
    if(root->right)
    {
        addLeaves(root->right,ans);
    }
}

vector<int> boundaryTraversal(Node* root)
{
    vector<int>ans;
    if(root == NULL)return ans;
    if(!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}