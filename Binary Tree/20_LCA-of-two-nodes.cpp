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

// Method -1 
// TC = O(n)
// SC = O(n)

bool helper(TreeNode<int>* root , vector<int>&ans , int x)
{
    if(root == NULL)return false;
    ans.push_back(root->data);
    if(root->data == x)return true;
    if(helper(root->left , ans , x) || helper(root->right , ans , x))return true;
    ans.pop_back();
    return false;
}

vector<int>rootToNodePath(TreeNode<int>*root , int x)
{
    vector<int>ans;
    if(root == NULL)return ans;
    helper(root , ans , x);
    return ans;
}

int intersection(vector<int>a1 , vector<int>a2)
{
    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0;
    int j = 0;
    int ans = -1;
    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            i++;
        }
        else if(a1[i]>a2[j])
        {
            j++;
        }
        else{
            ans = a1[i];
            i++;
            j++;
        }
    }
    return ans;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	vector<int>path1 = rootToNodePath(root , x);
    vector<int>path2 = rootToNodePath(root , y);
    int ans = intersection(path1,path2);
    return ans;
}

// Method -2 
// Using recursion
// TC = O(n) SC = O(n)

TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    //base case
    if (root == NULL || root == p || root == q) {
        return root;
    }
    TreeNode<int>* left = lowestCommonAncestor(root->left, p, q);
    TreeNode<int>* right = lowestCommonAncestor(root->right, p, q);

    //result
    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else { //both left and right are not null, we found our result
        return root;
    }
}

