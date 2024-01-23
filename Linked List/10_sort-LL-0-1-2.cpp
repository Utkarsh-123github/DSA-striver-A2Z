#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1)
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

// Brute approach: using vector

Node* sort012(Node* head)
{
    vector<int>arr;
    Node* temp = head;
    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

// Optimal Approach :- In single traversal

Node* Sort012(Node* head)
{
    Node* zerohead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zerohead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;
    if(head == NULL || head->next == NULL)return head;
    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }   
        else if(temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = oneHead->next;
    one->next = twoHead->next;
    return zerohead->next;
}

int main()
{
    vector<int>arr = {1,1,2,1,0,0,2};
    Node* head = convertArr2LL(arr);
    head = Sort012(head);
    PrintLL(head);
    return 0;
}
