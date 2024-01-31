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

// Brute approach :- Using hash Map
Node* startIndex(Node* head)
{
    Node* temp = head;
    map<Node* , int>mpp;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}

// Optimal Approach :- First we'll use slow and fast pointer approach to detect the loop and then we'll perform again some steps to detect loop start
// TC = O(n) SC = O(1)

Node* detectLoop(Node* head)
{
    if(head == NULL || head->next == NULL)return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && slow!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast)return slow;
    }
    return NULL;
}

Node* getStart(Node* head)
{
    Node* loopLink = detectLoop(head);
    if(loopLink == NULL)return NULL;
    Node* slow = head;
    while(slow!=loopLink)
    {
        slow = slow->next;
        loopLink = loopLink->next;
    }
    return slow;
}