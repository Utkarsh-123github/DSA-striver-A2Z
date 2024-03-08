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

int height(Node* root , int diameter)
{
    if(root == NULL)return 0;
    int leftHeight = height(root->left,diameter);
    int rightHeight = height(root->right,diameter);
    diameter = max(diameter, leftHeight+rightHeight);
    return 1 + max(leftHeight,rightHeight);
}

int getDiameter(Node* root)
{
    int diameter = 0;
    height(root,diameter);
    return diameter;
}