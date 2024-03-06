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

// Iterative preorder traversal
// TC = O(n)
// SC = O(n)

vector<int> preOrder(Node* root)
{
    vector<int>ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node*>st;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        if(root->right!=NULL)
        {
            st.push(root->right);
        }
        if(root->left!=NULL)
        {
            st.push(root->left);
        }
        ans.push_back(root->data);
    }
    return ans;
}

// Iterative Inorder traversal
// TC = O(n)
// SC = O(n)

vector<int>inOrder(Node* root)
{
    vector<int>ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node*>st;
    Node* node = root;
    while(true)
    {
        if(node!=NULL)
        {
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()==true)break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

// Iterative postorder traversal
// TC = O(n)
// SC = O(2n)
vector<int>postOrder(Node* root)
{
    vector<int>ans;
    stack<Node*>st1,st2;
    if(root == NULL)
    {
        return ans;
    }
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL)
        {
            st1.push(root->left);
        }
        if(root->right!=NULL)
        {
            st1.push(root->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

void printVector(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
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
    vector<int>preorder = preOrder(root);
    printVector(preorder);
    vector<int>inorder = inOrder(root);
    cout<<endl;
    printVector(inorder);
    vector<int>postorder = postOrder(root);
    cout<<endl;
    printVector(postorder);

}