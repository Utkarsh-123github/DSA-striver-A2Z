#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1 , Node* next1 , Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node* convertArr2DLL(vector<int>arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void printDLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// Brute approach
// TC ~= O(n^2) SC = O(1)
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>>ans;
    Node* temp1 = head;
    while(temp1!=NULL)
    {
        Node* temp2 = temp1->next;
        while(temp2!=NULL && temp1->data + temp2->data <=k)
        {
            if(temp1->data + temp2->data == k)
            {
                ans.push_back({temp1->data,temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}

// Optimal Approach
// TC = O(n)
// SC = O(1)

Node* findTail(Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    return temp;
}
vector<pair<int, int>> findPairs1(Node* head, int k)
{
    vector<pair<int,int>>ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data)
    {
        if(left->data + right->data == k)
        {
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < k)
        {
            left = left->next;
        }
        else{
            right = right->back;
        }

    }
    return ans;
}