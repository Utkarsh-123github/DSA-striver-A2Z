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

bool identicalTrees(Node* root1, Node* root2) {
    	 if(root1 == NULL || root2 == NULL)
         {
             return root1 == root2;
         }
         return (root1->data == root2->data && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right,root2->right));
}