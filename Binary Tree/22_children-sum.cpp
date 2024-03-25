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