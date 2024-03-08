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

int Sum(Node* root, int& maxi)
{
    if(root == NULL)return 0;
    int leftSum = Sum(root->left,maxi);
    int rightSum = Sum(root->right,maxi);
    if(leftSum<0)leftSum = 0;
    if(rightSum<0)rightSum = 0;
    maxi = max(maxi,root->data + leftSum + rightSum);
    return root->data + max(leftSum,rightSum);
}

int maxSum(Node* root)
{
    int ans = -10000;
    Sum(root,ans);
    return ans;
}