// You are given the 'head' of a singly linked list. Your task is to group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list’s head.

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

// Brute approach : TC = O(2n) SC = O(n)

Node* oddEvenList(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* temp = head;
    vector<int>arr;

    // For placing odd index elements in the vector 
    while(temp!=NULL && temp->next!=NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp)arr.push_back(temp->data);

    // For placing even index elements in the vector
    temp = head->next;
    while(temp!=NULL && temp->next!=NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp)arr.push_back(temp->data);
    temp = head;
    for(int i=0;i<arr.size();i++)
    {
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

// Optimal Approach :- TC = O(n) SC = O(1)

Node* OddEvenList(Node* head)
{
    if(head == NULL || head->next == NULL)return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even!=NULL && even->next!=NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
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


int main()
{
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    head = OddEvenList(head);
    PrintLL(head);
    return 0;
}




