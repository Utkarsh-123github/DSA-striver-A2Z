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

Node * deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == k)
        {
            if(temp == head)
            {
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if(nextNode!=NULL)
            {
                nextNode->back = prevNode;
            }
            if(prevNode!=NULL)
            {
                prevNode->next = nextNode;
            }
            delete temp;
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}