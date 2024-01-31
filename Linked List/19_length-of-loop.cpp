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

// Brute approach :- using hash map

int lengthOfLoop(Node* head)
{
    Node* temp = head;
    map<Node*,int>mpp;
    int timer = 1;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            int value = mpp[temp];
            return timer-value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

// Optimal Approach - Using fast and slow pointer approach

Node* detectLoop(Node* head)
{
    if(head == NULL || head->next == NULL)return NULL;
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL)
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

int countLength(Node* head)
{
    Node* loopLink = detectLoop(head);
    if(loopLink == NULL)return 0;
    Node* temp = loopLink;
    int count = 1;
    while(temp->next != loopLink)
    {
        count++;
        temp = temp->next;
    }
    return count;
}