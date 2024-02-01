#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
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

Node* getlastNode(Node* head, int k)
{
    Node* temp = head;
    int count = 1;
    while(temp!=NULL)
    {
        if(count == k)return temp;
        count++;
        temp = temp->next;
    }
    return temp;
}

Node* rotateLL(Node* head , int k)
{
    if(head == NULL || k==0)return head;
    Node* tail = head;
    int len = 1;
    while(tail->next!=NULL)
    {
        len++;
        tail = tail->next;
    }
    if(k % len == 0)return head;
    k = k % len;
    Node* newLastNode = getlastNode(head , len-k);
    tail->next = head;
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}

int main()
{
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    head = rotateLL(head,3);
    PrintLL(head);
    return 0;
}