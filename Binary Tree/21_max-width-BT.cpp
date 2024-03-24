#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// TC = O(n)
// SC = O(n)

vector<vector<int>>levelOrderTraversal(TreeNode<int>* root)
{
    vector<vector<int>>ans;
    if(root == NULL)return ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            TreeNode<int>* node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int getMaxWidth(TreeNode<int> *root)
{
    vector<vector<int>>levelOrder = levelOrderTraversal(root);
    int ans = 0;
    for(auto it : levelOrder)
    {
        if(it.size() > ans)
        {
            ans = it.size();
        }
    }
    return ans;
}