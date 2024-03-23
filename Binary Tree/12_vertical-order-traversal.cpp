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

vector<int> VerticalOrderTraversal(Node* root)
{
    vector<int>ans;
    queue<pair<Node* , pair<int , int>>>q;
    // stores{node,{vertical,level}}

    map<int , map<int , multiset<int>>>mp; 
    // stores vertical,level,node->data
    // multiset because it will handle the case where node->data will be same

    q.push({root , {0,0}});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int x = p.second.first; // Vertical
        int y = p.second.second; // Level
        mp[x][y].insert(node->data);
        // check left
        if(node->left!= NULL)
        {
            q.push({node->left,{x-1,y+1}});
        }
        // check right
        if(node->right!= NULL)
        {
            q.push({node->right,{x+1,y+1}});
        }
    }
    for (auto it : mp) {

        vector<int> level;

        for (auto p : it.second) { // iterate for level,node->val;

            level.insert(level.end(), p.second.begin(), p.second.end());
        }

        for (int v : level) {

            ans.push_back(v);
        }
  }

  return ans;
}


// Second type 

vector<int> verticalOrder(Node *root)
{
    vector<int>ans;
    map<int,vector<int>>mp;
    queue<pair<Node* , int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        Node* node = q.front().first;
        int distance = q.front().second;
        q.pop();
        mp[distance].push_back(node->data);
        if(node->left != NULL)
        {
            q.push({node->left,distance-1});
        }
        if(node->right != NULL)
        {
            q.push({node->right , distance+1});
        }
    }
    for(auto it : mp)
    {
        for(int y : it.second)
        {
            ans.push_back(y);
        }
    }
    return ans;
}