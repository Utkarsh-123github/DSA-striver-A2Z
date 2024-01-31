#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data1 , Node* next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void PrintLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// Brute approach :- Using hash map

bool detectLoop(Node* head)
{
    Node* temp = head;
    map<Node*,int>mpp;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return true;
            break;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// Optimal Approach - using Slow and fast pointer approach
bool detectLoop1(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    if(head == NULL || head->next==NULL)return false;
    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(fast == slow)return true;
    }
    return false;

}