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

bool isLeaf(Node* root)
{
    if(!root->left && !root->right)return true;
    return false;
}

bool isParentSum(Node* root)
{
    if(root == NULL)return true;
    if(isLeaf(root))return true;
    int leftSum = 0;
    int rightSum = 0;
    if(root->left)
    {
        leftSum += root->left->data;
    }
    if(root->right)
    {
        rightSum += root->right->data;
    }
    if(root->data != leftSum + rightSum || !isParentSum(root->left) || !isParentSum(root->right))return false;
    return true;
}