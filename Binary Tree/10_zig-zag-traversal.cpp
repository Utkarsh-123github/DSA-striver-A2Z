#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC = O(n)
// SC = O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    if(root == NULL)return ans;
    bool leftToRight = true;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            // determine the index value in which the element is to be pushed
            int index = leftToRight ?  i : (size-1-i);
            level[index] = node->val;

            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        }
        // Now change the insertion side that is from left-right to right-left or vice versa
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}