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

vector<int> topView(Node* root)
{
    vector<int>ans;
    queue<pair<Node* , int>>q;
    map<int , int>mp;
    q.push({root , 0});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int vertical = p.second;
        if(mp.find(vertical) == mp.end())
        {
            mp[vertical] = node->data;
        }
        // check left
        if(node->left != NULL)
        {
            q.push({node->left , vertical-1});
        }

        // check right
        if(node->right != NULL)
        {
            q.push({node->right , vertical+1});
        }
    }
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}