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

// Brute Approach using hashing

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* temp = firstHead;
    map<Node* , int>mpp;
    while(temp!=NULL)
    {
        mpp[temp]=1;
        temp = temp->next;
    }
    temp = secondHead;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!= mpp.end())return temp;
        temp= temp->next;
    }
    return NULL;
}

// Second approach :- Better approach
int length(Node* head)
{
    Node* temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* collisionPoint(Node* temp1 , Node* temp2, int difference)
{
    while(difference)
    {
        difference--;
        temp2 = temp2->next;
    }
    while(temp1!=temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node* findIntersection2(Node *firstHead, Node *secondHead)
{
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    int l1 = length(firstHead);
    int l2 = length(secondHead);
    if(l1<l2)
    {
        return collisionPoint(temp1,temp2,l2-l1);
    }
    else{
        return collisionPoint(temp2,temp1,l1-l2);
    }
}
