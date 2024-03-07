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

// We'll perform all the traversals in one go using single stack
// TC = O(3n)
// SC = O(4n)

vector<vector<int>> preInPost(Node* root)
{
    vector<vector<int>> ans;
    stack<pair<Node*,int>> st;
    vector<int>pre,post,inOrder;
    if(root == NULL)return ans;
    st.push({root,1});
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        // This is part of preOrder
        // Increment 1 to 2
        // Check for left and if available then push it
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            // check for left if available then push it in the stack
            if(it.first->left !=NULL)
            {
                st.push({it.first->left,1});
            }
        }

        // this is part of Inorder
        // increment 2 to 3
        // Check for right and if available than push it 
        if(it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            // check for right
            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }
        // don't push it again
        else{
            post.push_back(it.first->data);
        }
    }
    ans.push_back(pre);
    ans.push_back(inOrder);
    ans.push_back(post);
    return ans;
}