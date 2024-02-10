#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    class Node* left;
    class Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

