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

// PreOrder traversal
// TC = O(n)
// SC = O(n)

void preOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder traversal
// TC = O(n)
// SC = O(n)

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Post Order traversal
// TC = O(n)
// SC = O(n)

void postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// Level order traversal ( BFS )
// TC = O(n)
// SC = O(n)
vector<vector<int>> levelOrderTraversal(Node* root)
{
    vector<vector<int>>ans;
    if (root == NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

void printArr(vector<vector<int>>&arr){
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"Pre Order traversal : "<<endl;
    preOrder(root);
    cout<<endl<<"Inorder traversal : "<<endl;
    inorder(root);
    cout<<endl<<"Post Order traversal : "<<endl;
    postOrder(root);
    vector<vector<int>>BFS = levelOrderTraversal(root);
    cout<<endl<<"Level order traversal : "<<endl;
    printArr(BFS);
    
}
