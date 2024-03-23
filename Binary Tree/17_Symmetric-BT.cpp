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

// Method 1 :- Do level order traversal from left to right and from right to left and compare them
// If both are same than the matrix is symmetric
// else the matrix is not symmetric

// Method 2 : The recursive approach

// TC = O(n)
// SC = O(n)

bool isSymmetricUtil(Node* root1 , Node* root2)
{
    if(root1 == NULL || root2 == NULL)return true;
    return ((root1->data == root2->data) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left));
}

bool isSymmetric(Node* root)
{
    if(root == NULL)return true;
    return isSymmetricUtil(root->left , root->right);
}