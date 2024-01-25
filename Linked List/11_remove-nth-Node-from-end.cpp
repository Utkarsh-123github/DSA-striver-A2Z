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

// Brute approach:- TC ~ O(2n) SC = O(1)

Node* removeNthNodeFromEnd(Node* head , int n)
{
    Node* temp = head;
    int count = 0;
    // Counting length of linked list
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    if(count == n)
    {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    temp = head;
    int result = count - n;
    while(temp!=NULL)
    {
        result--;
        if(result == 0)break;
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

// Optimal Approach :- Using slow and fast pointer approach
// TC = O(length of LL) SC = O(1)
Node* RemoveNthNodefromEnd(Node* head , int n)
{
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++)
    {
        fast = fast->next;
    }
    if(fast == NULL)return head->next;
    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main()
{
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    head = RemoveNthNodefromEnd(head,2);
    PrintLL(head);
    return 0;
}