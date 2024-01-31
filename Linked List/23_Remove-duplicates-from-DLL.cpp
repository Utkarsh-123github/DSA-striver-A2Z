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

// Optimal Approach :- TC = O(n) SC = O(1)

Node * removeDuplicates(Node *head)
{
    if(head == NULL)return NULL;
    Node* curr = head;
    while(curr!=NULL)
    {
        if((curr->next!=NULL) && curr->data == curr->next->data)
        {
            Node* next_next = curr->next->next;
            Node* delNode = curr->next;
            delete(delNode);
            curr->next = next_next;
            if(next_next!=NULL)next_next->back = curr;
        }
        else{
            curr = curr->next;
        }
    }
    return head;

}